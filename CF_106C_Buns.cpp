#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int doughN, stuffN, reachNo, doughNo, reach[15], dough[15], rem[15], need[15], dp[1010][15][110];
int solve(int doughRem, int stuffType, int remStuff)
{
	long long take=0, leave=0;
	if(doughRem == 0)
	{
		return 0;
	}
	if(stuffType == stuffN+1)
	{
		return 0;
	}
	if(dp[doughRem][stuffType][remStuff] != -1)
	{
		return dp[doughRem][stuffType][remStuff];
	}
	if(doughRem >= dough[stuffType] && remStuff >= need[stuffType])
	{
		take = reach[stuffType] + solve(doughRem-dough[stuffType], stuffType, remStuff-need[stuffType]);
	}
	leave = solve(doughRem, stuffType+1, rem[stuffType+1]);
	return dp[doughRem][stuffType][remStuff] = max(take, leave);
}
int main()
{
	int i;
	long long result;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d %d",&doughN,&stuffN,&doughNo,&reachNo);
	for(i=0; i<stuffN; i++)
	{
		scanf("%d %d %d %d",&rem[i],&need[i],&dough[i],&reach[i]);
	}
	dough[stuffN] = doughNo;
	reach[stuffN] = reachNo;
	rem[stuffN] = 100;
	need[stuffN] = 0;
	result = solve(doughN, 0, rem[0]);
	cout << result << endl;
	return 0;
}
