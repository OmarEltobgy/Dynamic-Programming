#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[110][110], sum[110][110];
int main()
{
	int N, i, j, iStart, jStart, iEnd, jEnd, tempSum ,maxSum;
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			sum[i][j] = 0;
			scanf("%d",&arr[i][j]);
			sum[i][j] += arr[i][j];
			if(i>0) sum[i][j] += sum[i-1][j];
			if(j>0) sum[i][j] += sum[i][j-1];
			if(i>0&&j>0) sum[i][j] -= sum[i-1][j-1];
		}
	}
	maxSum = -100000000;
	for(iStart=0; iStart<N; iStart++)
	{
		for(jStart=0; jStart<N; jStart++)
		{
			for(iEnd=iStart; iEnd<N; iEnd++)
			{
				for(jEnd=jStart; jEnd<N; jEnd++)
				{
					tempSum = sum[iEnd][jEnd];
					if(iStart>0) tempSum -= sum[iStart-1][jEnd];
					if(jStart>0) tempSum -= sum[iEnd][jStart-1];
					if(iStart>0&&jStart>0) tempSum += sum[iStart-1][jStart-1];
					maxSum = max(maxSum, tempSum);
				}
			}
		}
	}
	printf("%d\n", maxSum);
}
