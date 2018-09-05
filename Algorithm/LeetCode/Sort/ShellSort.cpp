//
//  ShellSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/4.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "ShellSort.hpp"

void shellSort(int a[], int n) {
    int step = 3;
    int h = 0;
    while (h <= n) {                          // 生成初始增量
        h = step * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            int j = i - h;
            int get = a[i];
            while (j >= 0 && a[j] > get) {
                a[j + h] = a[j];
                j = j - h;
            }
            a[j + h] = get;
        }
        h = (h - 1) / step;                    // 递减增量
    }
}

void displayShellSort() {
    int a[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// 从小到大希尔排序
    int n = sizeof(a) / sizeof(int);
    shellSort(a, n);
    printf("希尔排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
