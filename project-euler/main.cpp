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

#include "problem14_2.h"

int main(int argc, const char * argv[]) {
    problem *p = new problem14_2();
    
    clock_t t = clock();
    p->run();
    t = clock() - t;
    
    printf ("\nTotal time = %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    return 0;
}
