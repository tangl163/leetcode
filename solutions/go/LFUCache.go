package main

import "time"

type node struct {
	lastAccessTime      time.Time
	key, val, freq, idx int
}

func newNode(key, val int) *node {
	return &node{
		key:            key,
		val:            val,
		freq:           1,
		lastAccessTime: time.Now(),
	}
}

func (this *node) inc() {
	this.freq++
	this.lastAccessTime = time.Now()
}

func (this *node) less(p *node) bool {
	if this.freq == p.freq {
		return this.lastAccessTime.Before(p.lastAccessTime)
	}

	return this.freq < p.freq
}

type heap struct {
	cap, len int
	data     []*node
}

func (this *heap) swap(i, j int) {
	this.data[i].idx, this.data[j].idx = j, i
	this.data[i], this.data[j] = this.data[j], this.data[i]
}

func (this *heap) bubbleUp(i int) {
	parent := (i - 1) / 2

	for parent >= 0 && this.data[i].less(this.data[parent]) {
		this.swap(parent, i)
		i = parent
		parent = (i - 1) / 2
	}
}

func (this *heap) siftDown(i int) {
	min := i
	left, right := 2*i+1, 2*i+2

	if left < this.len && this.data[left].less(this.data[min]) {
		min = left
	}

	if right < this.len && this.data[right].less(this.data[min]) {
		min = right
	}

	if i != min {
		this.swap(i, min)
		this.siftDown(min)
	}
}

func (this *heap) pushBack(p *node) {
	p.idx = this.len
	this.data[this.len] = p
	this.bubbleUp(p.idx)
	this.len++
}

func (this *heap) replace(p *node, idx int) {
	p.idx = idx
	this.data[idx] = p
	this.siftDown(idx)
}

func (this *heap) full() bool {
	return this.len == this.cap
}

type LFUCache struct {
	dict map[int]*node
	*heap
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		dict: make(map[int]*node),
		heap: &heap{
			cap:  capacity,
			len:  0,
			data: make([]*node, capacity),
		},
	}
}

func (this *LFUCache) Get(key int) int {
	if this.heap.cap == 0 {
		return -1
	}

	node, ok := this.dict[key]
	if !ok {
		return -1
	}

	node.inc()
	this.heap.siftDown(node.idx)

	return node.val
}

func (this *LFUCache) Put(key int, value int) {
	if this.heap.cap == 0 {
		return
	}

	node, ok := this.dict[key]
	if !ok {
		node = newNode(key, value)
		if this.full() {
			evict := this.heap.data[0]
			delete(this.dict, evict.key)
			this.replace(node, 0)
		} else {
			this.pushBack(node)
		}

		this.dict[key] = node
	} else {
		node.val = value
		node.inc()
		this.siftDown(node.idx)
	}
}

/**
* Your LFUCache object will be instantiated and called as such:
* obj := Constructor(capacity);
* param_1 := obj.Get(key);
* obj.Put(key,value);
 */
