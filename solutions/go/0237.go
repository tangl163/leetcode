// https://leetcode.com/problems/delete-node-in-a-linked-list

package golang

func deleteNode(node *ListNode) {
	*node = *node.Next
}
