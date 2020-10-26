#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
	int u, v;
	int oo = 1000000001;
	int c = 0;
	while (cin >> u >> v && (u || v))
	{
		int dp[101][101];
		for (int i = 0; i < 101; i++)
		{
			for (int j = 0; j < 101; j++)
			{
				dp[i][j] = oo;
			}
		}
		for (int i = 0; i < 101; i++)
		{
			dp[i][i] = 0;
		}
		dp[u][v] = 1;
		while (cin >> u >> v && (u || v)) {
			dp[u][v] = 1;
		}
		for (int k = 1; k < 101; k++)
		{
			for (int i = 1; i < 101; i++)
			{
				for (int j = 1; j < 101; j++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		double sum = 0;
		int cnt = 0;
		for (int i = 1; i < 101; i++)
		{
			for (int j = 1; j < 101; j++)
			{
				if (dp[i][j] > 0 && dp[i][j] < oo)
				{
					//cout << i<<" - "<<j<<" : " << dp[i][j] << "\n";
					sum += dp[i][j];
					cnt++;
				}
			}
		}
		cout << "Case " << ++c << ": average length between pages = " << fixed << setprecision(3) << sum / cnt << " clicks\n";
	}
	return 0;
}
