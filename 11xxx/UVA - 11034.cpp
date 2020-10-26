#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t_n, len, m, l_n, result;
	bool lb;
	char str[6];
	queue<int>l;
	queue<int>r;
	cin >> t_n;
	while (t_n--) {
		cin >> len >> m;
		while (m--) {
			cin >> l_n >> str;
			if (str[0] == 'l') {
				l.push(l_n);
			}
			else {
				r.push(l_n);
			}
		}
		len *= 100;
		result = 0;
		lb = true;
		while (true) {
			l_n = 0;
			if (lb && !l.empty()) {
				while (!l.empty() && l.front() + l_n <= len) {
					l_n += l.front();
					l.pop();
				}
			}
			else if (!lb && !r.empty()) {
				while (!r.empty() && r.front() + l_n <= len) {
					l_n += r.front();
					r.pop();
				}
			}
			if (l.empty() && r.empty()) {
				break;
			}
			else {
				lb = !lb;
				result++;
			}
		}
		cout << ++result << "\n";
	}
	system("pause");
	return 0;
}