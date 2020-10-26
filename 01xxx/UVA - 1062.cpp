#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<char>containers;
	string line;
	int caseNum = 0;
	bool newStack;
	while (cin >> line && line != "end")
	{
		containers.clear();
		for (int i = 0, end = line.size(); i < end; ++i)
		{
			newStack = true;
			for (int j = 0, c_end = containers.size(); j < c_end; ++j)
			{
				if (line[i] <= containers[j])
				{
					containers[j] = line[i];
					newStack = false;
					break;
				}
			}
			if (newStack)
			{
				containers.push_back(line[i]);
			}
		}
		cout << "Case " << ++caseNum << ": " << containers.size() << endl;
	}
	system("pause");
	return 0;
}