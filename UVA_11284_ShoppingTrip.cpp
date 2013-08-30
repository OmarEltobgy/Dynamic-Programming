#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int shopN, roadN, INF=1000000, DVDN, DVDStore[15];
long long graph[60][60], DVDDiff[15], dp[51][4100];
long long solve(int index, int taken)
{
	int i;
	long long take=0, leave=0, best=INF;
	if(taken == (1<<DVDN)-1)
	{
		return graph[index][0];
	}
	if(dp[index][taken] != -1)
	{
		return dp[index][taken];
	}
	for(i=0; i<DVDN; i++)
	{
		if((taken & (1<<i)) == 0)
		{
			take = graph[index][DVDStore[i]] + solve(DVDStore[i], (taken | (1<<i)));
			best = min(take, best);
			leave = DVDDiff[i] + solve(index, (taken | (1<<i)));
			best = min(leave, best);
		}
	}
	return dp[index][taken] = best;
}
int main()
{
	int testN, i, j, first, second, k;
	long long normal, trip, t, a, b;
	scanf("%d",&testN);
	while(testN--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d %d",&shopN,&roadN);
		for(i=0; i<=shopN; i++)
		{
			for(j=0; j<=shopN; j++)
			{
				graph[i][j] = INF;
			}
			graph[i][i] = 0;
		}
		for(i=0; i<roadN; i++)
		{
			scanf("%d %d %lld.%lld",&first,&second,&a,&b);
			t = a*100 + b;
			graph[first][second] = min(t, graph[first][second]);
			graph[second][first] = min(t, graph[second][first]);
		}
		scanf("%d",&DVDN);
		normal = 0;
		for(i=0; i<DVDN; i++)
		{
			scanf("%d %lld.%lld",&DVDStore[i],&a,&b);
			DVDDiff[i] = a*100+b;
			normal += DVDDiff[i];
		}
		for(k=0; k<=shopN; k++)
		{
			for(i=0; i<=shopN; i++)
			{
				for(j=0; j<=shopN; j++)
				{
					if(graph[i][k] + graph[k][j] < graph[i][j])
					{
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
		trip = solve(0, 0);
		long long answer = normal - trip;
		if(answer <= 0)
		{
			printf("Don't leave the house\n");
		}
		else
		{
			printf("Daniel can save $%.2lf\n", (answer+1e-9)/100);
		}
	}
	return 0;
}
