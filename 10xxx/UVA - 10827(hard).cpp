#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int c;
	cin >> c;
	int N;
	int data[400][400] = {};
	while (c--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> data[i][j];
				data[i + N][j] = data[i][j + N] = data[i + N][j + N] = data[i][j];
				//cout << data[i][j] << " ";
			}
			//cout << "\n";
		}

		/*for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << "\n";
		}*/

		int Max = data[1][1];
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int sum[400] = {};
				for (int x = i + 1; x <= N + i; x++)
				{
					int tmp = 0;
					for (int y = j + 1; y <= N + j; y++)
					{
						sum[y] += data[x][y];
						tmp += sum[y];
						Max = max(Max, tmp);
					}
				}
			}
		}
		cout << Max << "\n";
	}
	return 0;
}