#include <iostream>
#include <algorithm>
//#include <fstream>

using namespace std;

int main() {
	//ofstream out("t.txt");
	int N, w;
	int oo = 1000000001;
	char old, dir, u, v;
	int c = 0;
	while (cin >> N && N)
	{
		int dp[2][26][26];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				for (int k = 0; k < 26; k++)
				{
					dp[i][j][k] = oo;
				}
			}
		}
		for (int i = 0; i < 26; i++)
		{
			dp[0][i][i] = 0;
			dp[1][i][i] = 0;
		}
		/*if (++c == 36)
		{
			cout << "--";
		}*/
		while (N--)
		{
			cin >> old >> dir >> u >> v >> w;
			int y = 0;
			if (old == 'Y')
			{
				y = 0;
			}
			else
			{
				y = 1;
			}
			dp[y][u - 'A'][v - 'A'] = w;
			if (dir == 'B')
			{
				dp[y][v - 'A'][u - 'A'] = w;
			}
		}
		if (u == v)
		{
			dp[0][u - 'A'][u - 'A'] = 0;
			dp[1][u - 'A'][u - 'A'] = 0;
		}
		for (int x = 0; x < 2; x++)
		{
			for (int k = 0; k < 26; k++)
			{
				for (int i = 0; i < 26; i++)
				{
					for (int j = 0; j < 26; j++)
					{
						dp[x][i][j] = min(dp[x][i][j], dp[x][i][k] + dp[x][k][j]);
					}
				}
			}
		}
		cin >> u >> v;
		int x = u - 'A', y = v - 'A';
		int sum = oo, n_pos = 0;
		int pos[26];
		for (int k = 0; k < 26; k++)
		{
			if (sum > dp[0][x][k] + dp[1][y][k])
			{
				sum = dp[0][x][k] + dp[1][y][k];
				n_pos = 0;
				pos[n_pos++] = k;
			}
			else if (sum == dp[0][x][k] + dp[1][y][k])
			{
				pos[n_pos++] = k;
			}
		}
		if (sum >= oo)
		{
			cout << "You will never meet.\n";
		}
		else
		{
			cout << sum;
			for (int i = 0; i < n_pos; i++)
			{
				cout << " " << char(pos[i] + 'A');
			}
			cout << "\n";
		}
	}
	return 0;
}