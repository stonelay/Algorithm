//
//  KMP.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "KMP.hpp"
#include <vector>
#include <iostream>
#include "PrintUtil.hpp"

using namespace std;

int KMPSearch(char* s, char* p);

#pragma mark - KMP
void KMPMain(void) {
    int r = KMPSearch("AABBCDEDFEESSWW", "EDFEESS");
    printf("%d", r);
}

vector<int> getNext(string p) {
    int n = (int)p.size(), k = -1, j = 0;
    vector<int> next(n, -1);
    while (j < n - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++k; ++j;
            //            next[j] = k;
            if (p[j] != p[k])
                next[j] = k;
            else
                next[j] = next[k];
        } else {
            k = next[k]; // 归-1
        }
        printVect(next);
        cout << k << " " << j << endl;
    }
    return next;
}

int KMPSearch(char* s, char* p) {
    int i = 0;
    int j = 0;
    vector<int> next = getNext(p);
    int sLen = (int)strlen(s);
    int pLen = (int)strlen(p);
    while (i < sLen && j < pLen) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}
