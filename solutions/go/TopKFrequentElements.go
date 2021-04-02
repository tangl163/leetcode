type node struct {
	key, val int
}

type heap struct {
	cap, len int
	data []*node
}

func newHeap(cap int) *heap {
	return &heap{cap: cap, len: 0, data: make([]*node, cap)}
}

func (h *heap) full() bool {
	return h.cap == h.len
}

func (h *heap) swap(i, j int) {
	h.data[i], h.data[j] = h.data[j], h.data[i]
}

func (h *heap) push(p *node) {
	if h.full() {
		if (p.val > h.data[0].val) {
			h.data[0] = p
			h.siftDown(0)
		}
	} else {
		h.data[h.len] = p
		h.bubbleUp(h.len);
		h.len++
	}
}

func (h *heap) siftDown(i int) {
	min := i
	left, right := 2*i+1, 2*i+2

	if left < h.len && h.data[min].val > h.data[left].val {
		min = left
	}

	if right < h.len && h.data[min].val > h.data[right].val {
		min = right
	}

	if (min != i) {
		h.swap(min, i);
		h.siftDown(min);
	}
}

func (h *heap) bubbleUp(i int) {
	parent := (i - 1) / 2

	for parent >= 0 && h.data[parent].val > h.data[i].val {
		h.swap(parent, i)
		i = parent
		parent = (i - 1) / 2
	}
}

func topKFrequent(nums []int, k int) []int {
	heap := newHeap(k)
	dict := make(map[int]int)

	for _, v := range nums {
		dict[v]++
	}

	for key, val := range dict {
		heap.push(&node{key: key, val: val})
	}

	ret := make([]int, k)

	for i := 0; i < heap.len; i++ {
		ret[i] = heap.data[i].key
	}

	return ret
}
