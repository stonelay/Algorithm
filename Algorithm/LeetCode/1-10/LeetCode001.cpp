//
//  LeetCode001.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/7.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "LeetCode001.hpp"

vector<int> practice(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.count(target - nums[i])) {
            return {i, m[target - nums[i]]};
        }
        m[nums[i]] = i;
    }
    return {};
}
