#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int main() {
	//ofstream out("t.txt");
	int N, Q;
	int D, M;
	int cnt = 0;
	vector<int>values;
	vector<int>values_mod;
	long long dp[221][20];
	while (cin >> N >> Q && (Q || N))
	{
		cout << "SET " << ++cnt << ":\n";
		int tmp;
		values.clear();
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			values.push_back(tmp);
		}
		for (int q = 0; q < Q; q++)
		{
			//Init
			values_mod.clear();
			for (int i = 0; i < 221; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					dp[i][j] = 0;
				}
			}
			dp[0][0] = 1;

			cin >> D >> M;
			for (int i = 0; i < values.size(); i++)
			{
				values_mod.push_back(values[i] % D);
				if (values_mod.back() < 0)
				{
					values_mod[i] += D;
				}
			}

			for (int k = 0; k < values_mod.size(); k++)
			{
				for (int i = M; i > 0; i--)
				{
					for (int j = 220; j >= values_mod[k]; j--)
					{
						dp[j][i] += dp[j - values_mod[k]][i - 1];
					}
				}
			}
			int sum = 0;
			for (int i = 0; i < 200; i += D)
			{
				sum += dp[i][M];
			}
			cout << "QUERY " << q + 1 << ": " << sum << "\n";
		}
	}
	return 0;
}