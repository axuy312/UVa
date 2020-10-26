#include <iostream>
#include <vector>


using namespace std;


int main() {
	int value,sum=0;
	vector<int>tail;
	vector<int>index;
	vector<int>values;
	cin >> value;
	tail.push_back(value);
	values.push_back(value);
	index.push_back(0);
	while (cin >> value)
	{
		values.push_back(value);
		if (tail[0] > value)
		{
			tail[0] = value;
			index.push_back(0);
		}
		else if (tail.back() < value)
		{
			tail.push_back(value);
			index.push_back(tail.size() - 1);
		}
		else
		{
			int ci, low = 0, high = tail.size() - 1, mid;
			while (high - low > 1)
			{
				mid = (low + high) / 2;
				if (tail[mid] >= value)
				{
					high = mid;
				}
				else
				{
					low = mid;
				}
			}
			tail[high] = value;
			index.push_back(high);
		}
		/*for (int i = 0; i < tail.size(); i++)
		{
			cout << tail[i] << " ";
		}
		cout << "\n";*/
	}
	vector<int>res;
	cout << tail.size() << "\n-\n";
	for (int i = index.size() - 1,s = tail.size() - 1; i >= 0 && s >= 0; i--)
	{
		if (index[i] == s)
		{
			res.push_back(values[i]);
			s--;
		}
	}
	for (int i = res.size() - 1; i >= 0; i--)
	{
		cout << res[i] << "\n";
	}
	return 0;
}