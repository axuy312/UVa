#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	int numcase;
	string line, copy;
	cin >> numcase;
	cin.ignore();
	cin.clear();
	getline(cin, line);
	for (size_t i = 0; i < numcase; i++)
	{
		int sum = 0;
		map<string, int>species;
		while (getline(cin, line, '\n'))
		{
			if (line == "")
			{
				break;
			}
			copy = line;
			if (species[line] == 0)
			{
				species[line] = 1;
			}
			else
			{
				species[line]++;
			}
			sum++;
		}
		if (species.size() != 0)
		{
			for (map<string, int>::iterator it = species.begin(); it != species.end(); ++it)
			{
				cout << it->first << " " << fixed << setprecision(4) << (double)it->second * 100.0 / sum << endl;
			}
		}
		if (i < numcase - 1)
		{
			cout << "\n";
		}
	}


	system("pause");
	return 0;
}