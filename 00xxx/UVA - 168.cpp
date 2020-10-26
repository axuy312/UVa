#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	char letter;
	int max = 0, monster, human, k;
	while (true)
	{
		max = 0;
		vector<string>cavern(26);
		while (cin >> letter)
		{
			//cout << letter;
			if (letter == '#')
			{
				break;
			}
			else
			{
				int index = letter - 'A';
				if (index > max)
				{
					max = index;
				}
				cin >> letter;
				if (letter != ';' && letter != '.')
				{
					while (cin >> letter)
					{
						//cout << letter;
						if (letter == ';' || letter == '.')
						{
							break;
						}
						cavern[index] += letter;
						if (letter - 'A' > max)
						{
							max = letter - 'A';
						}
					}
				}
			}
			if (letter == '.')
			{
				cin >> letter;
				monster = letter - 'A';
				cin >> letter;
				human = letter - 'A';
				cin >> k;
				break;
			}
		}
		if (letter == '#')
		{
			break;
		}
		bool lit[26] = {};
		bool trap = true;
		int count = 0;
		max++;
		while (true)
		{
			trap = true;
			for (int i = 0; i < cavern[monster].size(); i++)
			{
				if (!lit[cavern[monster][i] - 'A'] && cavern[monster][i] - 'A' != human)
				{
					human = monster;
					monster = cavern[monster][i] - 'A';
					//cout << "Monster: " << char('A' + monster) << '\n';
					//cout << "Human: " << char('A' + human) << '\n';
					trap = false;
					break;
				}
			}
			if (trap)
			{
				//
				if (++count == k)
				{
					count = 0;
					lit[human] = true;
				}
				cout << '/' << char('A' + monster) << '\n';
				//
				break;
			}
			else
			{
				if (++count == k)
				{
					count = 0;
					lit[human] = true;
					cout << char('A' + human) << " ";
				}
			}
		}
	}
	return 0;
}