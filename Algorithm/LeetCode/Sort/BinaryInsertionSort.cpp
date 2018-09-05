//
//  BinaryInsertionSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/4.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "BinaryInsertionSort.hpp"

void binaryInsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];                    // 右手抓到一张扑克牌
        int left = 0;                       // 拿在左手上的牌总是排序好的，所以可以用二分法
        int right = i - 1;                  // 手牌左右边界进行初始化
        while (left <= right)  {            // 采用二分法定位新牌的位置
            int mid = (left + right) / 2;
            if (a[mid] > temp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--) {    // 将欲插入新牌位置右边的牌整体向右移动一个单位
            a[j + 1] = a[j];
        }
        a[left] = temp;                    // 将抓到的牌插入手牌
    }
}

void displayBinaryInsertionSort() {
    int a[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// 从小到大二分插入排序
    int n = sizeof(a) / sizeof(int);
    binaryInsertionSort(a, n);
    printf("二分插入排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
