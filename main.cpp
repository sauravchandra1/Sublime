#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD1 1000000009

long long gcd(long long a, long long b) {
    if (b == 0LL)
        return a;
    else 
        return gcd(b, a % b);
}

long long power(long long x, long long y, long long m) 
{ 
    if (y == 0LL) 
        return 1LL; 
    long long p = power(x, y / 2LL, m) % m; 
    p = (p * p) % m; 
    return (y % 2LL == 0)? p : (x * p) % m; 
} 

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n == 1LL) {
            cout << "0 0" << endl;
            continue;
        }
        long long nume1 = (((2LL * (n % MOD) - 3LL + MOD) % MOD) * 2LL) % MOD;
        long long dino1 = (((n % MOD - 1LL + MOD) % MOD) * (n % MOD)) % MOD;
        long long nume2 = (((2LL * (n % MOD1) - 3LL + MOD1) % MOD1) * 2LL) % MOD1;
        long long dino2 = (((n % MOD1 - 1LL + MOD1) % MOD1) * (n % MOD1)) % MOD1;
        long long hcf1 = (nume1 >= dino1 ? gcd(nume1, dino1) : gcd(dino1, nume1));
        long long hcf2 = (nume2 >= dino2 ? gcd(nume2, dino2) : gcd(dino2, nume2));
        nume1 /= hcf1, dino1 /= hcf1;
        nume2 /= hcf2, dino2 /= hcf2;
        long long nume11 = power(nume1, MOD - 2LL, MOD);
        long long nume22 = power(nume2, MOD1 - 2LL, MOD1);
        long long ans1 = (nume11 * dino1) % MOD;
        long long ans2 = (nume22 * dino2) % MOD1;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}