#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "w", stdout);
	srand(time(NULL));
	int t;
	t = rand() % 20 + 1;
	cout << t << endl;
	while (t--) {
		int n, s;
		n = rand() % 8 + 1;
		s = rand() % 50 + 1;
		cout << n << " " << s << endl;
		for (int i = 0; i < n; i++) {
			int tmp = rand() % 10;
			if (tmp < 5)
				cout << "-1 ";
			else 
				cout << tmp << " ";
		}
		cout << endl;
	}
	return 0;
}