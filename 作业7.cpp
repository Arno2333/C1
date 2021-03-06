#include<iostream>
#include<vector>
#include<cmath>
#include<time.h>
#include<cstring>
#include<algorithm>
 
using namespace std;

int n, m; // n代表项目的数量 , m代表投资的金额
int f[1000][1000]; // 用户存储给第i个项目投资x万元，能够获得f[i][x]万元的收益
int dp[1000][1000] = {0}; // dp[i][j]表示到第i个项目的时候已经花费了j万元的最大收益

int main()
{    
    scanf("%d %d", &n, &m); 
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            scanf("%d", &f[i][j]); // 对第i个项目投资j万元的收益为f[i][j]
    
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; j + k <= m; ++k)
                dp[i][j + k] = max(dp[i - 1][j] + f[i][k], dp[i][j + k]);
    cout << dp[n][m] << endl;
    system("pause");
    return 0;
} 
