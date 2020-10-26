#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<pair<int, int>>l, r, s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>result;
	bool lb;
	int t_n, n, t, m, time, num;
	char str[6];
	cin >> t_n;
	for (int i = 0; i < t_n; i++)
	{
		cin >> n >> t >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> time >> str;
			if (str[0] == 'l')
			{
				l.push(pair<int, int>(j, time));
			}
			else
			{
				r.push(pair<int, int>(j, time));
			}
		}
		time = 0;
		lb = true;
		while (l.size() || r.size())
		{
			num = 0;
			if (lb && l.size() && l.front().second <= time && num < n)
			{
				while (l.size() && l.front().second <= time && num < n)
				{
					num++;
					result.push(pair<int, int>(l.front().first, time + t));
					l.pop();
				}
				lb = !lb;
				time += t;
				continue;
			}
			else if (!lb  && r.size() && r.front().second <= time && num < n)
			{
				while (r.size() && r.front().second <= time && num < n)
				{
					num++;
					result.push(pair<int, int>(r.front().first, time + t));
					r.pop();
				}
				lb = !lb;
				time += t;
				continue;
			}

			if (r.empty() && l.size())
			{
				if (lb)
				{
					time = l.front().second;
				}
				else
				{
					if (time >= l.front().second)
					{
						time += t;
					}
					else
					{
						time = l.front().second + t;
					}
					lb = true;
				}
			}
			else if (l.empty() && r.size())
			{
				if (lb)
				{
					if (time >= r.front().second)
					{
						time += t;
					}
					else
					{
						time = r.front().second + t;
					}
					lb = false;
				}
				else
				{
					time = r.front().second;
				}
			}
			else if (r.size() && l.size())
			{
				if (r.front().second < l.front().second)
				{
					if (lb)
					{
						if (time >= r.front().second)
						{
							time += t;
						}
						else
						{
							time = r.front().second + t;
						}
						lb = false;
					}
					else
					{
						time = r.front().second;
					}
				}
				else if (r.front().second > l.front().second)
				{
					if (lb)
					{
						time = l.front().second;
					}
					else
					{
						if (l.front().second <= time)
						{
							time += t;
						}
						else
						{
							time = l.front().second + t;
						}
						lb = true;
					}
				}
				else
				{
					time = l.front().second;
				}
			}
		}
		while (result.size())
		{
			cout << result.top().second << '\n';
			result.pop();
		}
		if (i + 1 < t_n)
		{
			cout << '\n';
		}
	}
	system("pause");
	return 0;
}