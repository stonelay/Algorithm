//
//  LeetCode002.hpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#ifndef LeetCode002_hpp
#define LeetCode002_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

#endif /* LeetCode002_hpp */
