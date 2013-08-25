#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[1010][100][100], cylinders[1010][3], cylindersN, oxygenN, nitrogenN;
int solve(int index, int oxygen, int nitrogen)
{
	int take=0, leave=0, t1, t2;
	if(oxygen >= oxygenN && nitrogen >= nitrogenN)
	{
		return 0;
	}
	if(index == cylindersN)
	{
		if(oxygen >= oxygenN && nitrogen >= nitrogenN)
		{
			return 0;
		}
		else
		{
			return 1000000;
		}
	}
	if(dp[index][oxygen][nitrogen] != -1)
	{
		return dp[index][oxygen][nitrogen];
	}
	t1 = oxygen+cylinders[index][0];
	t2 = nitrogen+cylinders[index][1];
	if(t1 > oxygenN)
	{
		t1 = oxygenN;
	}
	if(t2 > nitrogenN)
	{
		t2 = nitrogenN;
	}
	take = cylinders[index][2] + solve(index+1, t1, t2);
	leave = solve(index+1, oxygen, nitrogen);
	return dp[index][oxygen][nitrogen] = min(take, leave);
}
int main()
{
	int testN, i, j, k;
	scanf("%d",&testN);
	while(testN--)
	{
		scanf("%d %d",&oxygenN,&nitrogenN);
		scanf("%d",&cylindersN);
		for(i=0; i<cylindersN; i++)
		{
			scanf("%d %d %d",&cylinders[i][0],&cylinders[i][1],&cylinders[i][2]);
			for(j=0; j<=oxygenN; j++)
			{
				for(k=0; k<=nitrogenN; k++)
				{
					dp[i][j][k] = -1;
				}
			}
		}
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}
