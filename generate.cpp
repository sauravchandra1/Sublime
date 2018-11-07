#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "w", stdout);
	srand(time(NULL));
	int t = 12;
	cout << t << endl;
	while (t--) {
		int n = rand() % 12 + 1;
		cout << n << endl;
		int x;
		for (int i = 0; i < n; i++) {
			x = rand() % 5 + 1;
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}