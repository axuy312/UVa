#include <iostream>

using namespace std;

int main() {
	int dp[101][101] = {};
	for (int i = 0; i < 101; i++)
	{
		dp[i][0] = dp[i][1] = 1;
	}
	for (int n = 0; n < 101; n++)
	{
		for (int k = 2; k < 101; k++)
		{
			for (int i = 0; i <= n && n >= i; i++)
			{
				dp[n][k] += dp[n - i][k - 1];
			}
			dp[n][k] %= 1000000;
			//printf("(%d,%d): %d\n", n, k, dp[n][k]);
		}
	}
	int n, k;
	while (cin >> n >> k && (n || k))
	{
		cout << dp[n][k] << "\n";
	}
	return  0;
}
