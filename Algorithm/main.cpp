//
//  main.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/1/29.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printVect(vector<int> vec);

void binSearch(void);

vector<int> getNext(string p);

int main(int argc, const char * argv[]) {
    
    vector<int> vec = getNext("ABCDABDE");
    printVect(vec);
    
    return 0;
}

#pragma mark - KMP
vector<int> getNext(string p) {
    int n = (int)p.size(), k = -1, j = 0;
    vector<int> next(n, -1);
    while (j < n - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++k; ++j;
            next[j] = k;
        } else {
            k = next[k]; // 归-1
        }
        printVect(next);
        cout << k << " " << j << endl;
    }
    return next;
}


#pragma mark - BinSearch
int bsearchWithoutRecursion(int array[],int low,int high,int target);

void binSearch(void) {
    int array[] = {1,3,4,5,6,7,8,9,10};
    int length = sizeof(array)/sizeof(int);
    int index = bsearchWithoutRecursion(array, 0, length, 9);
    cout << index << endl;
}

int bsearchWithoutRecursion(int array[],int low,int high,int target) {
    while(low<=high) {
        int mid=(low+high)/2;
        if(array[mid]>target)
            high=mid-1;
        else if(array[mid]<target)
            low=mid+1;
        else
            return mid;
    }
    return -1;
}

#pragma mark - Print Util
void printVect(vector<int> vec) {
    vector<int>::iterator it;
    for(it = vec.begin();it != vec.end();it++) {
        cout<< *it;
        cout<< " ";
    }
    cout << endl;
}


