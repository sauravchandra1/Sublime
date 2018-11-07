#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll max(ll a, ll b) {
    if(a>b) return a;
    return b;
}
ll min(ll a, ll b) {
    if(a>b) return b;
    return a;
}

ll f[1001], inv[1001];
ll cr[1001][1001];
ll p = 1000000007;

ll power(ll x, ll y, ll p) 
{ 
	ll res = 1;	 // Initialize result 

	x = x % p; // Update x if it is more than or 
				// equal to p 

	while (y > 0) 
	{ 
		// If y is odd, multiply x with result 
		if (y & 1) 
			res = (res*x) % p; 

		// y must be even now 
		y = y>>1; // y = y/2 
		x = (x*x) % p; 
	} 
	return res; 
} 

// Returns n^(-1) mod p 
ll modInverse(ll n, ll p) 
{ 
	return power(n, p-2, p); 
} 

// Returns nCr % p using Fermat's little 
// theorem. 
void precompute() 
{ 
    f[0] = 1;
    inv[0] = modInverse(f[0], p);
    for(ll i=1;i<=1000;i++) {
        f[i] = (i*f[i-1])%p;
        inv[i] = modInverse(f[i], p);
    }
	cr[0][0] = 1;
	for(ll i=1;i<=1000;i++) {
	    for(ll j=0;j<=i;j++) {
	        cr[i][j] =  ( ( (f[i]*inv[j]) % p ) * inv[i-j] ) % p;
	    }
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t,k,n;
	scanf("%lld\n", &t); //cin>>t;
	
	precompute();
    
    //cout<<cr[1][1]<<" "<<cr[3][0]<<" "<<cr[3][1]<<" "<<cr[3][2]<<" "<<cr[10][2]<<endl;
    
	while(t--) {
	   ll ans = 0;
	   scanf("%lld\n", &n); //cin>>n;
	   ll a[1005];
	   ll count[2002], pf[2002];
	   for(ll i=0;i<2002;i++) {
	       count[i] = pf[i] = 0;
	   }
	   for(ll i=0;i<n;i++) {
	       scanf("%lld ", &a[i]); //cin>>a[i];
	       count[ a[i] ]++ ;
	       pf[ a[i] ]++ ;
	   }
	   for(ll i=1;i<2002;i++) {
	       pf[i] += pf[i-1];
	   }
	   for(ll i=1;i<=n; i+=2) {
	       ans = (ans + cr[n][i] ) % p ;
	   }
	   //cout<<ans<<endl;
	   ll vec[1000], vs=0;
	   for(ll i=1; i<=2000;i++) {
	   		if(count[i] > 1) {
	   			vec[vs++] = i;
	   		}
	   		
	   }
	   for(ll ii=0;ii<vs; ii++) {
	   		ll i = vec[ii];
	       if(count[i] > 1) {
	           ll tans, le = pf[i-1], mo = pf[2000]-pf[i] , sl,sr;
	           for(ll k = 0; k<=(count[i]-2); k++) {
	               tans = cr[ count[i] ][k+2];
	               for(ll j=0;j<=k;j++) {
	                   ll o=k-j;
	                   if(j>o) {
	                       sl = 0;  sr = j-o;
	                       if( (le-sl)>=0 && (mo-sr)>=0 )
	                       ans = (ans%p + (tans*( cr[mo+le][le+sr] )%p)%p ) % p;
	                   }
	                   else {
	                       sl = o-j; sr = 0;
	                       if( (le-sl)>=0 && (mo-sr)>=0 )
	                       ans = (ans%p + (tans*( cr[mo+le][mo+sl] )%p )%p ) % p;
	                   }
	                   //ll tl = le, tr = mo;
	                   //cout<<i<<" "<<tl<<" "<<k<<" "<<tr<<endl;
	                   // while( (tl-sl)>=0 && (tr-sr)>=0 ) { //cout<<k<<endl;
	                   //     ans = (ans%p + (((tans*cr[tl][sl])%p)*cr[tr][sr] )%p) % p;
	                   //     sl++;
	                   //     sr++;
	                   // }
	                   //cout<<k<<" "<<ans<<endl;


	               }
	               //cout<<k<<" "<<ans<<endl;
	           }
	   	   }
	   }
	   
	   printf("%lld\n", ans); //cout<<ans<<endl;
	   //cout<<pf[2000]<<" "<<pf[2];
	}
	
	return 0;
}
