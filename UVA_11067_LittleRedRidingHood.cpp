#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

int width, height;
long long dp[110][110];
bool isWolf[110][110];
long long solve(int x, int y)
{
	long long ways = 0;
	if(x == width && y == height)
	{
		return 1;
	}
	if(dp[x][y] != -1)
	{
		return dp[x][y];
	}
	if(x+1 <= width && isWolf[x+1][y] == false)
	{
		ways += solve(x+1, y);
	}
	if(y+1 <= height && isWolf[x][y+1] == false)
	{
		ways += solve(x, y+1);
	}
	return dp[x][y] = ways;
}
int main()
{
	int i, n, a, b;
	long long temp;
	scanf("%d %d",&width,&height);
	while(width != 0 && height != 0)
	{
		memset(isWolf, false, sizeof(isWolf));
		memset(dp, -1, sizeof(dp));
		scanf("%d",&n);
		for(i=0; i<n; i++)
		{
			scanf("%d %d",&a,&b);
			isWolf[a][b] = true;
		}
		temp = solve(0, 0);
		if(temp == 0)
		{
			printf("There is no path.\n");
		}
		else if(temp == 1)
		{
			printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
		}
		else
		{
			printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n", temp);
		}
		scanf("%d %d",&width,&height);	
	}
}
