#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
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
	int n, m;
	string line, str;
	while (getline(cin, line))
	{
		n = 0;
		for (int i = 0; i < line.size(); i++) {
			switch (line[i])
			{
			case '(':
				point[n].x = point[n].y = 0;
				str = "";
				break;
			case ')':
				point[n].y = atof(str.c_str());
				n++;
				break;
			case ',':
				point[n].x = atof(str.c_str());
				str = "";
				break;
			case ' ':
				break;
			default:
				str += line[i];
				break;
			}

		}


		/*for (int i = 0; i < n; i++)
		{
			cout << fixed << setprecision(3) << point[i].x << " " << point[i].y << "\n";
		}*/

		m = 0;
		sort(point, point + n, compare_min);
		sort(point + 1, point + n, compare_angle);



		point[n] = point[0];
		for (int i = 0; i <= n; i++)
		{
			while (m > 1 && cross(ans[m - 2], ans[m - 1], point[i]) <= 0)
			{
				m--;
			}
			ans[m++] = point[i];
		}
		for (int i = 0; i < m; i++)
		{
			if (i)
				printf(" ");
			cout << "(" << ans[i].x << "," << ans[i].y << ")";
			//printf("(%g,%g)", ans[i].x, ans[i].y);
		}
		printf("\n");
	}
	return 0;
}