#include <iostream>
#include <vector>
#include"DSU.hpp"




DisjointSU dsu;

typedef struct EDGE
{
    int u;
    int v;
    long long int w;
} Edge;

void swap(Edge *x, Edge *y)
{
    Edge temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void printMST(std::vector<Edge> T) //print the mst
{
    int i;
    long long int cost = 0;

    for (int i = 0; i < T.size(); i++)
    {
        std::cout << T[i].u << " " << T[i].v << " " << T[i].w << std::endl;
        cost += T[i].w;
    }
    printf("%lld", cost);
}

//partition funtion to help quicksort
int Partition(Edge E[],int low, int high)
{
    int pivot = E[high].w;
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (E[j].w < pivot)
        {
            swap(&E[i], &E[j]);
            i++;
        }
    }
    swap(&E[i], &E[high]);
    return i;
}
// quicksort to sort the edges
void QuickSort(Edge E[],int low, int high)
{
    if (low < high)
    {
        int p = Partition(E,low,high);
        QuickSort(E,low,p-1);
        QuickSort(E,p+1,high);
    }

}

void Kruskal(Edge *E, int n, int e)
{
    int  u, v;

    std::vector<Edge> MST;
    QuickSort(E, 0, e - 1); //sort edges in ascending order according to their weights


    for (int i = 0; i < e; i++)
    {

        u = dsu.king(E[i].u); //find the king of the u
        v = dsu.king(E[i].v); //find the king of the v
        if (u != v) // checking if the two vertices are not in same ser
        {

            MST.push_back({E[i].u, E[i].v, E[i].w}); //add the edge to the mst

            dsu.unionbysize(u, v); //union the two set
        }

    }

    printMST(MST);
    return;
}

int main()
{



    int  n, e;
    long long int w;
    Edge *E;
    std :: cin >> n >> e;

    E = (Edge *)malloc(e * sizeof(Edge));
    // making singleton sets for each vertex
    for (int i = 1; i <= n ; i++)
    {
        dsu.makeSet(i);
    }

    for (int k = 0; k < e; k++)
    {
        std::cin >> E[k].u >> E[k].v >> E[k].w;

    }

    Kruskal(E, n, e);
    return 0;
}
