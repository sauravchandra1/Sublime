#include<bits/stdc++.h>
#include<vector>
#define mod 1000000007
#define int long long
using namespace std;
int sum;
int size;
int arr[52];
int n;
vector<int>ans;
int ans_f=0;
int nCr(int n, int r) 
{ 
  int p = mod;
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
int base(vector<int> &ans)
{
  vector<int>vec;
  int c=1;
  for(int i=1;i<ans.size();i++)
  {
    if(ans[i] == ans[i-1])
    {
      c++;
    }
    else
    {
      vec.push_back(c);
      c = 1;
    }
    
  }
  if(vec.size() != 0)
  vec.push_back(c);
  /**for(int i=0;i<vec.size();i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;**/
  int temp_size = ans.size();
  int t= 1;
  for(int i=0;i<vec.size();i++)
  {
    //cout<<temp_size<<" "<<vec[i]<<endl;
    t = (t* nCr(temp_size,vec[i]))%mod;
    temp_size -= vec[i];
  }
  return t;
}
int gcd(int arr1[],int n)
{
  //cout<<"n "<<n<<endl;
  /**for(int i=0;i<n;i++)
  {
    cout<<arr1[i]<<" ";
  }
  cout<<endl;**/
  int p=0;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      p = (p+ __gcd(arr1[i],arr1[j]))%mod;
    }
  }
  return p;
}
void dfs(int sum1,int size1)
{
  //cout<<sum1<<" "<<size1<<endl;
  //cout<<sum<<" "<<size<<endl;
  //return;
  if(sum1 > sum || size1 > size)
  {
    return ;
  }
  if(sum1 == sum && size1 == size )
  {
    int temp[n];
    for(int i=0;i<n;i++)
    {
      temp[i] = arr[i];
    }
    int j=0;
    for(int i=0;i<n;i++){
      if(arr[i]==-1)
      {
        temp[i] = ans[j++];
      }
    }
    /**for(int i=0;i<ans.size();i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<endl;**/
    int k = gcd(temp,n)%mod;
    int m = base(ans)%mod;
    int o = (k*m)%mod;
    ans_f = (ans_f + o)%mod;
    return;
  }
  else
  {
    int l;
    if(ans.size() ==0)
    {
      l = 1;
    }
    else
    {
      l = ans[ans.size()-1];
    }
    for(int i=l;i<sum-sum1+1;i++)
    {
      ans.push_back(i);
      dfs(sum1+i,size1+1);
      ans.pop_back();
    }
    }
}
main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //freopen("input.txt","rt",stdin);
  int t;
  cin>>t;
  while(t--)
  {
    ans_f =0;
    cin>>n>>sum;
    vector<int>a;
    vector<int>b;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      if(arr[i]==-1)
      {
        a.push_back(arr[i]);
      }
      else
      {
        sum -= arr[i];
        b.push_back(arr[i]);
      }
    }
      size = a.size();
      dfs(0,0);
      cout<<ans_f<<endl;
    
  }
}