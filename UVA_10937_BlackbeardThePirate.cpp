#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;

int N, M, adjMat[55][55], treasure[12][2], treasureN, INF=1000000;
int dp[12][2100], minD[12][12], dist[55][55], imp[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
//2 treasure, 1 can go there, 0 can't go there, -1 not set yet
int solve(int index, int taken)
{
	int i, best=INF, temp=INF;
	if(taken == (1<<treasureN)-1)
	{
		return minD[index][0];
	}
	if(dp[index][taken] != -1)
	{
		return dp[index][taken];
	}
	for(i=1; i<treasureN; i++)
	{
		if((taken & (1<<i)) == 0)
		{
			temp = minD[index][i] + solve(i, (taken | (1<<i)));
			best = min(best, temp);
		}
	}
	return dp[index][taken] = best;
}
void bfs(int x, int y)
{
	int topx, topy, topd, nx, ny, i;
	queue<int> Q;
	if(adjMat[x][y] == 1 && dist[nx][ny]==INF)
	{
		dist[x][y] = 0;
		Q.push(x);
		Q.push(y);
		Q.push(dist[x][y]);
	}
	while(!Q.empty())
	{
		topx = Q.front();
		Q.pop();
		topy = Q.front();
		Q.pop();
		topd = Q.front();
		Q.pop();
		for(i=0; i<4; i++)
		{
			nx = topx+imp[i][0];
			ny = topy+imp[i][1];
			if(nx<N && nx>=0 && ny<M && ny>=0 && adjMat[nx][ny]==1 && dist[nx][ny]==INF)
			{
				dist[nx][ny] = topd+1;
				Q.push(nx);
				Q.push(ny);
				Q.push(dist[nx][ny]);
			}
		}
	}
}
int main()
{
	string temp;
	int i, j, a, b, k, res;
	scanf("%d %d",&N,&M);
	getline(cin, temp);
	//cout << temp;
	while(N != 0 || M != 0)
	{
		treasureN = 1;
		memset(adjMat, -1, sizeof(adjMat));
		memset(dp, -1, sizeof(dp));
		//cout << temp;
		for(i=0; i<N; i++)
		{
			getline(cin, temp);
			for(j=0; j<M; j++)
			{
				if(temp[j] == '.' && adjMat[i][j] == -1)
				{
					adjMat[i][j] = 1;
				}
				else if(temp[j] == '@')
				{
					if(adjMat[i][j] == -1)
					{
						adjMat[i][j] = 1;
					}
					treasure[0][0] = i;
					treasure[0][1] = j;
				}
				else if(temp[j] == '~' || temp[j] == '#')
				{
					adjMat[i][j] = 0;
				}
				else if(temp[j] == '*')
				{
					for(a=i-1; a<=i+1; a++)
					{
						for(b=j-1; b<=j+1; b++)
						{
							if(a>=0 && b>=0 && a<N && b<M)
							{
								adjMat[a][b] = 0;
							}
						}
					}
				}
				else if(temp[j] == '!')
				{
					if(adjMat[i][j] == -1)
					{
						adjMat[i][j] = 1;
					}
					treasure[treasureN][0] = i;
					treasure[treasureN][1] = j;
					treasureN ++;
				}
			}
		}
		for(i=0; i<treasureN; i++)
		{
			for(a=0; a<N; a++)
			{
				for(b=0; b<M; b++)
				{
					dist[a][b] = INF;;
				}
			}
			bfs(treasure[i][0], treasure[i][1]);
			minD[i][i] = 0;
			for(j=i+1; j<treasureN; j++)
			{ 
				minD[i][j] = dist[treasure[j][0]][treasure[j][1]];
				//printf("%d %d %d\n", i, j, minD[i][j]);
				minD[j][i] = dist[treasure[j][0]][treasure[j][1]];
			}
		}
		res = solve(0, 1);
		if(res == INF)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", res);
		}
		scanf("%d %d",&N,&M);
		getline(cin, temp);
	}
	return 0;
}
