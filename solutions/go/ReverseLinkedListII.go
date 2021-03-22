/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	first := head
	second := head

	for i := right-left; i > 0; i-- {
		second = second.Next
	}

	var prev *ListNode

	for i := 1; i < left; i++ {
		prev = first
		first = first.Next
		second = second.Next
	}

	next := second.Next

	for i := left; i < right; i++ {
		tmp := first.Next
		first.Next = next
		next = first
		first = tmp
	}

	first.Next = next

	if prev == nil {
		head = first
	} else {
		prev.Next = first
	}

	return head
}
