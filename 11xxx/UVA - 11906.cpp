#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector< vector< vector<int*>>>connect;
vector<int*>result;
bool square[101][101];

//不能用: overflow(???)
void dfs(int x, int y) {
	int *create = new int[2];
	create[0] = x;
	create[1] = y;
	result.push_back(create);
	square[x][y] = true;
	for (int i = 0; i < connect[x][y].size(); i++)
	{
		if (!square[connect[x][y][i][0]][connect[x][y][i][1]])
		{
			//cout << connect[x][y][i].first << " " << connect[x][y][i].second << "\n";
			dfs(connect[x][y][i][0], connect[x][y][i][1]);
		}
	}
}

int main() {
	int numcase;
	int r, c, m, n;
	int numwater;
	int x, y;
	cin >> numcase;
	for (int i = 0; i < numcase; i++)
	{
		cin >> r >> c >> m >> n;
		cin >> numwater;
		bool square[101][101] = {};
		connect.resize(r);
		for (int j = 0; j < r; j++)
		{
			connect[j].resize(c);
		}
		for (int k = 0; k < r; k++)
		{
			for (int j = 0; j < c; j++)
			{
				square[k][j] = false;
			}
		}
		for (int j = 0; j < numwater; j++)
		{
			cin >> x >> y;
			square[x][y] = true;
		}
		for (int k = 0; k < r; k++)
		{
			for (int j = 0; j < c; j++)
			{
				connect[k][j].clear();
				//(n,m)
				if (k + m < r)
				{
					if (j + n < c && !square[k + m][j + n])
					{
						int *create = new int[2];
						create[0] = k + m;
						create[1] = j + n;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int,int>(k + m, j + n));
					}
					if (j - n >= 0 && !square[k + m][j - n] && n != 0)
					{
						int *create = new int[2];
						create[0] = k + m;
						create[1] = j - n;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int, int>(k + m, j - n));
					}
				}
				if (k - m >= 0 && m != 0)
				{
					if (j + n < c && !square[k - m][j + n])
					{
						int *create = new int[2];
						create[0] = k - m;
						create[1] = j + n;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int, int>(k - m, j + n));
					}
					if (j - n >= 0 && !square[k - m][j - n] && n != 0)
					{
						int *create = new int[2];
						create[0] = k - m;
						create[1] = j - n;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int, int>(k - m, j - n));
					}
				}
				if (m == n)
				{
					continue;
				}
				//(m,n)
				if (k + n < r)
				{
					if (j + m < c && !square[k + n][j + m])
					{
						int *create = new int[2];
						create[0] = k + n;
						create[1] = j + m;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int, int>(k + n, j + m));
					}
					if (j - m >= 0 && !square[k + n][j - m] && m != 0)
					{
						int *create = new int[2];
						create[0] = k + n;
						create[1] = j - m;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int, int>(k + n, j - m));
					}
				}
				if (k - n >= 0 && n != 0)
				{
					if (j + m < c && !square[k - n][j + m])
					{
						int *create = new int[2];
						create[0] = k - n;
						create[1] = j + m;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int, int>(k - n, j + m));
					}
					if (j - m >= 0 && !square[k - n][j - m] && m != 0)
					{
						int *create = new int[2];
						create[0] = k - n;
						create[1] = j - m;
						connect[k][j].push_back(create);
						//connect[k][j].push_back(pair<int, int>(k - n, j - m));
					}
				}
			}
		}
		result.clear();
		//dfs(0, 0);
		stack<int*>sta;
		int *create = new int[2];
		create[0] = 0;
		create[1] = 0;
		result.push_back(create);
		square[0][0] = true;
		sta.push(create);
		while (!sta.empty())
		{
			int *pos = sta.top();
			sta.pop();
			for (int j = 0; j < connect[pos[0]][pos[1]].size(); j++)
			{
				if (!square[connect[pos[0]][pos[1]][j][0]][connect[pos[0]][pos[1]][j][1]])
				{
					square[connect[pos[0]][pos[1]][j][0]][connect[pos[0]][pos[1]][j][1]] = true;
					result.push_back(connect[pos[0]][pos[1]][j]);
					sta.push(connect[pos[0]][pos[1]][j]);
				}
			}
		}


		//---------------------------
		int odd = 0, even = 0;
		for (int j = 0; j < result.size(); j++)
		{
			if (connect[result[j][0]][result[j][1]].size() % 2 == 1)
			{
				odd++;
			}
			else
			{
				even++;
			}
		}
		cout << "Case " << i + 1 << ": " << even << " " << odd << "\n";
	}
	system("pause");
	return 0;
}