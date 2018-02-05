//
//  LeetCode002.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "LeetCode002.hpp"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry)
        cur->next = new ListNode(1);
    
    return head->next;
}
