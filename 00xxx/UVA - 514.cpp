#include <iostream>
#include <stack>

using namespace std;

int main() {
	int num, order, n;
	stack<int>station, dirA, copyA;
	while (cin >> num, num)
	{
		while (copyA.size())
		{
			copyA.pop();
		}
		for (int i = num; i > 0; --i)
		{
			copyA.push(i);
		}
		dirA = copyA;
		n = num;
		while (cin >> order, order)
		{
			if (station.size() && station.top() == order)
			{
				station.pop();
			}
			else
			{
				while (dirA.size() && dirA.top() != order)
				{
					station.push(dirA.top());
					dirA.pop();
				}
				if (dirA.size())
				{
					dirA.pop();
				}
			}
			if ((--n) == 0)
			{
				n = num;
				dirA = copyA;
				if (station.size())
				{
					station.pop();
					while (station.size())
					{
						station.pop();
					}
					cout << "No\n";
				}
				else
				{
					cout << "Yes\n";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}