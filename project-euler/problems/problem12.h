//
//  problem12.h
//  project-euler
//
//  Created by Zhaowei Wang on 8/4/18.
//  Copyright © 2018 Zhaowei Wang. All rights reserved.
//

#ifndef problem12_h
#define problem12_h

#import "problem.h"
#include "mathmisc.h"

class problem12 : public problem
{
public:
    void run()
    {
        int N = 1;
        int lim = 500;
        int tri;
        std::vector<int> pf;
        do {
            tri = sum_of_ints(0, N);
            pf = prime_factors(tri);
            N += 1;
        } while(number_of_factors(pf) < lim);
        printf("The largest triangular number with less than %d factors is %d. \
               \n", lim, tri);
    }
};

#endif /* problem12_h */
