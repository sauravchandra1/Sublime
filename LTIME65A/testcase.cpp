#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "w", stdout);
	srand(time(NULL));
	int t;
	t = rand() % 30 + 1;
	cout << t << endl;
	while (t--) {
		int n, s;
		n = rand() % 50 + 1;
		s = rand() % 44 + 20;
		cout << n << " " << s << endl;
		int x;
		for (int i = 0; i < n; i++) {
			x = rand() % 10 + 1;
			if (x < 5)
				cout << "-1 ";
			else
				cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}