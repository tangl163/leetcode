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
    pub fn sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            return head;
        }

        let (head, mid) = Solution::split_off(head);
        let l1 = Solution::sort_list(head);
        let l2 = Solution::sort_list(mid);

        Solution::merge(l1, l2)
    }

    // split off the list at the middle
    fn split_off(
        mut head: Option<Box<ListNode>>,
    ) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        if head.is_none() {
            return (None, None);
        }

        let mut len = 0;
        let mut tmp = &head;

        while tmp.is_some() {
            tmp = &tmp.as_ref().unwrap().next;
            len += 1;
        }

        let mut mid = len / 2 - 1;
        let mut tmp = &mut head;

        while mid > 0 {
            tmp = &mut tmp.as_mut().unwrap().next;
            mid -= 1;
        }

        (tmp.as_mut().unwrap().next.take(), head)
    }

    fn merge(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (Some(mut l1), Some(mut l2)) => {
                if l1.val < l2.val {
                    let tmp = l1.next.take();
                    l1.next = Solution::merge(tmp, Some(l2));
                    Some(l1)
                } else {
                    let tmp = l2.next.take();
                    l2.next = Solution::merge(Some(l1), tmp);
                    Some(l2)
                }
            }
            (Some(l), None) | (None, Some(l)) => Some(l),
            _ => None,
        }
    }
}
