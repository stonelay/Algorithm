//
//  SortPractice.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/9/3.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "SortPractice.hpp"

#include "QuickSort.hpp"
#include "BubbleSort.hpp"
#include "BinaryInsertionSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "ShellSort.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"

void displaySort() {
    displayQuickSort();
    displayBubbleSort();
    displayBinaryInsertionSort();
    displayInsertionSort();
    displaySelectionSort();
    displayShellSort();
    displayMergeSort();
    displayHeapSort();
}
