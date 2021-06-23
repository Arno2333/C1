#include<iostream>
#include<vector>
#include<cmath>
#include<time.h>
#include<cstring>
#include<algorithm>
 
using namespace std;

int n, m; // n������Ŀ������ , m����Ͷ�ʵĽ��
int f[1000][1000]; // �û��洢����i����ĿͶ��x��Ԫ���ܹ����f[i][x]��Ԫ������
int dp[1000][1000] = {0}; // dp[i][j]��ʾ����i����Ŀ��ʱ���Ѿ�������j��Ԫ���������

int main()
{    
    scanf("%d %d", &n, &m); 
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            scanf("%d", &f[i][j]); // �Ե�i����ĿͶ��j��Ԫ������Ϊf[i][j]
    
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; j + k <= m; ++k)
                dp[i][j + k] = max(dp[i - 1][j] + f[i][k], dp[i][j + k]);
    cout << dp[n][m] << endl;
    system("pause");
    return 0;
} 
