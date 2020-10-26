#include <iostream>
#include <cstring>


using namespace std;

char input[101], target[101], stack[101], output[101];


void dfs(int p_t, int p_i, int p_s, int p_o) {
	if (p_t == strlen(target))
	{
		cout << output[0];
		for (int i = 1; i < p_o; i++)
		{
			cout << ' ' << output[i];
		}
		cout << '\n';
	}
	else
	{
		if (p_i < strlen(input))
		{
			output[p_o] = 'i';
			char t[101];
			for (int i = 0; i < p_s; i++)
			{
				t[i] = stack[i];
			}
			stack[p_s] = input[p_i];
			dfs(p_t, p_i + 1, p_s + 1, p_o + 1);

			for (int i = 0; i < p_s; i++)
			{
				stack[i] = t[i];
			}
		}/*
		for (int i = 0; i < p_o; i++)
		{
			cout << output[i];
		}
		cout << endl;
		for (int i = 0; i < p_s; i++)
		{
			cout << stack[i];
		}
		cout << endl;
		cout << "target: " << p_t << "\ninput: " << p_i << "\nstack: " << p_s << "\noutput: " << p_o << '\n';*/
		if (p_s > 0 && stack[p_s - 1] == target[p_t])
		{
			output[p_o] = 'o';
			dfs(p_t + 1, p_i, p_s - 1, p_o + 1);
		}
	}
}

int main() {
	while (cin >> input >> target)
	{
		cout << "[\n";
		if (strlen(input) == strlen(target))
		{
			dfs(0, 0, 0, 0);
		}
		cout << "]\n";
	}


	
	system("pause");
	return 0;
}