/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
	return qsort(head, nil)
}

func qsort(head, tail *ListNode) *ListNode {
	if head == nil || head.Next == nil || head == tail {
		return head
	}

	pivot := partition(head, tail)
	qsort(head, pivot)
	qsort(pivot.Next, tail)

	return head
}

func partition(head, tail *ListNode) *ListNode {
	pivot := head
	tmp := head.Next

	for tmp != nil && tmp != tail {
		if tmp.Val < head.Val {
			pivot = pivot.Next
			tmp.Val, pivot.Val = pivot.Val, tmp.Val
		}
		tmp = tmp.Next
	}

	head.Val, pivot.Val = pivot.Val, head.Val
	return pivot
}

// sortListV2 Another version using merge sort
func sortListV2(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	var tmp *ListNode
	slow, fast := head, head

	for fast != nil && fast.Next != nil {
		tmp = slow
		slow = slow.Next
		fast = fast.Next.Next
	}

	tmp.Next = nil

	l1 := sortListV2(head)
	l2 := sortListV2(slow)

	return mergeList(l1, l2)
}

func mergeList(l1, l2 *ListNode) *ListNode {
	var dummy ListNode
	ptr := &dummy

	for l1 != nil || l2 != nil {
		if l1 != nil && l2 != nil {
			if l1.Val < l2.Val {
				ptr.Next = l1
				l1 = l1.Next
			} else {
				ptr.Next = l2
				l2 = l2.Next
			}
			ptr = ptr.Next
		} else if l1 != nil {
			ptr.Next = l1
			break
		} else {
			ptr.Next = l2
			break
		}
	}

	return dummy.Next
}
