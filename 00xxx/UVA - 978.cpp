#include <iostream>
#include <set>

using namespace std;

int main() {
	int numcase, field, numgreen, numblue, power;
	int *battle;
	multiset<int>::iterator itg, itb;
	multiset<int>green;
	multiset<int>blue;
	cin >> numcase;
	for (int i = 0; i < numcase; i++)
	{
		green.clear();
		blue.clear();
		cin >> field >> numgreen >> numblue;
		for (int j = 0; j < numgreen; j++)
		{
			cin >> power;
			green.insert(power);
		}
		for (int j = 0; j < numblue; j++)
		{
			cin >> power;
			blue.insert(power);
		}
		while (green.size() != 0 && blue.size() != 0)
		{
			if (green.size() < field)
			{
				field = green.size();
			}
			if (blue.size() < field)
			{
				field = blue.size();
			}
			battle = new int[field];
			for (int j = 0; j < field; j++)
			{
				itg = --green.end();
				itb = --blue.end();
				battle[j] = *itg - *itb;
				green.erase(itg);
				blue.erase(itb);
			}
			for (int j = 0; j < field; j++)
			{
				if (battle[j] > 0)
				{
					green.insert(battle[j]);
				}
				else if (battle[j] < 0)
				{
					blue.insert(battle[j] * (-1));
				}
			}
		}
		if (green.size() != 0)
		{
			cout << "green wins\n";
			itg = --green.end();
			for (; itg != green.begin(); --itg)
			{
				cout << *itg << "\n";
			}
			cout << *itg << "\n";
		}
		else if (blue.size() != 0)
		{
			cout << "blue wins\n";
			itb = --blue.end();
			for (; itb != blue.begin(); --itb)
			{
				cout << *itb << "\n";
			}
			cout << *itb << "\n";
		}
		else
		{
			cout << "green and blue died\n";
		}
		if (i < numcase - 1)
		{
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}