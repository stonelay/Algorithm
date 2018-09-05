//
//  SelectionSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/4.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "SelectionSort.hpp"
#include "SortUtils.hpp"

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {         // i为已排序序列的末尾
        int min = i;
        for (int j = i + 1; j < n; j++) {     // 未排序序列
            if (a[j] < a[min]) {              // 找出未排序序列中的最小值
                min = j;
            }
        }
        if (min != i) {
            swap(a, min, i);    // 放到已排序序列的末尾，该操作很有可能把稳定性打乱，所以选择排序是不稳定的排序算法
        }
    }
}

void displaySelectionSort() {
    int a[] = { 8, 5, 2, 6, 9, 3, 1, 4, 0, 7 }; // 从小到大选择排序
    int n = sizeof(a) / sizeof(int);
    selectionSort(a, n);
    printf("选择排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
