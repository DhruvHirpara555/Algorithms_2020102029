#include<iostream>
#include<vector>

#define INF 1000007

typedef struct EDGE
{
    int u;
    int v;
    long long int w;
} Edge;


std::vector<Edge> prims(int** G, int n)
{
    int start = 0;
    // int inMsT[n];
    // int cost =0;
    // vector<Edge> mst;
    // int parent[n];
    // priority_queue<pair<int,int>>, vector<pair<int,int>>, greater<pair<int,int>> pq;
    // pair<int,int> p;
    // pq.push(make_pair(0,start));
    // while (!pq.empty())
    // {
    //     p = pq.top();
    //     pq.pop();
    //     if (inMsT[p.second] == 1)
    //         continue;
    //     inMsT[p.second] = 1;
    //     mst.push_back({parent[p.second],p.second,p.first});

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (G[p.second][i] != INF && inMsT[i] == 0)
    //         {
    //             pq.push(make_pair(G[p.second][i],i));
    //             parent[i] = p.second;
    //         }

    //     }
    // }
    // return mst;



    int distance[n];
    int inMST[n];
    distance[start];
    std::vector<Edge> MST;
    int parent[n] ;
    for(int i = 0; i < n; i++)
    {
        distance[i] = INF;
        inMST[i] = 0;
        parent[i] = -1;
    }

    for (int i =0; i < n; i++)
    {
        int min =0;
        for (int j = 0; j < n; j++)
        {

            if (inMST[j]==0 && distance[min] > distance[j])
            {
                min = j;
            }
        }
        if (distance[min]==-1)
        {
            std::cout << "MST not possible";
            exit(0);
        }
        inMST[min] = 1;

        MST.push_back({min, parent[min], distance[min]});
        for (int j = 0; j < n; j++)
        {
            if (inMST[j] == 0 &&G[min][j] < distance[j])
            {
                distance[j] = G[min][j];
                parent[j] = min;
            }
        }
    }
    return MST;


}


int main()
{
    int n,e;
    std::cin >> n >> e;
    int** G = (int **)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        G[i] = (int *)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j] = INF;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int u,v,w;
        std::cin >> u >> v >> w;
        G[u-1][v-1] = w;
        G[v-1][u-1] = w;
    }

    std::vector<Edge> MST = prims(G, n);

    int cost = 0;

    for (int i = 1; i < n; i++)
    {
        std::cout << MST[i].u +1<< " " << MST[i].v+1 << " " << MST[i].w << std::endl;
        cost += MST[i].w;
    }
    std::cout << cost;

}
