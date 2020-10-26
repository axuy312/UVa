#include<iostream>
#include <queue>
#include <string>

using namespace std;

struct instructions
{
	int num, period, cost;
	bool operator < (const instructions& r) const{
		return cost > r.cost || (cost == r.cost&& num > r.num);
	}
};

int main() {
	priority_queue<instructions>time;
	string str;
	int k;
	instructions ins;
	while (cin >> str && str != "#")
	{
		cin >> ins.num >> ins.period;
		ins.cost = ins.period;
		time.push(ins);
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		ins = time.top();
		time.pop();
		cout << ins.num << endl;
		ins.cost += ins.period;
		time.push(ins);
	}
	system("pause");
	return 0;
}