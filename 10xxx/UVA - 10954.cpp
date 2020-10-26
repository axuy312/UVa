#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue<int>addstore;
	int num, value, cost;
	while (cin >> num && num)
	{
		if (addstore.size() > 0)
		{
			addstore.pop();
		}
		cost = 0;
		for (int i = 0; i < num; i++)
		{
			cin >> value;
			addstore.push(-1 * value);
		}
		while (addstore.size() > 1)
		{
			value = addstore.top();
			addstore.pop();
			value += addstore.top();
			addstore.pop();
			cost += value;
			addstore.push(value);
		}
		cout << -1 * cost << endl;
	}
	system("pause");
	return 0;
}