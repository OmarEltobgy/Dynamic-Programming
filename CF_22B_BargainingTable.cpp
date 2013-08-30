#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, graph[30][30], count2[30][30];

int main()
{
	int i, j, testN, iStart, jStart, iEnd, jEnd, tempSum, nnn, tempPer, maxPer;
	char temp;
	memset(count2, 0, sizeof(count2));
	scanf("%d %d",&N,&M);
	getchar();
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			scanf("%c",&temp);
			graph[i][j] = temp-'0';
			count2[i][j] += graph[i][j];
			if(i>0) count2[i][j] += count2[i-1][j];
			if(j>0) count2[i][j] += count2[i][j-1];
			if(i>0&&j>0) count2[i][j] -= count2[i-1][j-1];
		}
		getchar();
	}
	maxPer = 0;
	for(iStart=0; iStart<N; iStart++)
	{
		for(jStart=0; jStart<M; jStart++)
		{
			for(iEnd=iStart; iEnd<N; iEnd++)
			{
				for(jEnd=jStart; jEnd<M; jEnd++)
				{
					nnn = (iEnd-iStart+1) * (jEnd-jStart+1);
					tempSum = count2[iEnd][jEnd];
					if(iStart>0) tempSum -= count2[iStart-1][jEnd];
					if(jStart>0) tempSum -= count2[iEnd][jStart-1];
					if(iStart>0&&jStart>0) tempSum += count2[iStart-1][jStart-1];
					if(tempSum == 0)
					{
						tempPer = ((iEnd-iStart+1) + (jEnd-jStart+1)) * 2;
						maxPer = max(maxPer, tempPer);
					}
				}
			}
		}
	}
	printf("%d\n", maxPer);
}
