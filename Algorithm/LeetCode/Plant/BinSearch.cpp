//
//  BinSearch.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "BinSearch.hpp"

#include <iostream>
using namespace std;

#pragma mark - BinSearch
void binSearchMain(void) {
    int array[] = {1,3,4,5,6,7,8,9,10};
    int length = sizeof(array)/sizeof(int);
    int index = bsearchWithoutRecursion(array, 0, length, 9);
    cout << index << endl;
}

int bsearchWithoutRecursion(int array[],int low,int high,int target) {
    while(low<=high) {
        int mid=(low+high)/2;
        if(array[mid]>target)
            high=mid-1;
        else if(array[mid]<target)
            low=mid+1;
        else
            return mid;
    }
    return -1;
}

