//
//  main.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/1/29.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "BinSearch.hpp"
#include "KMP.hpp"
#include "PrintUtil.hpp"
#include "LeetCode093.hpp"
#include <unordered_map>

using namespace std;

int helper(vector<int>& nums, int sum, int start, vector<unordered_map<int, int>>& dp) {
    if (start == nums.size()) return sum == 0;
    if (dp[start].count(sum)) return dp[start][sum];
    int cnt1 = helper(nums, sum - nums[start], start + 1, dp);
    int cnt2 = helper(nums, sum + nums[start], start + 1, dp);
    return dp[start][sum] = cnt1 + cnt2;
}

//int findTargetSumWays(vector<int>& nums, int S) {
//    vector<unordered_map<int, int>> dp(nums.size());
//    return helper(nums, S, 0, dp);
//}

int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n + 1);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (auto &a : dp[i]) {
            int sum = a.first, cnt = a.second;
            dp[i + 1][sum + nums[i]] += cnt;
            dp[i + 1][sum - nums[i]] += cnt;
        }
    }
    return dp[n][S];
}

int main(int argc, const char * argv[]) {
    
//    int d = reverse(2147483647);
    
//    printf("%d\n", d);
//    printf("%d\n", INT_MAX);
//    printVect(restoreIpAddresses("1111111"));
    vector<int> num;
    num.resize(5, 1);
    printf("%d\n", findTargetSumWays(num, 3));
    
    return 0;
}


