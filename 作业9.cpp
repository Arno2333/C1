//3.1LCS
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
string s[100][100];
int main()
{
    string a, b;
    cin >> a >> b;
    dp[0][0] = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
        {

            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                s[i + 1][j + 1] = s[i][j] + a[i];
            }
            else
            {
                if (dp[i + 1][j] > dp[i + 1][j])
                {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                    s[i + 1][j + 1] = s[i+1][j] ;
                }
                else 
                {
                     dp[i + 1][j + 1] = dp[i][j+1];
                    s[i + 1][j + 1] = s[i][j+1]  ;
                }
            }
        }
        cout<<dp[a.size()][b.size()]<<endl;
        cout<<s[a.size()][b.size()];
}


//3.2±³°üÎÊÌâ
#include <iostream>
#include <cstring>
using namespace std;
const int N=15;
int main()
{
    int v[N]={0,8,10,6,3,7,2};
    int w[N]={0,4,6,2,2,5,1};
 
 
    int m[N][N];
    int n=6,c=12;
    memset(m,0,sizeof(m));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(j>=w[i])
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
 
 
            else
                m[i][j]=m[i-1][j];
        }
    }
 
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<m[i][j]<<' ';
        }
        cout<<endl;
    }
 
 
    return 0;
}
