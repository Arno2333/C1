//Prim
#include<stdio.h>
#define ed 1000
int main()
{
int dianshu,bianshu,i,j,k,min,a,b,c,count=0,sum=0;
int er[10][10],dis[10],book[10]={0};
scanf("%d%d",&dianshu,&bianshu);
for(i=1;i<=dianshu;i++)
for(j=1;j<=dianshu;j++)
{
if(i==j)
er[i][j]=0;
else
er[i][j]=ed;
}
for(i=1;i<=bianshu;i++)
{
scanf("%d%d%d",&a,&b,&c);
er[a][b]=c;
er[b][a]=c;
}

//Kruskal
#include<stdio.h>
struct edge
{
int u;
int v;
int w;
};
struct edge e[1000];
int n,m;
int f[1000]={0},sum=0,count=0;
void quicksort(int l,int r)
{
int i,j;
struct edge t;
if(l>r)
return;
i=l;
j=r;
while(i!=j)
{
while(e[j].w>=e[l].w&&i<j)
j¨C;
while(e[i].w<=e[l].w&&i<j)
i++;
if(i<j)
{
t=e[i];
e[i]=e[j];
e[j]=t;
}
}
t=e[l];
e[l]=e[i];
e[i]=t;
quicksort(l,i-1);
quicksort(i+1,r);
return;
}
int getf(int v)
{
if(f[v]v)
return v;
else
{
f[v]=getf(f[v]);
return f[v];
}
}
int blending(int v,int u)
{
int t,p;
t=getf(v);
p=getf(u);
if(t!=p)
{
f[p]=t;
return 1;
}
return 0;
}
int main()
{
int i;
scanf("%d %d",&n,&m);
for(i=1;i<=m;i++)
scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
quicksort(1,m);
for(i=1;i<=n;i++)
f[i]=i;
for(i=1;i<=m;i++)
{
if(blending(e[i].u,e[i].v))
{
count++;
sum+=e[i].w;
}
if(countn-1)
break;
}
printf("%d\n",sum);
return 0;
}


