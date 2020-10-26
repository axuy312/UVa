#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>


using namespace std;

vector<int>computer[10];
int usable[100];
string printR;

bool dfs(string r) {
	int last = r.size();
	bool find;
	if (last == 10)
	{
		for (int i = 0; i < 26; i++)
		{
			if (usable[i] != 0)
			{
				return false;
			}
		}
		printR = r;
		return true;
	}
	for (int i = 0; i < computer[last].size(); i++)
	{
		if (computer[last][i] != '_' - 'A' && usable[computer[last][i]] == 0)
		{
			continue;
		}
		if (computer[last][i] != '_' - 'A')
		{
			usable[computer[last][i]]--;
		}
		find = dfs(r + char('A' + computer[last][i]));
		if (computer[last][i] != '_' - 'A')
		{
			usable[computer[last][i]]++;
		}
		if (find)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	char app = '\0', c = '\0';
	int num = 0, index = 0;
	string result, line;
	for (int i = 0; i < 10; i++)
	{
		computer[i].clear();
	}
	for (int i = 0; i < 26; i++)
	{
		usable[i] = 0;
	}
	while (getline(cin, line) || cin.eof())
	{
		if (line == "" || cin.eof())
		{
			for (int i = 0; i < 10; i++)
			{
				computer[i].push_back('_' - 'A');
			}
			if (dfs(result))
			{
				cout << printR << "\n";
			}
			else
			{
				cout << "!\n";
			}
			for (int i = 0; i < 10; i++)
			{
				computer[i].clear();
			}
			for (int i = 0; i < 26; i++)
			{
				usable[i] = 0;
			}
			if (cin.eof())
			{
				break;
			}
		}
		else
		{
			usable[line[0] - 'A'] = line[1] - '0';
			for (int i = 3; i < line.size() - 1; i++)
			{
				computer[line[i] - '0'].push_back(line[0] - 'A');
			}
		}
	}
	return 0;
}