# include<bits/stdc++.h>
#define NUM 100
using namespace std;
int n;  //��װ������
int c1,c2;  //�ִ�������
int cw,r; //��ǰ�ִ���������ʣ�༯װ������
int w[100],bestw,x[100],bestx[100];  //��������,���Ž�
//t��1��ʼ
void BackTrack(int t)
{
    //����Ҷ�ӽڵ�
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
        r-=w[t];    //����ʣ�༯װ������
        if(cw+w[t]<=c1)//û�г������������ж��Ƿ��������
        {
            x[t]=1;
            cw+=w[t];
            BackTrack(t+1);
            cw-=w[t];
        }
        //�ж��Ƿ��������
        if(cw+r>bestw)
        {
            x[t]=0;    
            BackTrack(t+1);
        }
        r+=w[t]; 
        //���۴����Ǵ��ҷ��ض���ԭʣ�༯װ������   
    }
}
int main()
{
    //�������ݣ�
    printf("������AB��������c1��c2:");
    cin>>c1>>c2;
    printf("������Ʒ������:");
    cin>>n;
    printf("����������Ʒ������:");
    for(int i=1; i<=n; i++)//��ʼ����bestw=0
    {
        cin>>w[i];
        r+=w[i];
    }
    //�ݹ����
    BackTrack(1);
    if(r-bestw>c2)//�޽�
        printf("û��װ�ط���\n");
    else//�н�
        for(int i=1; i<=n; i++)
            printf("%d ",bestx[i]);
    return 0;
}






