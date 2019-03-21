// https://leetcode.com/problems/remove-nth-node-from-end-of-list

package golang

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	var result = &ListNode{Next: head}
	var fast, slow = result, result

	for i := 0; i <= n; i++ {
		fast = fast.Next
	}

	for fast != nil {
		slow = slow.Next
		fast = fast.Next
	}

	slow.Next = slow.Next.Next

	return result.Next
}
