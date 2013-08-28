#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N, graph[30][30], count2[30][30];

int main()
{
	int i, j, testN, iStart, jStart, iEnd, jEnd, tempSum, maxSum, nnn;
	char temp;
	scanf("%d",&testN);
	getchar();
	while(testN--)
	{
		memset(count2, 0, sizeof(count2));
		i=0;
		j=0;
		getchar();
		scanf("%c",&temp);
		while(temp != '\n')
		{
			graph[i][j] = temp-'0';
			count2[i][j] += graph[i][j];
			if(i>0) count2[i][j] += count2[i-1][j];
			if(j>0) count2[i][j] += count2[i][j-1];
			if(i>0&&j>0) count2[i][j] -= count2[i-1][j-1];
			j++;
			scanf("%c",&temp);
		}
		N = j;
		for(i=1; i<N; i++)
		{
			for(j=0; j<N; j++)
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
		/*for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				printf("%d", count[i][j]);
			}
			printf("\n");
		}*/
		maxSum = 0;
		for(iStart=0; iStart<N; iStart++)
		{
			for(jStart=0; jStart<N; jStart++)
			{
				for(iEnd=iStart; iEnd<N; iEnd++)
				{
					for(jEnd=jStart; jEnd<N; jEnd++)
					{
						nnn = (iEnd-iStart+1) * (jEnd-jStart+1);
						tempSum = count2[iEnd][jEnd];
						if(iStart>0) tempSum -= count2[iStart-1][jEnd];
						if(jStart>0) tempSum -= count2[iEnd][jStart-1];
						if(iStart>0&&jStart>0) tempSum += count2[iStart-1][jStart-1];
						if(tempSum == nnn)
						{
							maxSum = max(maxSum, tempSum);
						}
					}
				}
			}
		}
		printf("%d\n", maxSum);
		if(testN != 0)
		{
			printf("\n");
		}
	}
}
