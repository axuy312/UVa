#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int main() {
	//ofstream out("t,txt", ios::app);
	int n, m, k;
	while (cin >> n >> k >> m)
	{
		if (m > n)
		{
			m = n;
		}
		vector<int>remain;
		remain.push_back(n);
		for (int i = k-1; i > 0; i--)
		{
			for (int x = 0, s = remain.size(); x < s; x++)
			{
				for (int j = 2; j <= m && remain[x] >= j; j++)
				{
					if (remain[x]> i && (remain[x] - j) <= m * i)
					{
						remain.push_back(remain[x] - j);
					}
				}
				if (remain[x] > 0 && (remain[x] - 1) <= m * i)
				{
					remain[x]--;
				}
				else
				{
					remain[x] = 0;
				}
			}

			/*for (int x = 0, s = remain.size(); x < s; x++)
			{
				cout << remain[x] << " ";
			}
			cout << "\n";*/
		}
		int sum = 0;
		for (int x = 0, s = remain.size(); x < s; x++)
		{
			if (remain[x] > 0 && remain[x] <= m)
			{
				sum++;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}