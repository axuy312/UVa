#include <iostream>
#include <algorithm>
using namespace std;

	int bags[10001];
int main() {
	int n, n_stack, t, cbag, mbag;
	bool first = true;
	while (cin >> n)
	{
		if (!n)
		{
			break;
		}
		else if (!first)
		{
			cout << "\n";
		}
		first = false;
		t = cbag = mbag = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> bags[i];
		}
		sort(bags, bags + n);
		for (int i = 0; i < n; i++)
		{
			if (bags[i] != bags[i - 1])
			{
				cbag = 1;
			}
			else
			{
				cbag++;
			}
			mbag = max(mbag, cbag);
		}
		cout << mbag << "\n";
		for (int i = 0; i < mbag; i++)
		{
			cout << bags[i];
			for (int j = i + mbag; j < n; j += mbag)
			{
				cout << " " << bags[j];
			}
			cout << "\n";
		}
	}
	return 0;
}