#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, oo = 10000001;
	cin >> N;
	while (N--)
	{
		int n, m;
		int dp[100001];
		vector<int>money;
		cin >> m >> n;
		money.resize(n);
		for (int i = 0; i < 100001; i++)
		{
			dp[i] = oo;
		}
		dp[0] = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> money[i];
			//dp[money[i]] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 100000; j >= money[i]; j--)
			{
				dp[j] = min(dp[j], dp[j - money[i]] + 1);
			}
		}
		//cout << dp[9999] << "\n" << dp[9998] << "\n" << dp[19996] << "\n" << dp[19997] << "\n";
		for (int i = m; i < 100001; i++)
		{
			if (dp[i] < oo)
			{
				cout << i << " " << dp[i] << "\n";
				break;
			}
		}

	}
	return 0;
}