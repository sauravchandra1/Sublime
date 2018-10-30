#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int m = (int) 1e9 + 7;
inline int power(int a) {
	int ans = 1, b = m - 2;
	while (b) {
		if (b & 1) {
			ans = 1L * ans * a % m;
		}
		a = 1L * a * a % m;
		b >>= 1;
	}
	return ans;
}
inline void preprocessing(int *fact, int *modInverse) {
	fact[0] = fact[1] = modInverse[0] = modInverse[1] = 1;
	for (int i = 2; i < 51; i++) {
		fact[i] = 1L * i * fact[i - 1] % m;
		modInverse[i] = power(fact[i]);
	}
}
inline int gcd(int a, int b) {
	int y;
	while (true) {
		if (!b) {
			return a;
		}
		y = b;
		b = a % b;
		a = y;
	}
}
inline int nice(vector<int> &arr) {
	int ans = 0, n = (int) arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += gcd(arr[i], arr[j]);
		}
	}
	return ans;
}
void recurSolve(int i, vector<int> v, int n, int c, int s, vector<vector<int>> &ways) {
	if (i == n) {
		if (c == s) {
			ways.push_back(v);
		}
	} else {
		int k = v.empty() ? 1 : v.back();
		for (int j = k; j < 51; j++) {
			if (c + j + n - 1 - i <= s) {
				v.push_back(j);
				recurSolve(i + 1, v, n, c + j, s, ways);
				v.pop_back();
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, fact[51], modInverse[51], arr[50];
	preprocessing(fact, modInverse);
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		vector<int> val;
		vector<vector<int>> ways;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] != -1) {
				val.push_back(arr[i]);
			}
		}
		int ans = 0;
		recurSolve(0, vector<int>(), n, 0, s, ways);
		for (vector<int> &x : ways) {
			unordered_map<int, int> count;
			for (int y : x) {
				count[y]++;
			}
			bool poss = true;
			for (int y : val) {
				if (count.find(y) == count.end() || !count[y]) {
					poss = false;
					break;
				}
				count[y]--;
			}
			if (!poss) {
				continue;
			}
			int curWays = fact[n - val.size()];
			for (pair<const int, int> &y : count) {
				if (y.second) {
					curWays = 1L * curWays * modInverse[y.second] % m;
				}
			}
			ans = (ans + 1L * curWays * nice(x)) % m;
		}
		cout << ans << '\n';
	}
	return 0;
}
