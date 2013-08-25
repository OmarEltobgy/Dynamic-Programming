#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int N, hoursN, array[12][110], dp[12][110];
int solve(int index, int hoursRemaining)
{
	int k, temp, max=-10000000;
	if(index == N)
	{
		return 0;
	}
	if(dp[index][hoursRemaining] != -1)
	{
		return dp[index][hoursRemaining];
	}
	for(k=1; k<=hoursRemaining && k<=hoursN; k++)
	{
		if(array[index][k] >= 5)
		{
			temp = array[index][k] + solve(index+1, hoursRemaining-k);
			if(temp > max)
			{
				max = temp;
			}
		}
	}
	return dp[index][hoursRemaining] = max;
}
int main()
{
	int testsN, i, result, j;
	double toPrint;
	scanf("%d",&testsN);
	while(testsN--)
	{
		scanf("%d %d",&N,&hoursN);
		memset(dp, -1, sizeof(dp));
		for(i=0; i<N; i++)
		{
			dp[i][0] = -1;
			for(j=1; j<=hoursN; j++)
			{
				scanf("%d",&array[i][j]);
				dp[i][j] = -1;
			}
		}
		result = solve(0, hoursN);
		toPrint = (1e-9 + result) / N;
		if(toPrint < 5)
		{
			printf("Peter, you shouldn't have played billiard that much.\n");
		}
		else
		{	
			printf("Maximal possible average mark - %.2lf.\n", toPrint);
		}
	}
	return 0;
}
