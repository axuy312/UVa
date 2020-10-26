#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main() {
	int numcase, numword;
	string word[205], line, sourceWord, targetWord;
	bool visited[205];
	int distance[205], source, target;
	queue<int>queqe_word;
	vector<int>connect[205];
	stringstream ss;

	cin >> numcase;
	while (numcase--)
	{
		//create dictionary
		for (int i = 0; i < 205; i++)
		{
			//input dictionarys
			cin >> word[i];
			if (word[i] == "*")//end dictionary
			{
				numword = i;
				break;
			}

			//init
			connect[i].clear();

			//create graph
			for (int j = 0; j < i; j++)
			{
				//check connect
				if (word[i].size() == word[j].size())
				{
					int diff = 0;
					for (int s = 0; s < word[i].size() && diff < 2; s++)
					{
						if (word[i][s] != word[j][s])
						{
							diff++;
						}
					}
					if (diff == 1)
					{
						connect[i].push_back(j);
						connect[j].push_back(i);
					}
				}
			}
		}

		/*
		//debug
		for (int i = 0; i < numword; i++)
		{
			cout << i << ". " << word[i] << ":";
			for (int j = 0; j < connect[i].size(); j++)
			{
				cout << " " << word[connect[i][j]];
			}
			cout << "\n";
		}*/

		cin.clear();
		cin.ignore();
		while (getline(cin, line) && line.size())
		{
			ss.str("");
			ss.clear();
			ss << line;
			ss >> sourceWord >> targetWord;
			for (int i = 0; i < numword; i++)
			{
				if (sourceWord == word[i])
				{
					source = i;
				}
				if (targetWord == word[i])
				{
					target = i;
				}
			}

			//init
			while (!queqe_word.empty())
			{
				queqe_word.pop();
			}
			for (int i = 0; i < numword; i++)
			{
				visited[i] = false;
				distance[i] = 0;
			}

			//run BFS
			int u = source;
			queqe_word.push(u);
			visited[u] = true;

			while (!queqe_word.empty())
			{

				u = queqe_word.front();
				queqe_word.pop();
				//visited[u] = true;
				//distance[u] = distance[pi[u]] + 1;
				if (u == target)
				{
					break;
				}
				for (int i = 0; i < connect[u].size(); i++)
				{
					if (!visited[connect[u][i]])
					{
						visited[connect[u][i]] = true;
						queqe_word.push(connect[u][i]);
						distance[connect[u][i]] = distance[u] + 1;
						//pi[connect[u][i]] = u;
					}
				}
			}
			cout << sourceWord << " " << targetWord << " " << distance[target] << "\n";

			//end BFS
		}
		if (numcase)
		{
			cout << "\n";
		}
	}
	return 0;
}