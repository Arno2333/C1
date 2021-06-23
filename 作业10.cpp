# include<bits/stdc++.h>
#define NUM 100
using namespace std;
int n;  //集装箱数量
int c1,c2;  //轮船载重量
int cw,r; //当前轮船载重量、剩余集装箱重量
int w[100],bestw,x[100],bestx[100];  //最优载重,最优解
//t从1开始
void BackTrack(int t)
{
    //到达叶子节点
    if(t>n)
    {
        if(cw>bestw)
        {
            for(int i=1; i<=n; i++)
            {
                bestx[i]=x[i];
            }
            bestw=cw;
            return;
        }
    }
    else
    {
        r-=w[t];    //更新剩余集装箱重量
        if(cw+w[t]<=c1)//没有超出载重量，判断是否可以向左
        {
            x[t]=1;
            cw+=w[t];
            BackTrack(t+1);
            cw-=w[t];
        }
        //判断是否可以向右
        if(cw+r>bestw)
        {
            x[t]=0;    
            BackTrack(t+1);
        }
        r+=w[t]; 
        //无论从左还是从右返回都还原剩余集装箱重量   
    }
}
int main()
{
    //读入数据；
    printf("请输入AB船的容量c1、c2:");
    cin>>c1>>c2;
    printf("输入物品的数量:");
    cin>>n;
    printf("依次输入物品的质量:");
    for(int i=1; i<=n; i++)//初始化，bestw=0
    {
        cin>>w[i];
        r+=w[i];
    }
    //递归回溯
    BackTrack(1);
    if(r-bestw>c2)//无解
        printf("没有装载方案\n");
    else//有解
        for(int i=1; i<=n; i++)
            printf("%d ",bestx[i]);
    return 0;
}






