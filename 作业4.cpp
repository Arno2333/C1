#include<stdio.h>
#include<stdlib.h>

int Merge(int a[],int head, int mid, int tail)
{
	int j, k, h;
	j = head;
	h = mid + 1;
	k = head;
	int b[1000];
	while (j<=mid&&h<=tail)	
	{
		if (a[j] < a[h])
			b[k++] = a[j++];
		else
			b[k++] = a[h++];
	}

	while (j <= mid)
	{
		b[k++] = a[j++];
	}
	while (h<=tail)
	{
		b[k++] = a[h++];
	}
	for (k = head; k <= tail; k++)
	{
		a[k] = b[k];
	}
}

int MergeSort(int a[],int head,int tail){
	if(head<tail)
	{
		int mid=(head+tail)/2;
		MergeSort(a,head,mid);
		MergeSort(a,mid+1,tail);
		Merge(a,head,mid,tail);
	}
}

int main(){
	int a[10]={3,4,2,6,5,7,8,1,9,10};
	MergeSort(a,0,9);
	for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

