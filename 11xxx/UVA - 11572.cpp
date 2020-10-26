#include <iostream>
#include <set>

using namespace std;

int main() {
	unsigned int numcase, numsnowflakes, snowflakes, max;
	int *allsnowflakes;
	set<int>package;
	cin >> numcase;
	for (unsigned int i = 0; i < numcase; i++)
	{
		max = 0;
		package.clear();
		cin >> numsnowflakes;
		allsnowflakes = new int[numsnowflakes];
		for (unsigned int j = 0; j < numsnowflakes; j++)
		{
			cin >> allsnowflakes[j];
			if (package.count(allsnowflakes[j]))
			{
				for (int k = 0; ; k++)
				{
					if (allsnowflakes[k] == allsnowflakes[j])
					{
						package.erase(allsnowflakes[k]);
						allsnowflakes[k] = -1;
						break;
					}
					if (allsnowflakes[k] >= 0)
					{
						package.erase(allsnowflakes[k]);
						allsnowflakes[k] = -1;
					}
				}
			}
			package.insert(allsnowflakes[j]);
			if (package.size() > max)
			{
				max = package.size();
			}
		}
		if (allsnowflakes != nullptr)
		{
			delete[] allsnowflakes;
		}
		cout << max << "\n";
	}
	system("pause");
	return 0;
}