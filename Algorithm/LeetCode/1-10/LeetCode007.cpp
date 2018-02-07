//
//  LeetCode007.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/6.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "LeetCode007.hpp"

int reverse(int x) {
    int r = 0;
    while (x != 0) {
        int t = r * 10 + x % 10;
        if (t / 10 != r) // 若答案溢出 返回0
            return 0;
        r = t;
        x /= 10;
    }
    return r;
}
