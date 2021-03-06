#include<iostream>
#include<vector>

#define INF 1000007
using namespace std;

void DFS(int **Graph, int N, int *visited, int &time, int* dep_time, int v) // sorting the vertices in topological order
{
    visited[v] = 1;


    for(int i=0; i<N; i++)
    {
        if(Graph[v][i]!= INF && !visited[i])
        {
            DFS(Graph, N, visited, time, dep_time, i);
        }
    }


    dep_time[time] = v; // storing the vertices in  reverse topological order
    time++;
}


void ShorthesPathInDAG(int** Graph, int source, int n)
{
    int dep_time[n];
    int visited[n];
    int parent[n];
    for (int i = 0; i < n; i++) //initializing required arrays,
    {
        dep_time[i] = 0; // for sorting the vertices in topological order
        visited[i] = 0; // for sorting the vertices in topological order
        parent[i] = i; // for finding the shortest path
    }
    int t =0;

    for (int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            DFS(Graph,n,visited,t,dep_time,i);
        }
    }

    int cost[n];
    for (int i = 0; i < n; i++)
    {
        cost[i] = INF;
    }

    cost[source] = 0;

    for (int i = n-1; i >=0; i--) //iterating in linearized order
    {
        int u = dep_time[i];
        for(int j=0; j<n; j++)
        {
            if((cost[u] != INF) &&  (cost[u] + Graph[u][j] < cost[j])) // if the cost of the path from u to j is less than the current cost of j
            {
                cost[j] = cost[u] + Graph[u][j]; // // updating the cost of the path from u to j
                parent[j] = u; // storing the parent of j
            }
        }
    }

    // printing the shortest path using backtracking(parent array)
    for (int i = 0; i < n; i++)
    {
        cout<<"Shortest path from "<<source<<" to "<<i<<" is "<<cost[i]<<" and the path is ";
        int k = i;

        while(k != parent[k])
        {
            cout<<k<<" ";
            k = parent[k];
        }
        cout<<endl;

    }


}


int main()
{
    int n, m, source;
    cin>>n>>m >> source;
    int **graph = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        graph[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = INF;
        }

    }


    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u][v] = w;
    }

    ShorthesPathInDAG(graph, source, n);
    return 0;
}