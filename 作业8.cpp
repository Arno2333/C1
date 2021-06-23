#include<stdio.h>
int PrintDivi(int (*p)[6], int start, int end)
{
	int Divi;
	Divi = p[start][end];
	if(start == end)
		printf("A%d",start+1);
	else
	{
		printf("(");
		PrintDivi(p, start, Divi);
		PrintDivi(p, Divi+1, end);
		printf(")");
	}
}
int main(void)
{
	int l,i,j,k,temp;
	int p[7] = {30,35,15,5,10,20,25};
	int m[6][6],s[6][6];
	for(i=0;i<6;i++)
	{		
		m[i][i] = 0;
	}
	for(l=2;l<=6;l++)
		for(i=0;i<6-l+1;i++)
		{
			j=i+l-1;
			m[i][j] = 0x7fffffff;
			for(k=i;k<j;k++)
			{
				temp = m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(temp<m[i][j])
				{
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	PrintDivi(s, 0, 5);
	return 0;
}
