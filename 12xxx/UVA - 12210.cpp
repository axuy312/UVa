#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int nB, nS, age, minAge, t = 0;
	while (cin >> nB >> nS)
	{
		if (!nB && !nS)
		{
			break;
		}
		if (nB)
		{
			cin >> minAge;
		}
		for (int i = 1; i < nB; i++)
		{
			cin >> age;
			minAge = min(age, minAge);
		}
		for (int i = 0; i < nS; i++)
		{
			cin >> age;
		}
		cout << "Case " << ++t << ": ";
		if (nB > nS)
		{
			cout << nB - nS << " " << minAge;
		}
		else
		{
			cout << "0";
		}
		cout << "\n";
	}
	return 0;
}