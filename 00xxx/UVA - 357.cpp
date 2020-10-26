#include <iostream>
#include <vector>

using namespace std;

int main(){
	int money[] = { 1,5,10,25,50 };
	vector<long long>dp(30001);
	dp[0] = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = money[i]; j < dp.size(); j++)
		{
			dp[j] += dp[j - money[i]];
		}
	}
	int n;
	while (cin >> n)
	{
		if (dp[n] == 1)
		{
			cout << "There is only 1 way to produce " << n <<" cents change.\n";
		}
		else
		{
			cout << "There are " << dp[n] <<" ways to produce " << n << " cents change.\n";
		}
	}
	return 0;
}