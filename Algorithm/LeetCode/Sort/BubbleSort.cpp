//
//  BubbleSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/3.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "BubbleSort.hpp"
#include "SortUtils.hpp"

void bubbleSort(int a[], int n) {
    for (int j = 0; j < n - 1; j++) {         // 每次最大元素就像气泡一样"浮"到数组的最后
        for (int i = 0; i < n - 1 - j; i++) { // 依次比较相邻的两个元素,使较大的那个向后移
            if (a[i] > a[i + 1]) {            // 如果条件改成a[i] >= a[i + 1],则变为不稳定的排序算法
                swap(a, i, i + 1);
            }
        }
    }
}

void displayBubbleSort() {
    int a[] = { 6, 5, 3, 1, 8, 7, 2, 4 };    // 从小到大冒泡排序
    int n = sizeof(a) / sizeof(int);
    bubbleSort(a, n);
    printf("冒泡排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
