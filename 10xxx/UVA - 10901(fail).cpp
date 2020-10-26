#include <iostream> 
#include <queue> 

using namespace std;

int main() {
	queue<pair<int, int>>l, r, s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>result;
	int t_n, n, t, m, time;
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
		while (l.size() || r.size())
		{
			while (l.size() && l.front().second <= time && s.size() < n)
			{
				s.push(l.front());
				l.pop();
			}
			if (s.size() || r.size() && r.front().second <= time)
			{
				time += t;
			}
			else
			{
				if (!r.size() && l.size())
				{
					time = l.front().second;
					continue;
				}
				else if (!l.size() && r.size())
				{
					time = r.front().second + t;
				}
				else
				{
					if (r.front().second < l.front().second)
					{
						time = r.front().second + t;
					}
					else
					{
						time = l.front().second;
						continue;
					}
				}
			}
			while (s.size())
			{
				result.push(pair<int, int>(s.front().first, time));
				s.pop();
			}
			while (r.size() && r.front().second <= time && s.size() < n)
			{
				s.push(r.front());
				r.pop();
			}
			if (s.size() || l.size() && l.front().second <= time)
			{
				time += t;
			}
			else
			{
				if (!r.size() && l.size())
				{
					time = l.front().second + t;
					continue;
				}
				else if (!l.size() && r.size())
				{
					time = r.front().second + t;
				}
				else if (!r.size() && !l.size())
				{
					break;
				}
				else
				{
					if (r.front().second <= l.front().second)
					{
						time = r.front().second + t;

						while (r.size() && r.front().second <= time && s.size() < n)
						{
							s.push(r.front());
							r.pop();
						}
					}
					else
					{
						time = l.front().second + t;
						continue;
					}
				}
			}
			while (s.size())
			{
				result.push(pair<int, int>(s.front().first, time));
				s.pop();
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