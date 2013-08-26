#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int itemN, price[1010], weight[1010], peopleN, max2[110], dp[1010][35];
int solve(int item, int remW)
{
	int i, take=0, leave=0;
	if(remW == 0)
	{
		return 0;
	}
	if(item == itemN)
	{
		return 0;
	}
	if(dp[item][remW] != -1)
	{
		return dp[item][remW];
	}
	if(remW >= weight[item])
	{
		take = price[item] + solve(item+1, remW-weight[item]);
	}
	leave = solve(item+1, remW);
	return dp[item][remW] = max(take, leave);
}
int main()
{
	int testN, i, j, result;
	scanf("%d",&testN);
	while(testN--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d",&itemN);
		for(i=0; i<itemN; i++)
		{
			scanf("%d %d",&price[i],&weight[i]);
		}
		scanf("%d",&peopleN);
		for(i=0; i<peopleN; i++)
		{
			scanf("%d",&max2[i]);
		}
		result = 0;
		for(i=0; i<peopleN; i++)
		{
			result += solve(0, max2[i]);
		}
		printf("%lld\n", result);
	}
	return 0;
}
