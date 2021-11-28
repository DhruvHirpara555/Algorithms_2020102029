#include <iostream>

using namespace std;
#define INF 1000007;

int MIN(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd_w(int **graph, int n)
{
    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dp[j][k] = MIN(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
        cout << "DP nmatrix at" << i << ": " << endl;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << dp[j][k] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    cout << "Shortest path matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n,k;
    cin >> n;
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = INF;
            if (i == j)
            {
                graph[i][j] = 0;
            }

        }
    }

    cin >> k ;
    for(int i=0;i<k;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v] = w;

    }

    floyd_w(graph, n);

    return 0;
}