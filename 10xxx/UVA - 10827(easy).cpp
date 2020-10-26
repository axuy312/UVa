#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int c;
	cin >> c;
	while (c--)
	{
		int N;
		vector<vector<int>>sum;
		cin >> N;
		sum.resize(2 * N + 1);
		for (int i = 0; i <= 2 * N; i++)
		{
			sum[i].resize(2 * N + 1);
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> sum[i][j];
				sum[i + N][j] = sum[i][j + N] = sum[i + N][j + N] = sum[i][j];
				//cout << sum[i][j] << " ";
			}
			//cout << "\n";
		}
		for (int i = 1; i <= 2 * N; i++)
		{
			for (int j = 1; j <= 2 * N; j++)
			{
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
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
				for (int x = i; x <= N + i - 1; x++)
				{
					for (int y = j; y <= N + j - 1; y++)
					{
						Max = max(Max, sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]);
					}
				}
			}
		}
		cout << Max << "\n";
	}
	return 0;
}