#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int N, S, Q, Qi, numCase, result, numCargoes = 0, numStation;
	int store[100];
	vector<queue<int>>station;
	stack<int>carrier;
	cin >> numCase;
	for (int n = 0; n < numCase; n++)
	{
		result = 0;
		station.clear();
		cin >> N >> S >> Q;
		station.resize(N);
		for (int s = 0; s < N; s++)
		{
			cin >> Qi;
			numCargoes += Qi;
			for (int i = 0; i < Qi; i++)
			{
				cin >> store[i];
			}
			for (int i = Qi - 1; i >= 0; i--)
			{
				station[s].push(store[i]);
			}
		}
		numStation = 1;
		while (true)
		{
			while (carrier.size() != 0 && station[numStation - 1].size() < Q)
			{
				if (carrier.top() == numStation)
				{
					carrier.pop();
					numCargoes--;
				}
				else
				{
					station[numStation - 1].push(carrier.top());
					carrier.pop();
				}
				result++;
				
			}
			while (carrier.size() != 0 && carrier.top() == numStation)
			{
				carrier.pop();
				numCargoes--;
				result++;
			}
			while (station[numStation - 1].size() != 0 && carrier.size() < S)
			{
				carrier.push(station[numStation - 1].front());
				station[numStation - 1].pop();
				result++;
			}
			if (!numCargoes)
			{
				break;
			}
			if (++numStation > N)
			{
				numStation = 1;
			}
			result += 2;
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}