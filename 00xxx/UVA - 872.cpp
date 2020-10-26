#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
vector<vector<int>>nextChar;
char output[26];
char letters[26];
int connected[26] = {};
int numLetter;
bool dfs(int index) {
	if (index == numLetter)
	{
		cout << letters[output[0]];
		for (int i = 1; i < numLetter; i++)
		{
			cout << " " << letters[output[i]];
		}
		cout << '\n';
		return true;
	}
	bool vaild = false;
	for (int i = 0; i < numLetter; i++)
	{
		if (connected[i] == 0)
		{
			--connected[i];
			output[index] = i;
			for (int j = 0; j < nextChar[i].size(); j++)
			{
				connected[nextChar[i][j]]--;
			}
			vaild = dfs(index + 1);
			connected[i]++;
			for (int j = 0; j < nextChar[i].size(); j++)
			{
				connected[nextChar[i][j]]++;
			}
		}
	}
	return vaild;
}

int main() {
	int numcase;
	string line;
	stringstream ss;
	cin >> numcase;
	cin.clear();
	cin.ignore();
	while (numcase--)
	{
		for (int i = 0; i < numLetter; i++)
		{
			connected[i] = 0;
		}
		numLetter = 0;
		getline(cin, line);
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss << line;
		while (ss >> letters[numLetter])
		{
			numLetter++;
		}
		for (int i = numLetter - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (letters[j] > letters[i])
				{
					char t = letters[j];
					letters[j] = letters[i];
					letters[i] = t;
				}
			}
		}
		nextChar.clear();
		nextChar.resize(numLetter);
		getline(cin, line);
		ss.str("");
		ss.clear();
		ss << line;
		while (ss >> line)
		{
			int a, b;
			bool ba = true, bb = true;
			for (int i = 0; ba || bb; i++)
			{
				if (letters[i] == line[0])
				{
					a = i;
					ba = false;
				}
				else if (letters[i] == line[2])
				{
					b = i;
					bb = false;
				}
			}
			nextChar[a].push_back(b);
			connected[b]++;
		}
		if (!dfs(0))
		{
			cout << "NO\n";
		}
		if (numcase)
		{
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}