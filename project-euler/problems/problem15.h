//
//  problem15.h
//  project-euler
//
//  Created by Zhaowei Wang on 8/4/18.
//  Copyright © 2018 Zhaowei Wang. All rights reserved.
//

#ifndef problem15_h
#define problem15_h

#include "problem.h"
#include "mathmisc.h"

class problem15 : public problem
{
public:
    void run()
    {
        u_long n = 20;
        printf("grid size=%ld, paths=%ld\n", n, nchoosek(2*n, n));
    }
};

#endif /* problem15_h */
