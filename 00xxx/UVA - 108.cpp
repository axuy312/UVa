#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, value;
	vector<vector<int>>sum;
	cin >> N;
	sum.resize(N + 1);
	sum[0].resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		sum[i].resize(N + 1);
		for (int j = 1; j <= N; j++)
		{
			cin >> value;
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + value;
			//cout << sum[i][j] << " ";
		}
		//cout << "\n";
	}

	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << sum[i][j] << " ";
		}
		cout << "\n";
	}*/

	int Max = sum[1][1];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int x = i; x <= N; x++)
			{
				for (int y = j; y <= N; y++)
				{
					//cout << i << "->" << x << " " << j << "->" << y << " : ";
					//cout << sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] << "\n";
					Max = max(Max, sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]);
				}
			}
		}
	}
	cout << Max << "\n";
	return 0;
}