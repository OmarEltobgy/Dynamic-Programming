#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

long long dp[5000];
long long solve(int game)
{
	long long ways = 0, best = 0;
	int game2;
	if(dp[game] != -1)
	{
		return dp[game];
	}
	for(int i=0; i<12; i++)
	{
		if((game & (1<<i)) == 0)
		{
			if(i > 1 && (game & (1<<(i-1))) != 0 && (game & (1<<(i-2))) != 0)
			{
				game2 = game;
				game2 = ( game2 | (1<<i) );
				game2 = ( game2 ^ (1<<(i-1)) );
				game2 = ( game2 ^ (1<<(i-2)) );
				ways = 1 + solve(game2);
				best = max(ways, best);
			}
			if(i < 10 && (game & (1<<(i+1))) != 0 && (game & (1<<(i+2))) != 0)
			{
				game2 = game;
				game2 = ( game2 | (1<<i) );
				game2 = ( game2 ^ (1<<(i+1)) );
				game2 = ( game2 ^ (1<<(i+2)) );
				ways = 1 + solve(game2);
				best = max(ways, best);
			}
		}
	}
	return dp[game] = best;
}
int main()
{
	int testN, i, game, N, res;
	char temp;
	scanf("%d",&testN);
	while(testN--)
	{
		getchar();
		memset(dp, -1, sizeof(dp));
		game = 0;
		N = 0;
		for(i=0; i<12; i++)
		{
			scanf("%c",&temp);
			if(temp == 'o')
			{
				game |= (1<<i);
				N++;
			}
		}
		res = solve(game);
		printf("%lld\n", N-res);
	}
}
