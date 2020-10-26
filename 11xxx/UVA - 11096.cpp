#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

struct Point
{
	double x, y;
};
Point point[1000];
Point ans[1000];
double cross(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double distance(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool compare_angle(Point a, Point b)
{
	double c = cross(point[0], a, b);
	return c > 0 || (c == 0 && distance(point[0], a) < distance(point[0], b));
}
bool compare_min(Point a, Point b)
{
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}
int main() {
	int n, N, m;
	double t, len;
	cin >> N;
	while (N--)
	{
		cin >> len >> n;
		t = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> point[i].x >> point[i].y;
		}

		m = 0;
		sort(point, point + n, compare_min);
		sort(point + 1, point + n, compare_angle);


		point[n] = point[0];
		/*for (int i = 0; i <= n; i++)
		{
			cout << fixed << setprecision(3) << point[i].x << " " << point[i].y << "\n";
		}*/

		for (int i = 0; i <= n; i++)
		{
			while (m > 1 && cross(ans[m - 2], ans[m - 1], point[i]) <= 0)
			{
				m--;
			}
			ans[m++] = point[i];
		}
		for (int i = 1; i < m; i++)
		{
			t += distance(ans[i - 1], ans[i]);
		}
		if (m == 2)
		{
			t = distance(point[0], point[n - 1]) * 2;
		}
		if (t < len)
		{
			cout << fixed << setprecision(5) << len << "\n";
		}
		else
		{
			cout << fixed << setprecision(5) << t << "\n";
		}
	}
	return 0;
}