#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

typedef long long int lli;

lli FACT[60];
lli invFACT[60];

lli GCD(lli a,lli b)
{
   if(b==0)
        return a;
   return ( GCD(b,a%b));
}


lli power(lli x,lli y)
{
        lli result=1;
        x=x%M;

        while(y>0)
        {
                if(y&1)
                        result=(result%M * x%M)%M;
                y=y/2;
                x=(x*x)%M;
        }

        return result;
}

void fillFACT()
{
        FACT[0]=1;
        invFACT[0]=power(FACT[0],M-2);
        for(int i=1;i<60;i++)
        {
       FACT[i]=((FACT[i-1]%M)*(i%M))%M;
       invFACT[i]=power(FACT[i],M-2);
        }
}

lli nCr(lli n,lli r)
{
    lli result=1;

    result=FACT[n];

    result= ((result%M)*(invFACT[n-r]%M))%M;

    result=((result%M)*(invFACT[r]%M))%M;

    return result;
}
//###################################################################


lli prr[100];
lli N,np,nm;
lli TS,PS,S,K;
lli Tpp,Tnp,Tnn;
lli ans;

//-------------------------------------------------------
lli funPP()
{
        lli result=0;

        if(np>=2)
        {
           for(int i=0;i<np-1;i++)
           {
                  for(int j=i+1;j<np;j++)
                  {
              result=(result%M + GCD(prr[i],prr[j])%M )%M;
                  }
           }
        }
        if (nm >= 1)
                result= ( (result%M) * ( nCr(S-1,nm-1) %M ))%M;

        return result;
}

//--------------------------------------------------------

lli funNP()
{
        lli result=0;  lli SR=0;  lli Temp;

        if(nm==1 && np>0)
        {
        for(int i=0;i<np;i++)
        {
                result= ( (result%M) + ( GCD(S,prr[i]) %M))%M;
        }
        }

        //----

        else if(nm>=2 && np>0)
        {
        for(int i=1;i<=K;i++)
        {
                Temp=0;
            for(int j=0;j<np;j++)
            {
                Temp= (Temp%M + GCD(i,prr[j])%M )%M;
            }

            SR=( (SR%M) + ( (nCr(S-i-1 ,nm-2)%M)*(Temp%M))%M )%M;
        }

        result= ( (SR%M)*(nm%M))%M;
        }

        else
                result=0;


        return result;
}

//--------------------------------------------------------

lli funNN()
{
        lli result=0;  lli Temp;

        if(nm>=3)
        {
                for(int i=1;i<=K;i++)
                {
                        for(int j=1;j<=(K-i+1);j++)
                        {
                                Temp=( (((GCD(i,j)%M )*( nCr( (S-(i+j)-1) , nm-3 )%M))%M) * (nCr(nm,2) %M))%M;
                                result=(result%M + Temp%M)%M;
                        }
                }
        }

        //----

        else if(nm==2)
        {
        for(int i=1;i<S;i++)
        {
                result=( (result%M) + (GCD(i,S-i) %M) )%M;  
        }
        }

        //----

        else
                result=0;

        return result;
}

//-------------------------------------------------------

int main()
{
        fillFACT();

        int test;  lli X;
        cin>>test;

        while(test--)
        {
                cin>>N>>TS;
                np=0; nm=0;  PS=0; 

                for(int i=0;i<N;i++)
                {
           cin>>X;
           if(X==-1)
                nm++;

           else
           {
                prr[np++]=X;
                PS+=X;
            }
                }

                S=TS-PS;
                K=S-nm+1;

                // for(int i=0;i<np;i++)
                //      cout<<prr[i]<<" ";
                // cout<<endl;

  //       cout<<np<<" "<<nm<<" "<<S<<endl;
                //------------------------

                if(N==1)
                {
                        cout<<0<<endl;
                        continue;
                }

                if (nm == 0 && PS != TS) {
                        cout << "0" << endl;
                        continue;
                }

                if(PS>TS)
                {
                        cout<<0<<endl;
                        continue;
                }

                if(S<nm)
                {
                        cout<<0<<endl;
                        continue;
                }

                //-------------


          Tpp=funPP();   //cout<<Tpp<<endl;
         Tnp=funNP();   //cout<<Tnp<<endl;
         Tnn=funNN();   //cout<<Tnn<<endl;

         ans=( ((Tpp%M)+(Tnp%M))%M + Tnn%M )%M;

         cout<<ans<<endl;
                
        }
        return 0;
}