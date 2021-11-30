#include <iostream>
#include "DSU.hpp"

//makeset fundtion : makes the set of the node
void DisjointSU::makeSet(int a)
{
    parent[a] = a;
    size[a] = 1;
}

//find function : returns the representative of the set
int DisjointSU::king(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = king(parent[a]);
}

//union function : joins the two sets
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