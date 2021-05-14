import "math"

type Deque struct {
	cap   int
	len   int
	rear  int
	front int
	data  []int
}

func NewDeque(cap int) *Deque {
	return &Deque{
		cap:   cap,
		len:   0,
		rear:  -1,
		front: -1,
		data:  make([]int, cap),
	}
}

func (this *Deque) Empty() bool {
	return this.len == 0
}

func (this *Deque) PushFront(val int) {
	if this.Empty() {
		this.rear, this.front = 0, 0
	} else if this.front == 0 {
		this.front = this.cap - 1
	} else {
		this.front--
	}

	this.len++
	this.data[this.front] = val
}

func (this *Deque) PopFront() {
	if this.Empty() {
		return
	}

	if this.front == this.rear {
		this.front, this.rear = -1, -1
	} else if this.front == this.cap-1 {
		this.front = 0
	} else {
		this.front++
	}

	this.len--
}

func (this *Deque) Front() int {
	if this.Empty() {
		panic("could not front on an empty deque")
	}

	return this.data[this.front]
}

func (this *Deque) PushBack(val int) {
	if this.len == this.cap {
		this.resize()
	}

	if this.Empty() {
		this.rear, this.front = 0, 0
	} else if this.rear == this.cap-1 {
		this.rear = 0
	} else {
		this.rear++
	}

	this.len++
	this.data[this.rear] = val
}

func (this *Deque) PopBack() {
	if this.Empty() {
		return
	}

	if this.rear == this.front {
		this.rear, this.front = -1, -1
	} else if this.rear == 0 {
		this.rear = this.cap - 1
	} else {
		this.rear--
	}

	this.len--
}

func (this *Deque) Back() int {
	if this.Empty() {
		panic("could not back on an empty deque")
	}

	return this.data[this.rear]
}

func (this *Deque) resize() {
	newCap := this.cap << 1
	if newCap > math.MaxInt32 {
		panic("deque memory overflow")
	}

	data := make([]int, newCap)

	copy(data, this.data[this.front:this.cap])
	copy(data[this.cap-this.front:], this.data[:this.front])

	this.rear = this.cap - 1
	this.front = 0
	this.cap = newCap
	this.data = data
}

func maxSlidingWindow(nums []int, k int) []int {
	var idx int
	queue := NewDeque(k)
	ret := make([]int, len(nums)-k+1)

	for i := 0; i < len(nums); i++ {
		if !queue.Empty() && queue.Front()+k == i {
			queue.PopFront()
		}

		for !queue.Empty() && nums[i] >= nums[queue.Back()] {
			queue.PopBack()
		}

		queue.PushBack(i)

		if i >= k-1 {
			ret[idx] = nums[queue.Front()]
			idx++
		}
	}

	return ret
}
