//
//  InsertionSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/4.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "InsertionSort.hpp"

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {       // 类似抓扑克牌排序
        int temp = a[i];                // 右手抓到一张扑克牌
        int j = i - 1;                  // 拿在左手上的牌总是排序好的
        while (j >= 0 && a[j] > temp) { // 将抓到的牌与手牌从右向左进行比较
            a[j + 1] = a[j];            // 如果该手牌比抓到的牌大，就将其右移
            j--;
        }
        a[j + 1] = temp;                // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
    }
}

void displayInsertionSort() {
    int a[] = { 6, 5, 3, 1, 8, 7, 2, 4 };// 从小到大插入排序
    int n = sizeof(a) / sizeof(int);
    insertionSort(a, n);
    printf("插入排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
