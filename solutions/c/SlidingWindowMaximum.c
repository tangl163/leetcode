#define DEQUE_MAX_CAP INT_MAX

struct deque_t {
    int front;
    int rear;
    int len;
    int cap;
    int *data;
};

static struct deque_t *newDeque(size_t cap);
static bool empty(struct deque_t *this);
static void pushBack(struct deque_t *this, int val);
static void popBack(struct deque_t *this);
static int back(struct deque_t *this);
static void pushFront(struct deque_t *this, int val);
static void popFront(struct deque_t *this);
static int front(struct deque_t *this);
static void resize(struct deque_t *this);
static void freeDeque(struct deque_t *this);

static struct deque_t *
newDeque(size_t cap)
{
    struct deque_t *p;

    p = malloc(sizeof *p);
    assert(p != NULL);
    p->data = malloc(sizeof *p->data * cap);
    assert(p->data != NULL);

    p->front = -1;
    p->rear = -1;
    p->len = 0;
    p->cap = cap;

    return p;
}

static bool
empty(struct deque_t *this)
{
    return this->len == 0;
}

static void
pushBack(struct deque_t *this, int val)
{
    if (this->cap == this->len) {
        resize(this);
    }

    if (empty(this)) {
        this->front = this->rear = 0;
    } else if (this->rear == this->cap-1) {
        this->rear = 0;
    } else {
        ++this->rear;
    }

    ++this->len;
    this->data[this->rear] = val;
}

static void
popBack(struct deque_t *this)
{
    if (empty(this)) {
        return;
    }

    if (this->rear == 0) {
        this->rear = this->cap - 1;
    } else {
        --this->rear;
    }

    --this->len;
}

static int
back(struct deque_t *this)
{
    return this->data[this->rear];
}

static void
pushFront(struct deque_t *this, int val)
{
    if (this->cap == this->len) {
        resize(this);
    }

    if (empty(this)) {
        this->front = this->rear = 0;
    } else if (this->front == 0) {
        this->front = this->cap - 1;
    } else {
        --this->front;
    }

    ++this->len;
    this->data[this->front] = val;
}

static void
popFront(struct deque_t *this)
{
    if (empty(this)) {
        return;
    }

    if (this->front == this->cap - 1) {
        this->front = 0;
    } else {
        ++this->front;
    }

    --this->len;
}

static int
front(struct deque_t *this)
{
    return this->data[this->front];
}

static void
resize(struct deque_t *this)
{
    int cap = this->cap << 1;
    if (cap > DEQUE_MAX_CAP) {
        fprintf(stderr, "deque overflow in memory");
        exit(-1);
    }

    int *p = malloc(sizeof *this->data * cap);
    assert(p != NULL);

    memcpy(p, this->data + this->front, sizeof *this->data * (this->cap - this->front));
    memcpy(p + this->cap - this->front, this->data, sizeof *this->data * this->front);

    this->front = 0;
    this->rear = this->cap - 1;
    this->cap = cap;
    this->data = p;
}

static void
freeDeque(struct deque_t *this)
{
    free(this->data);
    free(this);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
maxSlidingWindow(int *nums, int len, int k, int *returnSize)
{
    int *ret;
    int i, j;
    struct deque_t *queue;

    j = 0;
    queue = newDeque(k);
    ret = malloc(sizeof *ret * (len - k + 1));
    assert(ret != NULL);

    for (i = 0; i < len; ++i) {
        if (!empty(queue) && front(queue) + k == i) {
            popFront(queue);
        }

        while (!empty(queue) && nums[back(queue)] <= nums[i]) {
            popBack(queue);
        }

        pushBack(queue, i);

        if (i >= k-1) {
            ret[j++] = nums[front(queue)];
        }
    }

    freeDeque(queue);
    *returnSize = len - k + 1;

    return ret;
}

