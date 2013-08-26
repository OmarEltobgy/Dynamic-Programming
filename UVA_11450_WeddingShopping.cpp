#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int garmentN, garment[50][50], modelN[50], dp[50][300];
int solve(int index, int remMoney)
{
	int mmm, temp, k;
	if(index == garmentN)
	{
		return 0;
	}
	if(dp[index][remMoney] != -1)
	{
		return dp[index][remMoney];
	}
	mmm = -1000000;
	for(k=0; k<modelN[index]; k++)
	{
		if(garment[index][k] <= remMoney)
		{
			temp = garment[index][k] + solve(index+1, remMoney-garment[index][k]);
			if(temp > mmm)
			{
				mmm = temp;
			}
		}
	}
	return dp[index][remMoney] = mmm;
}
int main()
{
	int testN, i, money, j, temp;
	scanf("%d",&testN);
	while(testN--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d %d",&money,&garmentN);
		for(i=0; i<garmentN; i++)
		{
			scanf("%d",&modelN[i]);
			for(j=0; j<modelN[i]; j++)
			{
				scanf("%d",&garment[i][j]);
			}
		}
		temp = solve(0, money);
		if(temp > 0)
		{
			printf("%d\n", temp);
		}
		else
		{
			printf("no solution\n");
		}
	}
	return 0;
}
