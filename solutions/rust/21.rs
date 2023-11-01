// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (Some(mut l1), Some(mut l2)) => {
                if l1.val < l2.val {
                    let tmp = l1.next.take();
                    l1.next = Solution::merge_two_lists(tmp, Some(l2));
                    Some(l1)
                } else {
                    let tmp = l2.next.take();
                    l2.next = Solution::merge_two_lists(Some(l1), tmp);
                    Some(l2)
                }
            }
            (Some(l), None) | (None, Some(l)) => Some(l),
            _ => None,
        }
    }
}
