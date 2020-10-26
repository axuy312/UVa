#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	int oo = 100000001;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, R, u, v;
		vector<vector<int>>dp;
		cin >> N >> R;
		dp.resize(N);
		for (int i = 0; i < N; i++)
		{
			dp[i].resize(N, oo);
			dp[i][i] = 0;
		}
		for (int r = 0; r < R; r++)
		{
			cin >> u >> v;
			dp[u][v] = dp[v][u] = 1;
		}
		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		cin >> u >> v;
		int Max = 0;
		for (int k = 0; k < N; k++)
		{
			Max = max(Max, dp[u][k] + dp[k][v]);
		}
		cout << "Case " << t + 1 << ": " << Max << "\n";
	}
	return 0;
}