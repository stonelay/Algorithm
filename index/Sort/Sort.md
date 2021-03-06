# Sort

## 插入排序 insertionSort
```
最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
平均时间复杂度 ---- O(n^2)
所需辅助空间 ------ O(1)
稳定性 ------------ 稳定
```

## 二分插入排序 binaryInsertionSort
```
最差时间复杂度 ---- O(n^2)
最优时间复杂度 ---- O(nlogn)
平均时间复杂度 ---- O(n^2)
所需辅助空间 ------ O(1)
稳定性 ------------ 稳定
```

## 冒泡排序 bubbleSort
```
最差时间复杂度 ---- O(n^2)
最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
平均时间复杂度 ---- O(n^2)
所需辅助空间 ------ O(1)
稳定性 ----------- 稳定
```

## 归并排序 mergeSort
```
最差时间复杂度 ---- O(nlogn)
最优时间复杂度 ---- O(nlogn)
平均时间复杂度 ---- O(nlogn)
所需辅助空间 ------ O(n)
稳定性 ------------ 稳定
```

## 快速排序 quickSort
```
最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
平均时间复杂度 ---- O(nlogn)
所需辅助空间 ------ 主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)
稳定性 ----------- 不稳定
```

## 选择排序 selectionSort 
```
最差时间复杂度 ---- O(n^2)
最优时间复杂度 ---- O(n^2)
平均时间复杂度 ---- O(n^2)
所需辅助空间 ------ O(1)
稳定性 ------------ 不稳定
```

## 希尔排序 shellSort
```
最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
最优时间复杂度 ---- O(n)
平均时间复杂度 ---- 根据步长序列的不同而不同。
所需辅助空间 ------ O(1)
稳定性 ------------ 不稳定
```

## 堆排序 heapSort
```
分类 -------------- 内部比较排序
数据结构 ---------- 数组
最差时间复杂度 ---- O(nlogn)
最优时间复杂度 ---- O(nlogn)
平均时间复杂度 ---- O(nlogn)
所需辅助空间 ------ O(1)
稳定性 ------------ 不稳定
```

## ps 
堆排序、快速排序、希尔排序、直接选择排序 是 不稳定排序
基数排序、冒泡排序、直接插入排序、折半插入排序、归并排序 是 稳定排序

### 稳定性的意义
1、如果只是简单的进行数字的排序，那么稳定性将毫无意义。
2、如果排序的内容仅仅是一个复杂对象的某一个数字属性，那么稳定性依旧将毫无意义（所谓的交换操作的开销已经算在算法的开销内了，如果嫌弃这种开销，不如换算法好了？）
3、如果要排序的内容是一个复杂对象的多个数字属性，但是其原本的初始顺序毫无意义，那么稳定性依旧将毫无意义。
4、除非要排序的内容是一个复杂对象的多个数字属性，且其原本的初始顺序存在意义，那么我们需要在二次排序的基础上保持原有排序的意义，才需要使用到稳定性的算法，例如要排序的内容是一组原本按照价格高低排序的对象，如今需要按照销量高低排序，使用稳定性算法，可以使得想同销量的对象依旧保持着价格高低的排序展现，只有销量不同的才会重新排序。（当然，如果需求不需要保持初始的排序意义，那么使用稳定性算法依旧将毫无意义）。
