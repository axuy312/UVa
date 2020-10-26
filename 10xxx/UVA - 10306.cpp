#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, s, m;
	int oo = 100000001;
	cin >> n;
	while (n--)
	{
		int dp[301][301];
		vector<int>money;
		vector<int>value;
		cin >> m >> s;
		money.resize(m);
		value.resize(m);
		for (int i = 0; i <= s; i++)
		{
			for (int j = 0; j <= s; j++)
			{
				dp[i][j] = oo;
			}
		}
		for (int i = 0; i < m; i++)
		{
			cin >> money[i] >> value[i];
			dp[money[i]][value[i]] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = money[i]; j <= s; j++)
			{
				for (int k = value[i]; k <= s; k++)
				{
					dp[j][k] = min(dp[j][k], dp[j - money[i]][k - value[i]] + 1);
				}
			}
		}
		int Min = oo;
		for (int i = 0; i <= s; i++)
		{
			for (int j = 0; j <= s; j++)
			{
				if (i*i+j*j==s*s)
				{
					Min = min(Min, dp[i][j]);
				}
			}
		}
		if (Min >= oo)
		{
			cout << "not possible\n";
		}
		else
		{
			cout << Min << "\n";
		}
	}
	return 0;
}