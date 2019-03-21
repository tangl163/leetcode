// https://leetcode.com/problems/linked-list-cycle

package golang

func hasCycle(head *ListNode) bool {
	var fast, slow = head, head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if fast == slow {
			return true
		}
	}

	return false
}
