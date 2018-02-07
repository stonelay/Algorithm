//
//  LeetCode006.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/6.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "LeetCode006.hpp"


string convert(string s, int numRows) {
    int nSize = numRows == 1 ? numRows : numRows * 2 - 2;
    string r = "";
    string tRows[numRows];
    for (int i = 0 ; i < s.size(); i++) {
        int tRow = i % nSize;
        int row = tRow > (numRows - 1) ? numRows - tRow % (numRows - 1) - 1 : tRow;
        tRows[row] += s[i];
    }
    for (int j = 0; j < numRows; j++) {
        r += tRows[j];
    }
    return r;
}
