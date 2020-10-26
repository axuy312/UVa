#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, X;
	vector<int>wind[10];
	vector<int>cost[10];
	cin >> N;
	while (N--)
	{
		cin >> X;
		X /= 100;
		for (int j = 9; j >= 0; j--)
		{
			wind[j].clear();
			cost[j].clear();
			wind[j].resize(X+1, 0);
			cost[j].resize(X+1, 1000000);
			for (int i = 0; i < X; i++)
			{
				cin >> wind[j][i];
			}
		}
		cost[0][0] = -wind[0][0];
		for (int i = 0; i < X; i++)
		{
			if (cost[0][i] < 1000000)
			{
				if (cost[0][i + 1] > cost[0][i] + 30 - wind[0][i + 1])//hold
				{
					cost[0][i + 1] = cost[0][i] + 30 - wind[0][i + 1];
				}
				if (cost[1][i + 1] > cost[0][i] + 60 - wind[1][i + 1])//climb
				{
					cost[1][i + 1] = cost[0][i] + 60 - wind[1][i + 1];
				}
			}
			for (int j = 1; j < 9; j++)
			{
				if (cost[j][i] >= 1000000)
				{
					continue;
				}
				if (cost[j - 1][i + 1] > cost[j][i] + 20 - wind[j - 1][i + 1])//sink
				{
					cost[j - 1][i + 1] = cost[j][i] + 20 - wind[j - 1][i + 1];
				}
				if (cost[j][i + 1] > cost[j][i] + 30 - wind[j][i + 1])//hold
				{
					cost[j][i + 1] = cost[j][i] + 30 - wind[j][i + 1];
				}
				if (cost[j + 1][i + 1] > cost[j][i] + 60 - wind[j + 1][i + 1])//climb
				{
					cost[j + 1][i + 1] = cost[j][i] + 60 - wind[j + 1][i + 1];
				}
			}
			if (cost[0][i] < 1000000)
			{
				if (cost[8][i + 1] > cost[9][i] + 20 - wind[8][i + 1])//sink
				{
					cost[8][i + 1] = cost[9][i] + 20 - wind[8][i + 1];
				}
				if (cost[9][i + 1] > cost[9][i] + 30 - wind[9][i + 1])//hold
				{
					cost[9][i + 1] = cost[9][i] + 30 - wind[9][i + 1];
				}
			}
		}
		/*cout << "\n\n";
		for (int j = 9; j >= 0; j--)
		{
			for (int i = 0; i <= X; i++)
			{
				cout << " " << cost[j][i];
			}
			cout << "\n";
		}
		cout << "\n\n";*/
		cout << cost[0][X] << "\n\n";
	}
	return 0;
}