//
//  MergeSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/4.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "MergeSort.hpp"

#include <stdlib.h>
#include <string.h>

void merge(int a[], int left, int mid, int right) { // 合并两个已排好序的数组a[left...mid]和a[mid+1...right]
    int len = right - left + 1;
    int *temp = (int *)malloc(sizeof(int) * len);
    memset(temp, 0, sizeof(int) * len);
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right) {
        temp[index++] = a[i] <= a[j] ? a[i++] : a[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid) {
        temp[index++] = a[i++];
    }
    while (j <= right) {
        temp[index++] = a[j++];
    }
    for (int k = 0; k < len; k++) {
        a[left++] = temp[k];
    }
    free(temp);
}

void mergeSortRecursion(int a[], int left, int right) {   // 递归实现的归并排序(自顶向下)
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    mergeSortRecursion(a, left, mid);
    mergeSortRecursion(a, mid + 1, right);
    merge(a, left, mid, right);
}

void mergeSortIteration(int a[], int len) {     // 非递归(迭代)实现的归并排序(自底向上)
    int left, mid, right;                       // 子数组索引,前一个为a[left...mid]，后一个子数组为a[mid+1...right]
    for (int i = 1; i < len; i *= 2) {          // 子数组的大小i初始为1，每轮翻倍
        left = 0;
        while (left + i < len) {                // 后一个子数组存在(需要归并)
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
            merge(a, left, mid, right);
            left = right + 1;                   // 前一个子数组索引向后移动
        }
    }
}

void displayMergeSort() {
    int a1[] = { 6, 5, 3, 1, 8, 7, 2, 4 };      // 从小到大归并排序
    int a2[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int n1 = sizeof(a1) / sizeof(int);
    int n2 = sizeof(a2) / sizeof(int);
    mergeSortRecursion(a1, 0, n1 - 1);          // 递归实现
    mergeSortIteration(a2, n2);                 // 非递归实现
    printf("递归实现的归并排序结果：");
    for (int i = 0; i < n1; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");
    printf("非递归实现的归并排序结果：");
    for (int i = 0; i < n2; i++) {
        printf("%d ", a2[i]);
    }
    printf("\n");
}
