#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool sortByPrice(pair<int, int>a, pair<int, int>b) {
	return a.first > b.first;
}

int main(){
	int m, n, p, f;
	//int cnt = 0;
	while (cin >> m >> n)
	{
		/*if (++cnt == 52) {
			system("pause");
		}*/
		int extend = 0;
		vector<int>dp;
		if (m > 1800 && m <= 2000) {
			dp.resize(m + 201);
			pair<int, int>* input = new pair<int, int>[n] {};
			int* cost = new int[m + 201]{};
			for (int i = 0; i < n; i++)
			{
				cin >> input[i].first >> input[i].second;
			}
			//sort(input, input + n, sortByPrice);//P.S小到大排序會有遺漏(雖然也是AC)
			for (int j = 0; j < n; j++)
			{
				//cout << input[i].first << " " << input[i].second << "\n";
				for (int i = m + 200; i >= input[j].first; i--)
				{
						if (dp[i - input[j].first] + input[j].second > dp[i])
						{
							cost[i] = cost[i - input[j].first] + input[j].first;
							dp[i] = dp[i - input[j].first] + input[j].second;
						}
					/*if (i <= m)
					{
						if (dp[i - input[j].first] + input[j].second > dp[i])
						{
							cost[i] = cost[i - input[j].first] + input[j].first;
						}
						dp[i] = max(dp[i - input[j].first] + input[j].second, dp[i]);
					}
					else if (dp[i -  input[j].first] != 0 || (input[j].first > 2000 && i >= input[j].first))
					{
						if (dp[i - input[j].first] + input[j].second > dp[i])
						{
							cost[i] = cost[i - input[j].first] + input[j].first;
						}
						dp[i] = max(dp[i - input[j].first] + input[j].second, dp[i]);
					}*/
				}
			}
			if (cost[m + 200] > 2000)
			{
				dp[m] = dp[m + 200];
			}
		}
		else
		{
			if (m > 2000)
			{
				extend = 200;
			}
			dp.resize(m + 1 + extend);
			while (n--)
			{
				cin >> p >> f;
				for (int i = m + extend; i >= p; i--)
				{
					dp[i] = max(dp[i - p] + f, dp[i]);
				}
			}
		}
			/*for (int i = 0; i <= m; i++)
			{
				cout << dp[i] << " ";
			}
			cout << "\n";*/
		//ofstream cout("r.txt", ios::app);
		cout << dp[m + extend] << "\n";
	}
	return 0;
}
