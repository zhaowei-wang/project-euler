//
//  problem14_2.h
//  project-euler
//
//  Created by Zhaowei Wang on 8/4/18.
//  Copyright © 2018 Zhaowei Wang. All rights reserved.
//

#ifndef problem14_2_h
#define problem14_2_h

#include <stdio.h>
#include <inttypes.h>

#include "problem.h"

#define ARRAYSIZE 1000000
#define LIMIT 1000000

uint32_t limit = LIMIT;
uint64_t arraysize = ARRAYSIZE;
uint32_t collatzarray[ARRAYSIZE] = {0};


uint64_t collatzstep(uint64_t n) {
    if (n%2 == 0)
        return n/2;
    else
        return 3*n +1;
}


uint32_t collatzcount(uint64_t n, uint32_t* array, uint64_t* arraysize ) {
    uint32_t count = 0;
    if (n <= *arraysize) {
        if (array[n-1] != 0)
            return array[n-1];
        else {
            if (n == 1) {
                array[0] = 1;
                return 1;
            }
            else {
                count = collatzcount(collatzstep(n), array, arraysize) + 1;
                array[n-1] = count;
                return count;
            }
        }
    }
    else {
        count = collatzcount(collatzstep(n), array, arraysize) + 1;
        return count;
    }
}

class problem14_2 : public problem
{
public:
    void run()
    {
        uint32_t maxcount, maxn;
        maxcount = 0;
        
        uint32_t current;
        for (uint32_t i = 1; i <= limit; i++) {
            current = collatzcount(i, collatzarray, &arraysize)-1;
            if (current > maxcount) {
                maxcount = current;
                maxn = i;
            }
        }
        
        printf("Longest Collatz sequence, n < %" PRIu32 " is Collatz(%" PRIu32 ") = %" PRIu32 "\n", limit, maxn, maxcount);
    }
};

#endif /* problem14_2_h */
