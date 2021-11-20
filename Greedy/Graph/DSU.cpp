#include <iostream>
#include "DSU.hpp"

void DisjointSU::makeSet(int a)
{
    parent[a] = a;
    size[a] = 1;
}
int DisjointSU::king(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = king(parent[a]);
}
void DisjointSU::unionbysize(int a, int b)
{
    a = king(a);
    b = king(b);
    if (a == b)
        return;
    if (size[a] < size[b])
    {
        parent[a] = b;
        size[b] += size[a];
    }
    else
    {
        parent[b] = a;
        size[a] += size[b];
    }
}