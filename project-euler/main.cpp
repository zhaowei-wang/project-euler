//
//  main.cpp
//  project-euler
//
//  Created by Zhaowei Wang on 8/4/18.
//  Copyright © 2018 Zhaowei Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

#include "problem12.h"

int main(int argc, const char * argv[]) {
    clock_t t;
    problem *p = new problem12();
    t = clock();
    p->run();
    t = clock() - t;
    printf ("Total time = %f seconds.\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}
