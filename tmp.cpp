#include<iostream>
using namespace std;
long long Mod = 998244353;
long long n,ans,a[200001];
long long dp[100001][201][2];
void get(int i, int j, int k)
{
        cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
}
int main()
{
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        dp[0][0][1] = 1;
        for(int i=1; i<=n; i++) 
        {
                long long sum1 = 0, sum2 = 0;
                for(int j=1; j<=200; j++)
                {
                        sum1 += dp[i-1][j-1][0] + dp[i-1][j-1][1];
                        dp[i][j][0] = sum1;
                        sum1 %= Mod;
                        dp[i][j][0] %= Mod;
                }
                for(int j=200; j>=1; j--)
                {
                        sum2 += dp[i-1][j][1];
                        dp[i][j][1] = dp[i-1][j][0] + sum2;
                        sum2 %= Mod;
                        dp[i][j][1] %= Mod;
                }
                if(a[i] != -1) for(int j=0; j<=200; j++) if(j - a[i]) dp[i][j][0] = 0, dp[i][j][1] = 0;
        }
        for(int i=1; i<=200; i++) ans += dp[n][i][1];
        //for(int i=2; i<=3; i++) for(int j=1; j<=3; j++) for(int k=0; k<2; k++) get(i,j,k);
        cout << ans % Mod;
}