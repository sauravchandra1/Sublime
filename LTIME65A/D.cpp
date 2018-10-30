#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 55
long long num, s;
vector<long long> pos, inv(N + 10), fact(N + 10);
void cal_fact() {
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;
}
long long inverse(long long x) {
	long long y = MOD - 2;
	long long res = 1;
	while(y > 0) {
		if (y & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return res;
}
void cal_inv() {
	for (int i = 0; i < N; i++) {
		inv[i] = inverse(fact[i]);
	}
}
long long nCr(long long n, long long r) {
	return (fact[n] % MOD * (inv[n - r] % MOD * inv[r] % MOD) % MOD) % MOD;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cal_fact();
	cal_inv();
	int t;
	cin >> t;
	while (t--) {
		pos.clear();
		cin >> num >> s;
		int x, k = 0;
		for (int i = 0; i < num; i++) {
			cin >> x;
			if (x == -1) 
				k = k + 1;
			else
				pos.push_back(x);
		}
		if (num == 1) {
			cout << "0" << endl;
			continue;
		}
		long long sum = 0;
		for (int i = 0; i < (int)pos.size(); i++) 
			sum += pos[i];
		if (k == 0 && sum != s) {
			cout << "0" << endl;
			continue;
		}
		sum = s - sum;
		if (sum < k) {
			cout << "0" << endl;
			continue;
		}
		long long hcf;
		if (k == 1) {
			pos.push_back(sum);
			long long ans = 0;
			for (int i = 0; i < (int)pos.size(); i++) {
				for (int j = i + 1; j < (int)pos.size(); j++) {
					hcf = __gcd(pos[i], pos[j]);
					ans = (ans % MOD + hcf % MOD) % MOD;
				}
			}
			cout << ans << endl;
			continue;
		}
		long long pos_ans = 0;
		for (int i = 0; i < (int)pos.size(); i++) {
			for (int j = i + 1; j < (int)pos.size(); j++) {
				hcf = __gcd(pos[i], pos[j]);
				pos_ans = (pos_ans % MOD + hcf % MOD) % MOD;
			}
		}
		long long n, r;
		n = sum - 1;
		r = k - 1;
		long long tot_sq;
		if (n <= 0 || r <= 0)
			tot_sq = 1;
		else 
	 		tot_sq = nCr(n, r);
		pos_ans = (pos_ans % MOD * tot_sq % MOD) % MOD;
		long long col_ans = 0, occurrence, tmp;
		for (long long i = 1; i <= sum - (k - 1); i++) {
			tmp = 0;
			n = sum - i - 1;
			r = k - 2;
			if (n <= 0 || r <= 0) 
				occurrence = 1;
			else
				occurrence = nCr(sum - i - 1, k - 2);
			for (int j = 0; j < (int)pos.size(); j++) {
				hcf = __gcd(i, pos[j]);
				tmp = (tmp % MOD + hcf % MOD) % MOD;
			}
			tmp = (tmp % MOD * occurrence % MOD) % MOD;
			col_ans = (col_ans % MOD + tmp % MOD) % MOD;
		}
		col_ans = (col_ans % MOD * k % MOD) % MOD;
		long long neg_ans = 0;
		if (k == 2) {
			for (long long i = 1; i <= sum - 1; i++) {
				hcf = __gcd(i, sum - i);
				neg_ans = (neg_ans % MOD + hcf % MOD) % MOD;
			}
		}
		else {
			long long tmp;
			for (int i = 1; i <= sum - (k - 1); i++) {
				for (int j = 1; j <= sum - k - i + 2; j++) {
					n = sum - (i + j) - 1;
					r = k - 3;
					if (n <= 0 || r <= 0)
						occurrence = 1;
					else
						occurrence = nCr(n, r);
					hcf = __gcd(i, j);
					tmp = (hcf % MOD * occurrence % MOD) % MOD;
					neg_ans = (neg_ans % MOD + tmp % MOD) % MOD;
				}
			}
		}
		if (k >= 2)
			neg_ans = (neg_ans % MOD * ((k * (k - 1LL)) / 2LL) % MOD) % MOD;
		long long ans = (pos_ans % MOD + col_ans % MOD + neg_ans % MOD) % MOD;
		cout << ans << endl;
	}
	return 0;
}