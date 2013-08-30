#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int NM, NH, MM, MH;
long long dp[110][110][15][15];
long long solve(int M, int H, int MC, int HC)
{
	long long way1 = 0, way2 = 0;
	if(M+H == NM+NH)
	{
		return 1;
	}
	if(dp[M][H][MC][HC] != -1)
	{
		return dp[M][H][MC][HC];
	}
	if(M+1 <= NM && MC+1 <= MM)
	{
		way1 = solve(M+1, H, MC+1, 0) % 100000000;
	}
	if(H+1 <= NH && HC+1 <= MH)
	{
		way2 = solve(M, H+1, 0, HC+1) % 100000000 ;
	}
	return dp[M][H][MC][HC] = (way1+way2) % 100000000;
}
int main()
{
	scanf("%d %d %d %d",&NM,&NH,&MM,&MH);
	for(int i=0; i<=NM; i++)
	{
		for(int j=0; j<=NH; j++)
		{
			for(int k=0; k<=MM; k++)
			{
				for(int l=0; l<=MH; l++)
				{
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	cout << solve(0, 0, 0, 0);
}
