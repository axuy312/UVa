#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

struct BigNum
{
	vector<long long>num;
};

vector<long long> mul(vector<long long> v, int b) {

	/*cout << v.back() << " ";
	for (int i = v.size() - 2; i >= 0; i--)
	{
		int cnt = 0;
		for (int j = v[i]; j != 0; j /= 10)
		{
			cnt++;
		}
		for (int j = 0; j < 5 - cnt; j++)
		{
			cout << "0";
		}
		cout << v[i] << " ";
	}
	cout << " * " << b << " = ";*/

	bool nb = false;
	if (b < 0)
	{
		nb = true;
		b *= (-1);
	}
	for (int i = 0; i < v.size(); i++)
	{
		v[i] *= b;
	}
	if (nb)
	{
		v[v.size() - 1] *= (-1);
	}
	if (v.back() < 0)
	{
		nb = true;
		v[v.size() - 1] *= (-1);
	}
	else
	{
		nb = false;
	}
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > 99999)
		{
			v[i + 1] += (v[i] / 100000);
			v[i] %= 100000;
		}
	}
	if (v.back() > 99999)
	{
		v.push_back(v.back() / 100000);
		v[v.size() - 2] %= 100000;
	}
	if (nb)
	{
		v[v.size() - 1] *= (-1);
	}
	for (int i = v.size() - 1; i > 0; i--)
	{
		if (v[i] == 0)
		{
			v.pop_back();
			i--;
		}
		else
		{
			break;
		}
	}

	/*cout << v.back() << " ";
	for (int i = v.size() - 2; i >= 0; i--)
	{
		int cnt = 0;
		for (int j = v[i]; j != 0; j/=10)
		{
			cnt++;
		}
		for (int j = 0; j < 5 - cnt; j++)
		{
			cout << "0";
		}
		cout << v[i] << " ";
	}
	cout << "\n\n";*/
	return v;
}

bool bigger(vector<long long>n1, vector<long long>n2) {
	if (n1.back() >= 0 && n2.back() <= 0)
	{
		return true;
	}
	else if (n1.back() <= 0 && n2.back() >= 0)
	{
		return false;
	}
	else if (n1.size() > n2.size())
	{
		if (n1.back() > 0 && n2.back() > 0)
		{
			return true;
		}
		return false;
	}
	else if (n1.size() < n2.size())
	{
		if (n1.back() > 0 && n2.back() > 0)
		{
			return false;
		}
		return true;
	}
	else
	{
		bool nege = false;
		if (n1.back() < 0)
		{
			n1[n1.size() - 1] *= (-1);
			n2[n2.size() - 1] *= (-1);
			nege = true;
		}
		for (int i = n1.size() - 1; i >= 0; i--)
		{
			if (n1[i] > n2[i])
			{
				if (nege)
				{
					return false;
				}
				return true;
			}
			else if (n1[i] < n2[i])
			{
				if (nege)
				{
					return true;
				}
				return false;
			}
		}
		return false;
	}
}

int main() {
	int value;
	while (cin >> value)
	{
		//ofstream cout("t.txt", ios::app);

		if (value == -999999)
		{
			cout << "0\n";

			continue;
		}
		vector<int>Data(1, value);
		vector<BigNum>Min;
		vector<BigNum>Max;
		BigNum tmp;
		int maxI = 0;
		tmp.num.push_back(value);
		Min.push_back(tmp);
		Max.push_back(tmp);
		while (cin >> value && value != -999999) {
			Data.push_back(value);
			tmp.num[0] = value;
			Min.push_back(tmp);
			Max.push_back(tmp);
		}
		int n = Data.size();
		//tmp.num[0] = Data[0];
		for (int i = 1; i < n; i++)
		{
			//cout << "\nTmp: ";
			//tmp.num = mul(tmp.num, Data[i]);
			vector<long long>tmpV;
			tmpV = mul(Max[i - 1].num, Data[i]);
			if (bigger(tmpV, Max[i].num))
			{
				Max[i].num = tmpV;
			}
			if (!bigger(tmpV, Min[i].num))
			{
				Min[i].num = tmpV;
			}
			tmpV = mul(Min[i - 1].num, Data[i]);
			if (bigger(tmpV, Max[i].num))
			{
				Max[i].num = tmpV;
			}
			if (!bigger(tmpV, Min[i].num))
			{
				Min[i].num = tmpV;
			}
			if (bigger(Max[i].num, Max[maxI].num))
			{
				maxI = i;
			}
		}

		cout << Max[maxI].num.back();
		for (int i = Max[maxI].num.size() - 2; i >= 0; i--)
		{
			int cnt = 0;
			for (int j = Max[maxI].num[i]; j >= 10; j /= 10)
			{
				cnt++;
			}
			for (int j = 0; j < 4 - cnt; j++)
			{
				cout << "0";
			}
			cout << Max[maxI].num[i];
		}
		cout << "\n";
	}
	return 0;
}