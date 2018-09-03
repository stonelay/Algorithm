//
//  SortUtils.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/3.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "SortUtils.hpp"

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
