#include<iostream>
using namespace std;


unsigned int power(int base, int exp, int mod)
{
    int ans = 1;
    while(exp)
    {
        if(exp & 1)
            ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return ans;
}

bool miller_rabin(int n, int k)
{
    if(n<2){
        return false;
    }
    if(n==2){
        return true;
    }
    if(n%2==0){
        return false;
    }

    int s=0;
    int d=n-1;
    while(d%2==0){
        d/=2;
        s++;
    }

    for (int i = 0; i < k; i++)
    {
        int a = rand()%(n-4)+2;
        int x = power(a,d,n);
        if(x==1 || x==n-1){
            continue;
        }
        for (int j = 0; j < s-1; j++)
        {
            x = power(x,2,n);
            if(x==1){
                return false;
            }
            if(x==n-1){
                break;
            }
        }
        if(x!=n-1){
            return false;
        }
    }
    return true;
}


int main()
{
    int k= 5;

    cout << "prime no.s in 1 to 100" << endl;
    for (int i = 1; i <= 100; i++)
    {
        if(miller_rabin(i,k)){
            cout << i << " ";
        }
    }
}
