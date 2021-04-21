/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define INIT_CAP 64

#define MAP_DATA_OFFSET(p, offset) ((unsigned int *)p + offset)

struct bucket_t {
    int key;
    int val;
    unsigned int next;
};

struct map_t {
    unsigned int len;
    unsigned int cap;
    unsigned int mask;
    struct bucket_t *data;
};

static struct map_t *newMap(unsigned int cap);
static void insert(struct map_t *map, int key, int val);
static struct bucket_t *find(struct map_t *map, int key);
static void resize(struct map_t *map);
static void freeMap(struct map_t *map);

static struct map_t *
newMap(unsigned int cap)
{
    struct map_t *map;

    /* align cap with the lowest power of 2 */
    --cap;
    cap |= cap >> 1;
    cap |= cap >> 2;
    cap |= cap >> 4;
    cap |= cap >> 8;
    cap |= cap >> 16;
    ++cap;

    map = calloc(1, sizeof *map);
    assert(map != NULL);

    map->len = 0;
    map->cap = cap;
    map->mask = -cap;

    struct bucket_t *data = malloc(cap * sizeof(struct bucket_t) + sizeof(unsigned int) * cap);
    assert(data != NULL);

    memset(data, -1, sizeof(unsigned int) * cap);
    map->data = MAP_DATA_OFFSET(data, cap);

    return map;
}

static void
insert(struct map_t *map, int key, int val)
{
    resize(map);

    struct bucket_t *p = map->data + map->len;
    p->key = key;
    p->val = val;

    unsigned int idx = key | map->mask;
    p->next = ((unsigned int *)map->data)[(int)idx];
    ((unsigned int *)map->data)[(int)idx] = map->len++;
}

static struct bucket_t *
find(struct map_t *map, int key)
{
    if (map->len == 0) {
        return NULL;
    }

    struct bucket_t *p = NULL;
    unsigned int hash = map->mask | key;
    unsigned int idx = ((unsigned int *)map->data)[(int)(hash)];

    while (idx != -1) {
        p = map->data + idx;
        if (p->key == key) {
            return p;
        }

        idx = p->next;
    }

    return NULL;
}

static void
freeMap(struct map_t *map)
{
    assert(map != NULL);

    free((unsigned int *)map->data - map->cap);
    free(map);
}

static void
resize(struct map_t *map)
{
    if (map->len < map->cap) {
        return;
    }

    unsigned int cap = map->cap >> 1;
    size_t size = cap * sizeof(struct bucket_t) + sizeof(unsigned int) * cap;
    void *addr = malloc(size);
    assert(addr != NULL);

    void *oldBucket = map->data;
    void *oldAddr = (unsigned int *)oldBucket - map->cap;
    memset(addr, -1, sizeof(unsigned int) * cap);
    map->cap = cap;
    map->mask = -cap;
    map->data = MAP_DATA_OFFSET(addr, cap);
    memcpy(map->data, oldBucket, sizeof(struct bucket_t) * map->len);
    free(oldAddr);

    struct bucket_t *p = map->data;

    for (unsigned int i = 0; i < map->len; ++i) {
        unsigned int idx = p->key | map->mask;
        p->next = ((unsigned int *)map->data)[(int)idx];
        ((unsigned int *)map->data)[(int)idx] = i;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
twoSum(int *nums, int len, int target, int *returnSize)
{
    int i, j;
    struct bucket_t *p;
    struct map_t *map = newMap(INIT_CAP);

    for (i = 0; i < len; i++) {
        p = find(map, target - nums[i]);
        if (p != NULL) {
            j = p->val;
            break;
        }

        insert(map, nums[i], i);
    }

    freeMap(map);

    int *ret = malloc(sizeof *ret * 2);

    ret[0] = i;
    ret[1] = j;
    *returnSize = 2;

    return ret;
}

