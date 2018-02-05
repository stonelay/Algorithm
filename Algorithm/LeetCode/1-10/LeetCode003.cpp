//
//  LeetCode003.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "LeetCode003.hpp"

int lengthOfLongestSubstring(string s) {
    int m[256] = {0}, maxLength = 0, left = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (m[s[i]] == 0 || m[s[i]] < left) {
            maxLength = max(maxLength, i - left + 1);
        } else {
            left = m[s[i]];
        }
        m[s[i]] = i + 1;
    }

    return maxLength;
}

