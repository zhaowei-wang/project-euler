//
//  problem14.h
//  project-euler
//
//  Created by Zhaowei Wang on 8/4/18.
//  Copyright © 2018 Zhaowei Wang. All rights reserved.
//

#ifndef problem14_h
#define problem14_h

#import "problem.h"
#import "mathmisc.h"

// stores <Collatz starting number, length of Collatz Sequence>
typedef std::unordered_map<u_long, u_long> cache;

void collatz_internal(u_long n, u_long *len, cache *cache)
{
    if (n == 1) return;
    
    u_long c = (n % 2 == 0) ? n/2 : 3*n+1;
    if (cache && cache->find(c) != cache->end())
    {
        (*len) += (*cache)[c];
        return;
    }
    
    (*len) += 1;
    collatz_internal(c, len, cache);
}

u_long collatz(u_long n, cache *cache)
{
    u_long len = 1;
    collatz_internal(n, &len, cache);
    return len;
}

class problem14 : public problem
{
public:
    void run()
    {
        u_long N = 1;
        u_long lim = 10000000;
        u_long max_N = 0;
        u_long max_seq_length = 0;
        cache cache;
        while (N < lim)
        {
            u_long seq_len = collatz(N, &cache);
            cache[N] = seq_len;
            if (seq_len > max_seq_length)
            {
                max_seq_length = seq_len;
                max_N = N;
            }
            
            N += 1;
        }
        
        printf("The longest sequence under N=%ld is %ld starting at %ld.\n", \
                lim, max_seq_length, max_N);
        
//        for (auto it : cache)
//        {
//            printf("%ld = %ld\n", it.first, it.second);
//        }
    }
};

#endif /* problem14_h */
