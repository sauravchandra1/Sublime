#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 22
int MAX = 1 << N;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec(n + 1);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++) {
			vector<int> seq;
			for (int j = 0; j < n; j++) {
				if (mask & (1 << j)) {
					seq.push_back(vec[j]);
				}
			}
			sort(seq.begin(), seq.end());
		// for (int k = 0; k < (int)seq.size(); k++) 
		// 	cout << seq[k] << " ";
		// cout << endl;
			int seqSize = (int)seq.size();
			if (seqSize & 1) {
				ans++;
			}
			else if (seqSize) {
				int first = seq[seqSize / 2];
				int second = seq[(seqSize - 1) / 2];
				if (first == second)
					ans++;
			}
		}
		cout << ans << endl;	
	}
	return 0;
}