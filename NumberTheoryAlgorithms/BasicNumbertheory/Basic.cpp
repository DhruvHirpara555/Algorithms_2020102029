#include<iostream>

long long int binpow(long long int a, long long int b, long long int m)
{
    long long int ans = 1;
    while(b)
    {
        if(b&1)
            ans = (ans*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return ans;
}


int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int extendedgcd(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extendedgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}