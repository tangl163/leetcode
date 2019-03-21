// https://leetcode.com/problems/linked-list-cycle-ii

package golang

func detectCycle(head *ListNode) *ListNode {
	var result *ListNode
	var fast, slow = head, head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if fast == slow {
			fast = head
			for fast != slow {
				fast = fast.Next
				slow = slow.Next
			}
			result = fast
			break
		}
	}

	return result
}
