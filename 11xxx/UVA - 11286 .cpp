#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int num, sub[5], max = 0, times = 0;
	map<int, map<int, map<int, map<int, map<int, int>>>>>subs;
	while (cin >> num)
	{
		subs.clear();
		max = 0;
		times = 0;
		if (num == 0)
		{
			break;
		}
		for (int i = 0, temp; i < num; i++)
		{
			cin >> sub[0] >> sub[1] >> sub[2] >> sub[3] >> sub[4];
			for (int j = 4; j > 0; j--)
			{
				for (int k = 0; k < j; k++)
				{
					if (sub[k] > sub[k + 1])
					{
						temp = sub[k];
						sub[k] = sub[k + 1];
						sub[k + 1] = temp;
					}
				}
			}
			if (subs[sub[0]][sub[1]][sub[2]][sub[3]][sub[4]] == 0)
			{
				subs[sub[0]][sub[1]][sub[2]][sub[3]][sub[4]] = 1;
			}
			else
			{
				subs[sub[0]][sub[1]][sub[2]][sub[3]][sub[4]]++;
			}
			if (subs[sub[0]][sub[1]][sub[2]][sub[3]][sub[4]] > max)
			{
				times = 1;
				max = subs[sub[0]][sub[1]][sub[2]][sub[3]][sub[4]];
			}
			else if (subs[sub[0]][sub[1]][sub[2]][sub[3]][sub[4]] == max) {
				times++;
			}
		}
		cout << max * times << "\n";
	}
	return 0;
}