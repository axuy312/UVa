#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int N, x, T, K, price, sum, f;
	while (cin >> N >> x >> T >> K && (N || x || T || K))
	{
		vector<pair<int, int>>input;
		int num = ((++N) * x) * 10;
		num /= 11;
		num -= T * N;
		vector<vector<int>>dp(2 * N + 1, vector<int>(num + 1));
		for (int i = 0; i < K; i++)
		{
			pair<int, int> p;
			cin >> p.first;
			sum = 0;
			for (int j = 0; j < N; j++)
			{
				cin >> f;
				sum += f;
			}
			p.second = sum;
			input.push_back(p);
			input.push_back(p);
		}
		//sort(input.begin(), input.end(), cmp);
		/*for (int i = 0; i < input.size(); i++)
		{
			cout << input[i].first << "  " << input[i].second << "\n";
		}*/
		for (int i = 0; i < 2 * K; i++)
		{
			for (int j = 2 * N; j > 0; j--)
			{
				for (int k = num; k >= input[i].first; k--)
				{
					dp[j][k] = max(dp[j - 1][k - input[i].first] + input[i].second, max(dp[j - 1][k], dp[j][k]));
				}
			}
		}
		/*for (int k = num; k >= 0; k--)
		{
			cout << k << ": " << dp[1][k] << "\n";
		}*/
		int Max = 0;
		for (int i = 1; i <= 2 * N; i++)
		{
			Max = max(Max, dp[i][num]);
		}
		cout << fixed << setprecision(2) << (double)Max / N << "\n";
	}
	return 0;
}