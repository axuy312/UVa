#include <iostream>
#include <algorithm>
#include <vector>
//#include <fstream>

using namespace std;

int main() {
	int value, N;
	//ofstream out("t.txt");
	while (cin >> N && N)
	{
		vector<int>dp;
		int maxV = -1;
		while (N--)
		{
			cin >> value;
			dp.push_back(value);
			if (dp.size() > 1)
			{
				dp[dp.size() - 1] = max(dp.back(), dp[dp.size() - 2] + value);
			}
			maxV = max(maxV, dp.back());
		}
		if (maxV > 0)
		{
			cout << "The maximum winning streak is " << maxV << ".\n";
		}
		else
		{
			cout << "Losing streak.\n";
		}
	}
	return 0;
}