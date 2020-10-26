#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int main() {
	//ofstream out("t.txt");
	int N;
	long long value;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		vector<vector<vector<long long>>>data;
		vector<vector<vector<long long>>>sum;

		data.resize(A + 1);
		sum.resize(A + 1);
		for (int i = 0; i <= A; i++)
		{
			data[i].resize(B + 1);
			sum[i].resize(B + 1);
			for (int j = 0; j <= B; j++)
			{
				data[i][j].resize(C + 1);
				sum[i][j].resize(C + 1);
			}
		}

		for (int i = 1; i <= A; i++)
		{
			for (int j = 1; j <= B; j++)
			{
				for (int k = 1; k <= C; k++)
				{
					cin >> value;
					data[i][j][k] = value;
					sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k] + value;
					//cout << sum[i][j][k] << ",";
				}
				//cout << " ";
			}
			//cout << "\n";
		}

		/*for (int i = 0; i < sum.size(); i++)
		{
			for (int j = 0; j < sum[i].size(); j++)
			{
				for (int k = 0; k < sum[i][j].size(); k++)
				{
					cout << sum[i][j][k] << ",";
				}
				cout << "   ";
			}
			cout << "\n";
		}*/



		for (int i = 1; i <= A; i++)
		{
			for (int j = 1; j <= B; j++)
			{
				for (int k = 1; k <= C; k++)
				{
					sum[i][j][k] += sum[i][j][k - 1];
					//cout << sum[i][j][k] << ",";
				}
				//cout << " ";
			}
			//cout << "\n";
		}
		/*for (int i = 0; i < sum.size(); i++)
		{
			for (int j = 0; j < sum[i].size(); j++)
			{
				for (int k = 0; k < sum[i][j].size(); k++)
				{
					cout << sum[i][j][k] << ",";
				}
				cout << "   ";
			}
			cout << "\n";
		}*/

		long long Max = sum[1][1][1];
		for (int a = 1; a <= A; a++)
		{
			for (int b = 1; b <= B; b++)
			{
				for (int c = 1; c <= C; c++)
				{
					for (int i = a; i <= A; i++)
					{
						for (int j = b; j <= B; j++)
						{
							for (int k = c; k <= C; k++)
							{
								//cout << "X: " << a << "-" << i << "  Y: " << b << "-" << j << "  Z: " << c << "-" << k << " :  ";
								//cout << sum[i][j][k] - sum[a - 1][j][k] - sum[i][b - 1][k] + sum[a - 1][b - 1][k] - (sum[i][j][c - 1] - sum[a - 1][j][c - 1] - sum[i][b - 1][c - 1] + sum[a - 1][b - 1][c - 1]) << "\n";
								long long tmp = sum[i][j][k] - sum[a - 1][j][k] - sum[i][b - 1][k] + sum[a - 1][b - 1][k] - (sum[i][j][c - 1] - sum[a - 1][j][c - 1] - sum[i][b - 1][c - 1] + sum[a - 1][b - 1][c - 1]);
								if (tmp > Max)
								{
									Max = tmp;
								}
							}
						}
					}
				}
			}
		}
		cout << Max << "\n";
		if (n != N - 1)
		{
			cout << "\n";
		}
	}
	return 0;
}