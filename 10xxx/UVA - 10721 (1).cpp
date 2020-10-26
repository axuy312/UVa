#include <iostream>
using namespace std;

int main() {
	long long dp[51][51][51];
	for (int x = 1; x < 51; x++)
	{
		for (int z = x; z < 51; z++)
		{
			dp[x][1][z] = 1;
		}
	}
	for (int x = 2; x < 51; x++)
	{
		for (int y = 2; y < 51; y++)
		{
			for (int z = 1; z < 51; z++)
			{
				for (int i = 1; i <= z && i < x; i++)
				{
					dp[x][y][z] += dp[x - i][y - 1][z];
				}
				//cout << "(" << x << "," << y << "," << z << ") : " << dp[x][y][z] << "\n";
			}
		}
	}
	int n, k, m;
	while (cin >> n >> k >> m)
	{
		cout << dp[n][k][m] << "\n";
	}
	return 0;
}