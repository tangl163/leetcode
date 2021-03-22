/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	first := head
	second := head

	for i := 0; i < k; i++ {
		second = second.Next
		if second == nil {
			k %= i + 1
			i = -1
			second = head
		}
	}

	if k == 0 {
		return head
	}

	for second.Next != nil {
		first = first.Next
		second = second.Next
	}

	tmp := first.Next
	first.Next = nil
	second.Next = head

	return tmp
}
