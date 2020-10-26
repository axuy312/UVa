#include <iostream>
#include <vector>
//#include <algorithm>
//#include <fstream>
using namespace std;

int ceilMaxIndex(vector<int>v, int value) {
	//int l = 0, h = v.size() - 1, m;
	/*while (h - l > 0)
	{
		m = (l + h) / 2;
		if (v[m] < value)
		{
			l = m;
		}
		else
		{
			h = m;
		}
	}*/
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= value)
		{
			return i;
		}
	}
}


int main() {
	int n;
	//ofstream out("t.txt");
	cin >> n;
	while (n--)
	{
		int num, tmp;
		vector<int>in;
		cin >> num;
		if (!num)
		{
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < num; i++)
		{
			cin >> tmp;
			in.push_back(tmp);
		}

		vector<int>tailMax(1, in[num - 1]);
		//vector<int>tailMin();

		/*cout << "\n\n";
		for (int i = 0; i < num; i++) {
			cout << in[i] << " ";
		}
		cout << "\n\n";*/

		for (int i = num - 2; i >= 0; i--)
		{
			if (in[i] < tailMax[0])
			{
				tailMax[0] = in[i];
			}
			else if (in[i] > tailMax.back())
			{
				tailMax.push_back(in[i]);
			}
			else
			{
				tailMax[ceilMaxIndex(tailMax, in[i])] = in[i];
			}

			/*for (int j = 0; j < tailMax.size(); j++)
			{
				cout << tailMax[j] << " ";
			}
			cout << "\n";*/
		}

		for (int i = 0; i < num; i++)
		{
			if (in[i] < tailMax[0])
			{
				tailMax[0] = in[i];
			}
			else if (in[i] > tailMax.back())
			{
				tailMax.push_back(in[i]);
			}
			else
			{
				tailMax[ceilMaxIndex(tailMax, in[i])] = in[i];
			}

			/*for (int j = 0; j < tailMax.size(); j++)
			{
				cout << tailMax[j] << " ";
			}
			cout << "\n";*/
		}
		cout << tailMax.size() << "\n";
	}
	return 0;
}