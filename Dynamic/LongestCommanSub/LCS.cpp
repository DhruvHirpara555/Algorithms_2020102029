#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MAX(int a, int b)
{
    return (a > b) ? a : b;
}



int LCS(string s1, string s2, string &common)
{
    int m = s1.length();
    int n = s2.length();


    int dp[m+1][n+1]; // dp[i][j] = length of LCS of s1[0..i-1] and s2[0..j-1]
    for(int i=0;i<=m;i++){ // initialize the first row and column with 0
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j =1 ; j <= n ; j++) // compute the value of dp[i][j] using the already filled values(element above/element in left/ diagonal)
        {
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=MAX(dp[i-1][j],dp[i][j-1]);
            }
        }

    }
    //using backtracking to find the common string

    int i=m,j=n;

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            common += s1[i-1];
            i--;
            j--;
        }
        else if(MAX(dp[i-1][j],dp[i][j-1]) == dp[i-1][j]){
            i--;
        }
        else{
            j--;
        }
    }
    return dp[m][n];

}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    string common= "";

    cout<<LCS(s1,s2,common) << endl;

    for (int i = 0; i < common.size(); i++)
    {
        cout<<common[common.size() - i -1];
    }

    return 0;
}