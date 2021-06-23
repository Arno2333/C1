#include<stdio.h>
#include<math.h>
int findx_1(int a[],int n,int x){//顺序查找 
	for(int i=0;i<n;i++){
		if(a[i]==x)
		 return i;
	}
	return 0;
}

int findx_2(int a[],int n,int x){//二分查找 
	int head=1;
	int tail=n;
	int m;
	while(head<=tail){
		m=floor((head+tail)/2.0);
		if(x<a[m])
		 tail-=1;
		else if(x>a[m])
		 head+=1;
		else
		 return m;
	}
	return 0;
}

int main(){
	int a[100],n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	printf("%d\n",findx_2(a,n,x));
}

