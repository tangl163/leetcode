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
    // This version is referred to below
    // @https://leetcode.com/problems/add-two-numbers/solutions/469977/simple-rust-solution-0ms-2-1mb/
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (None, None) => None,
            (Some(l), None) | (None, Some(l)) => Some(l),
            (Some(l1), Some(l2)) => {
                let sum = l1.val + l2.val;
                if sum < 10 {
                    Some(Box::new(ListNode {
                        val: sum,
                        next: Solution::add_two_numbers(l1.next, l2.next),
                    }))
                } else {
                    Some(Box::new(ListNode {
                        val: sum - 10,
                        next: Solution::add_two_numbers(
                            l1.next,
                            Solution::add_two_numbers(l2.next, Some(Box::new(ListNode::new(1)))),
                        ),
                    }))
                }
            }
        }
    }

    pub fn add_two_numbers_v2(
        mut l1: Option<Box<ListNode>>,
        mut l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut head = &mut dummy;
        let mut carry = 0;

        while l1.is_some() || l2.is_some() || carry != 0 {
            let mut val = carry;

            if let Some(tmp) = l1 {
                val += tmp.val;
                l1 = tmp.next;
            }

            if let Some(tmp) = l2 {
                val += tmp.val;
                l2 = tmp.next;
            }

            carry = val / 10;
            head.next = Some(Box::new(ListNode::new(val % 10)));
            head = head.next.as_mut().unwrap();
        }

        dummy.next
    }

    pub fn add_two_numbers_v3(
        mut l1: Option<Box<ListNode>>,
        mut l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut head = &mut dummy;
        let mut carry = 0;

        while l1.is_some() || l2.is_some() || carry != 0 {
            let val = match l1 {
                Some(l) => {
                    l1 = l.next;
                    l.val
                }
                None => 0,
            } + match l2 {
                Some(l) => {
                    l2 = l.next;
                    l.val
                }
                None => 0,
            } + carry;

            carry = val / 10;
            head.next = Some(Box::new(ListNode::new(val % 10)));
            head = head.next.as_mut().unwrap();
        }

        dummy.next
    }
}
