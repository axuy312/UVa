#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct Point
{
	int x, y;
};
Point point[1000];
Point ans[1000];
int cross(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
int distance(Point a, Point b) {
	return (int)sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool compare_angle(Point a, Point b)
{
	int c = cross(point[0], a, b);
	return c > 0 || (c == 0 && distance(point[0], a) < distance(point[0], b));
}
bool compare_min(Point a, Point b)
{
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}
int main() {
	int t, n, m;
	cin >> t;
	cout << t << "\n";
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> point[i].x >> point[i].y;
		}
		cin >> point[0].x >> point[0].y;
		if (t) {
			cin >> m;
		}
		m = 0;
		sort(point, point + n - 1, compare_min);
		sort(point + 1, point + n - 1, compare_angle);
		point[n - 1].x = point[0].x;
		point[n - 1].y = point[0].y;
		ans[m++] = point[0];
		for (int i = 1; i < n; i++)
		{
			while (m > 1 && cross(ans[m - 2], ans[m - 1], point[i]) <= 0)
			{
				m--;
			}
			ans[m++] = point[i];
		}
		cout << m << "\n";
		for (int i = 0; i < m; i++)
		{
			cout << ans[i].x << " " << ans[i].y << "\n";
		}
		if (t) {
			cout << "-1\n";
		}
	}
	return 0;
}