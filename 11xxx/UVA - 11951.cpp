#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

int main() {
	//ofstream out("t.txt");
	int N, M, K, value, T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vector<vector<int>>sum;
		cin >> N >> M >> K;
		sum.resize(N + 1);
		sum[0].resize(M + 1);
		for (int i = 1; i <= N; i++)
		{
			sum[i].resize(M + 1);
			for (int j = 1; j <= M; j++)
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

		int Max = 0, cost = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				for (int x = i; x <= N; x++)
				{
					for (int y = j; y <= M; y++)
					{
						//cout << i << "->" << x << " " << j << "->" << y << " : ";
						//cout << sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] << "\n";
						int tmp = sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
						if (tmp <= K)
						{
							if (Max < (x - i + 1) * (y - j + 1))
							{
								Max = (x - i + 1) * (y - j + 1);
								cost = tmp;
							}
							else if (Max == (x - i + 1) * (y - j + 1))
							{
								cost = min(cost, tmp);
							}
						}
					}
				}
			}
		}
		cout << "Case #" << t << ": " << Max << " " << cost << "\n";
	}
	return 0;
}