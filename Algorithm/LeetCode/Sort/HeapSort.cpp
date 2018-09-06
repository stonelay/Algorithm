//
//  HeapSort.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/6.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "HeapSort.hpp"
#include "SortUtils.hpp"

void heapify(int a[], int i, int size) { // 从a[i]向下进行堆调整
    int left_child = 2 * i + 1;         // 左孩子索引
    int right_child = 2 * i + 2;        // 右孩子索引
    int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
    if (left_child < size && a[left_child] > a[max])
        max = left_child;
    if (right_child < size && a[right_child] > a[max])
        max = right_child;
    if (max != i) {
        swap(a, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
        heapify(a, max, size);          // 递归调用，继续从当前结点向下进行堆调整
    }
}

int buildHeap(int a[], int n) {          // 建堆，时间复杂度O(n)
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
        heapify(a, i, heap_size);
    return heap_size;
}

void heapSort(int a[], int n) {
    int heap_size = buildHeap(a, n);    // 建立一个最大堆
    while (heap_size > 1) {             // 堆（无序区）元素个数大于1，未完成排序
        // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
        // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
        swap(a, 0, --heap_size);
        heapify(a, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
    }
}

void displayHeapSort() {
    int a[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// 从小到大堆排序
    int n = sizeof(a) / sizeof(int);
    heapSort(a, n);
    printf("堆排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
