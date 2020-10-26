#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	deque<string>result;
	string str, line;
	bool front = true;

	while (getline(cin, line))
	{
		if (line == "")
		{
			break;
		}
		front = true;
		str.clear();
		result.clear();
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == '[' || line[i] == ']')
			{
				if (front)
				{
					result.push_front(str);
				}
				else
				{
					result.push_back(str);
				}
				if (line[i] == ']')
				{
					front = false;
				}
				else
				{
					front = true;
				}
				str.clear();
			}
			else
			{
				str += line[i];
			}
		}
		if (front)
		{
			result.push_front(str);
		}
		else
		{
			result.push_back(str);
		}
		for (deque<string>::iterator it = result.begin(); it != result.end(); ++it)
		{
			cout << *it;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}