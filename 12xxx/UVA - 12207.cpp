#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int>line;
	int p, c, num, size, numcase = 0;
	int *result;
	char command;
	while (cin >> p >> c)
	{
		if (p == 0 && c == 0)
		{
			break;
		}
		size = 0;
		line.clear();
		result = new int[c]();
		for (int i = 1; i <= p && i <= 1000; i++)
		{
			line.push_back(i);
		}
		for (int i = 0; i < c; i++)
		{
			cin >> command;
			if (command == 'E')
			{
				cin >> num;
				for (deque<int>::iterator it = line.begin(); it != line.end(); ++it)
				{
					if (*it == num)
					{
						line.erase(it);
						break;
					}
				}
				line.push_front(num);
			}
			else
			{
				result[size++] = *(line.begin());
				line.push_back(*line.begin());
				line.erase(line.begin());
			}
		}
		cout << "Case " << ++numcase << ":\n";
		for (int i = 0; i < size; i++)
		{
			cout << result[i] << endl;
		}
		if (result != nullptr)
		{
			delete[] result;
		}
	}
	return 0;
}