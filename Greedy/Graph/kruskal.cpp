#include <iostream>
#include <vector>

 class DisjointSU
 {
 private:
     int parent[1000007], size[1000007];
 public:
     void makeSet(int a);
     int king(int a);
     void unionbysize(int a, int b);

 };





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
};



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

void printMST(std::vector<Edge> T)
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
    QuickSort(E, 0, e - 1);

    int j = 0;
    for (int i = 0; i < e; i++)
    {

        u = dsu.king(E[i].u);
        v = dsu.king(E[i].v);
        if (u != v)
        {

            MST.push_back({E[i].u, E[i].v, E[i].w});
            j++;
            dsu.unionbysize(u, v);
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
