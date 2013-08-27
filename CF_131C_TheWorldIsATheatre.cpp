#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long dp[35][35];
long long solve(int n, int r)
{
	if(r == 0 || n == r) return 1;
	if(dp[n][r] != -1) return dp[n][r];
	return dp[n][r] = solve(n-1, r-1) + solve(n-1, r);
}
int main()
{
	long long boysN, girlsN, total, result, b, g, first, second;
	cin >> boysN >> girlsN >> total;
	memset(dp, -1, sizeof(dp));
	result = 0;
	for(b=4; b<=total-1 && b<=boysN; b++)
	{
		g = total - b;
		if(g <= girlsN)
		{
			first = solve(boysN, b);
			second = solve(girlsN, g);
			result += first * second;
		}
	}
	cout << result << endl;
}
