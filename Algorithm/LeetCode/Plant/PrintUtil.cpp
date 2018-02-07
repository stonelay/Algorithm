//
//  PrintUtil.cpp
//  Algorithm
//
//  Created by LayZhang on 2018/2/5.
//  Copyright © 2018年 Zhanglei. All rights reserved.
//

#include "PrintUtil.hpp"
#include <iostream>
using namespace std;

#pragma mark - Print Util
void printVect(vector<string> vec) {
    vector<string>::iterator it;
    for(it = vec.begin();it != vec.end();it++) {
        cout<< *it;
        cout<< " ";
    }
    cout << endl;
}
