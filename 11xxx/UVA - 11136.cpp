#include <iostream>
#include <set>

using namespace std;
int main() {
	multiset<int>urn;
	unsigned int day, numorder, cost;
	long long sum;
	while (cin >> day)
	{
		if (day == 0)
		{
			break;
		}
		sum = 0;
		urn.clear();
		for (int d = 0; d < day; d++)
		{
			cin >> numorder;
			for (int n = 0; n < numorder; n++)
			{
				cin >> cost;
				urn.insert(cost);
			}
			sum += *(--urn.end()) - *urn.begin();
			urn.erase(--urn.end());
			urn.erase(urn.begin());
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}