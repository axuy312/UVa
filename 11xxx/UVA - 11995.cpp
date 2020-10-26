#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue<int>que;
	vector<int>data_stack;
	vector<int>data_queue;
	int num, com, value;
	bool is_stack, is_queue, is_priority_queue;
	while (cin >> num)
	{
		while (que.size())
		{
			que.pop();
		}
		data_queue.clear();
		data_stack.clear();
		is_stack = true, is_queue = true, is_priority_queue = true;
		for (int i = 0; i < num; i++)
		{
			cin >> com >> value;
			if (com == 1)
			{
				data_stack.push_back(value);
				data_queue.push_back(value);
				que.push(value);
			}
			else
			{
				if (que.size() == 0)
				{
					is_stack = is_queue = is_priority_queue = false;
					continue;
				}
				if (is_priority_queue)
				{
					if (que.top() != value)
					{
						is_priority_queue = false;
					}
					else
					{
						que.pop();
					}
				}
				if (is_stack)
				{
					if (*(--data_stack.end()) != value)
					{
						is_stack = false;
					}
					else
					{
						data_stack.pop_back();
					}
				}
				if (is_queue)
				{
					if (data_queue[0] != value)
					{
						is_queue = false;
					}
					else
					{
						data_queue.erase(data_queue.begin());
					}
				}
			}
		}
		if (is_stack && !is_queue && !is_priority_queue)
		{
			cout << "stack\n";
		}
		else if (!is_stack && is_queue && !is_priority_queue)
		{
			cout << "queue\n";
		}
		else if (!is_stack && !is_queue && is_priority_queue)
		{
			cout << "priority queue\n";
		}
		else if (!is_stack && !is_queue && !is_priority_queue)
		{
			cout << "impossible\n";
		}
		else
		{
			cout << "not sure\n";
		}
	}
	system("pause");
	return 0;
}