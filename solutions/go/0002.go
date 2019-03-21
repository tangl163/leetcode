// https://leetcode.com/problems/add-two-numbers

package golang

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var result = new(ListNode)
	var carry, relay, next1, next2 = 0, result, l1, l2

	for next1 != nil && next2 != nil {
		sumVal := next1.Val + next2.Val + carry
		relay.Next = &ListNode{Val: sumVal % 10}
		relay = relay.Next
		carry = sumVal / 10
		next1 = next1.Next
		next2 = next2.Next
	}

	var left *ListNode

	if left = next1; left == nil {
		left = next2
	}

	for left != nil {
		sumVal := left.Val + carry
		relay.Next = &ListNode{Val: sumVal % 10}
		relay = relay.Next
		carry = sumVal / 10
		left = left.Next
	}

	if carry > 0 {
		relay.Next = &ListNode{Val: carry}
	}

	return result.Next
}
