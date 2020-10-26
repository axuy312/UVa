#include <iostream>
#include <string>
#include<list>

using namespace std;


void dfs(bool map[26][26], bool visited[26], int u, list<char>&result) {
	visited[u] = true;
	//cout << char(u + 'A') << endl;
	for (int i = 0; i < 26; i++)
	{
		if (map[u][i] && !visited[i])
		{
			//cout << char(u + 'A') << " -> " << char(i + 'A') << '\n';
			dfs(map, visited, i, result);
		}
	}
	result.push_front(char(u + 'A'));
}

int main() {
	bool map[26][26] = {};
	bool visited[26] = {};
	bool exist[26] = {};
	string word, comWord;
	list<char>result;
	cin >> comWord;
	while (cin >> word && word != "#")
	{
		int minL = comWord.size();
		if (word.size() < minL)
		{
			minL = word.size();
		}
		for (int i = 0; i < minL; i++)
		{
			if (word[i] != comWord[i])
			{
				exist[comWord[i] - 'A'] = true;
				map[comWord[i] - 'A'][word[i] - 'A'] = true;
				//cout << int(comWord[i]-'A') << " -> " << int(word[i]-'A') << endl;
				break;
			}
		}
		comWord = word;
	}
	for (int i = 0; i < 26; i++)
	{
		if (exist[i] && ! visited[i])
		{
			dfs(map, visited, i, result);
		}
	}
	for (list<char>::iterator it = result.begin(); it != result.end(); ++it)
	{
		cout << *it;
	}
	cout << '\n';
	system("pause");
	return 0;
}