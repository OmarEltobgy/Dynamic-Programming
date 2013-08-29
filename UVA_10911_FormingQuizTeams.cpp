#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

int N, place[25][2];
double dp[25][80000], adjMat[25][25];
double solve(int index, int taken)
{
	int i;
	double ans, temp;
	if(taken == (1<<(2*N))-1)
	{
		return 0;
	}
	if(dp[index][taken] != -1)
	{
		return dp[index][taken];
	}
	if((taken & (1<<index)) != 0)
	{
		return solve(index+1, taken);
	}
	ans = 10000000;
	for(i=index+1; i<2*N; i++)
	{
		if((taken & (1<<i)) == 0)
		{
			temp = adjMat[index][i] + solve(index+1, ( taken | (1<<index) | (1<<i) ) );
			ans = min(ans, temp);
		}
	}
	return dp[index][taken] = ans;
}
int main()
{
	int i, j, k, ttt=0;
	double distance;
	string temp;
	while(scanf("%d",&N) != EOF)
	{
		if(N == 0)
		{
			break;
		}
		ttt++;
		for(i=0; i<2*N; i++)
		{
			for(j=0; j<=(1<<(2*N)); j++)
			{
				dp[i][j] = -1;
			}
			cin >> temp >> place[i][0] >> place[i][1];
			adjMat[i][i] = 0;
			for(j=0; j<i; j++)
			{
				distance = sqrt( pow(abs(place[i][0]-place[j][0]), 2) + pow(abs(place[i][1]-place[j][1]), 2) );
				adjMat[i][j] = distance;
				adjMat[j][i] = distance;
			}
		}
		printf("Case %d: %.2lf\n", ttt, solve(0, 0));	
	}
	return 0;
}
