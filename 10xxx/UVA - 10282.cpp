#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
	stringstream ss;
	string line, key;
	map<string, string>dic;
	while (getline(cin, line))
	{
		if (line == "")
		{
			break;
		}
		ss.str("");
		ss.clear();
		ss << line;
		ss >> line;
		ss >> key;
		dic[key] = line;
	}
	while (cin >> key)
	{
		if (dic[key] == "")
		{
			cout << "eh\n";
		}
		else
		{
			cout << dic[key] << endl;
		}
	}
	system("pause");
	return 0;
}