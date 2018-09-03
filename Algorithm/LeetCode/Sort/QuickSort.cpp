//
//  QuickSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/3.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "QuickSort.hpp"
#include "SortUtils.hpp"

int partition(int a[], int left, int right) { // 划分函数
    int pivot = a[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left;                    // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++) {// 遍历基准以外的其他元素
        if (a[i] <= pivot)  {           // 把小于等于基准的元素放到前一个子数组末尾
            swap(a, tail, i);
            tail++;
        }
    }
    swap(a, tail, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
    // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail;                    // 返回基准的索引
}

void quickSort(int a[], int left, int right) {
    if (left >= right)
        return;
    int pivotIndex = partition(a, left, right); // 基准的索引
    quickSort(a, left, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, right);
}

void displayQuickSort() {
    int a[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 }; // 从小到大快速排序
    int n = sizeof(a) / sizeof(int);
    quickSort(a, 0, n - 1);
    printf("快速排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
