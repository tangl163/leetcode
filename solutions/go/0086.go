// https://leetcode.com/problems/partition-list

package golang

func partition(head *ListNode, x int) *ListNode {
	var result = &ListNode{Next: head}

	var insertNode = result
	for insertNode.Next != nil && insertNode.Next.Val < x {
		insertNode = insertNode.Next
	}

	var curr = insertNode

	for curr.Next != nil {
		if curr.Next.Val < x {
			tmp := curr.Next
			curr.Next = tmp.Next
			tmp.Next = insertNode.Next
			insertNode.Next = tmp
			insertNode = tmp
		} else {
			curr = curr.Next
		}
	}

	return result.Next
}
