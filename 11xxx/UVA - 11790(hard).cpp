#include <iostream>
#include <algorithm>
#include <vector>
//#include <fstream>
using namespace std;




int main() {
	//ofstream out("t.txt");
	int n, cnt=0;
	cin >> n;
	while (n--)
	{
		int num;
		int MaxDecr = 0;
		int MaxIncr = 0;
		cin >> num;
		vector<int>dp(num + 1);
		vector<int>w(num + 1);
		vector<int>h(num + 1);

		for (int i = 1; i <= num; i++)
		{
			cin >> h[i];
		}
		for (int i = 1; i <= num; i++)
		{
			cin >> w[i];
		}



		dp[1] = w[1];
		MaxIncr = w[1];

		for (int i = 2; i <= num; i++)
		{
			dp[i] = w[i];
			for (int j = 0; j < i; j++)
			{
				if (h[i] > h[j])
				{
					dp[i] = max(dp[j] + w[i], dp[i]);
				}
			}
			MaxIncr = max(MaxIncr, dp[i]);
		}
		
		//cout << MaxIncr << "\n";

		//decre

		dp.clear();
		dp.resize(num + 1);
		reverse(++(w.begin()), w.end());
		reverse(++(h.begin()), h.end());
		dp[1] = w[1];
		MaxDecr = w[1];

		for (int i = 2; i <= num; i++)
		{
			dp[i] = w[i];
			for (int j = 0; j < i; j++)
			{
				if (h[i] > h[j])
				{
					dp[i] = max(dp[j] + w[i], dp[i]);
				}
			}
			MaxDecr = max(MaxDecr, dp[i]);
		}


		cout << "Case " << ++cnt << ". ";

		if (MaxIncr >= MaxDecr)
		{
			cout << "Increasing (" << MaxIncr << "). Decreasing (" << MaxDecr << ").\n";
		}
		else
		{
			cout << "Decreasing (" << MaxDecr << "). Increasing (" << MaxIncr << ").\n";
		}
	}
	return 0;
}