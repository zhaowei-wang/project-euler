//
//  mathmisc.h
//  project-euler
//
//  Created by Zhaowei Wang on 8/4/18.
//  Copyright © 2018 Zhaowei Wang. All rights reserved.
//

#ifndef mathmisc_h
#define mathmisc_h

#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <vector>

// A function to print all prime factors of a given number n
std::vector<int> prime_factors(int n)
{
    std::vector<int> out;
    if (n == 0) return out;
    
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        out.push_back(2);
        n = n/2;
    }
    
    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            out.push_back(i);
            n = n/i;
        }
    }
    
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        out.push_back(n);
    }
    
    return out;
}

int sum_of_ints_from_one(int n)
{
    return n * (n+1) / 2;
}

int sum_of_ints(int n, int m)
{
    return sum_of_ints_from_one(m) - sum_of_ints_from_one(n);
}

int number_of_factors(std::vector<int> pf)
{
    std::unordered_map<int, int> d;
    for (auto k : pf)
    {
        if (d.find(k) != d.end())
        {
            d[k] = d[k] + 1;
        }
        else
        {
            d[k] = 1;
        }
    }
    
    int num_factors = 1;
    for (auto it : d)
    {
        num_factors *= it.second + 1;
    }
    
    return num_factors;
}

template<typename T>
void print(const T& cont) {
    for (auto const& x : cont) {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

u_long nchoosek(u_long n, u_long k)
{
    u_long ret = 1;
    for (u_long i = 1; i <= k; ++i) {
        ret *= (n + 1 - i);
        ret /= i;
    }
    return ret;
}

#endif /* mathmisc_h */
