// https://leetcode.com/problems/merge-two-sorted-lists

package golang

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var result = new(ListNode)
	var relay, next1, next2 = result, l1, l2

	for next1 != nil && next2 != nil {
		if next1.Val > next2.Val {
			relay.Next = &ListNode{Val: next2.Val}
			next2 = next2.Next
		} else {
			relay.Next = &ListNode{Val: next1.Val}
			next1 = next1.Next
		}
		relay = relay.Next
	}

	if next1 != nil {
		relay.Next = next1
	} else if next2 != nil {
		relay.Next = next2
	}

	return result.Next
}

func mergeTwoLists_v2(l1 *ListNode, l2 *ListNode) *ListNode {
	var dummy ListNode
	cur := &dummy

	for l1 != nil || l2 != nil {
		if l1 != nil && l2 != nil {
			if l1.Val < l2.Val {
				cur.Next = l1
				l1 = l1.Next
			} else {
				cur.Next = l2
				l2 = l2.Next
			}
			cur = cur.Next
		} else if l1 != nil {
			cur.Next = l1
			break
		} else {
			cur.Next = l2
			break
		}
	}

	return dummy.Next
}
