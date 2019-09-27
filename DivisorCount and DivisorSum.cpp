#include<bits/stdc++.h>
#define mx 10000005
#define ll long long
#define pb push_back
using namespace std;
//int prime[ mx ], k = 0;
//long long N = 10e7;
vector<ll>prime;
int status[(mx/32)+2];
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}
void sieve()
{
	 ll i, j, sqrtN;
     sqrtN = (ll)( sqrt( mx-1 ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j < mx; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }

	 prime.pb(2);
	 for( i = 3; i < mx; i += 2)
        if( Check( status[ i >> 5 ], i & 31 ) == 0 ){
            prime.pb(i);
        }
}
ll power(ll a,ll b){
if(b==0)return 1;
else if(b==1)return a;
ll ans=1;
while(b--){
    ans*=a;
}
return ans;
}

ll sum_of_divisor(ll n){
    ll sum=1,cnt,k=n;
    for(int i=0;i<prime.size()&&i*i<n;i++){
        if(n%prime[i]==0){
            cnt=0;
            while(n%prime[i]==0){
                cnt++;
                n/=prime[i];
            }
            sum*=(power(prime[i],cnt+1)-1)/(prime[i]-1);
            //cout<<sum<<endl;
        }
    }
    if(n>1)sum*=n+1;
 return sum;
}
ll countDivisor(ll n) {
  ll divisor = 1;
  for (int i = 0; i < prime.size()&&i*i<n; i++) {
    if (n % prime[i] == 0) {
      ll cnt = 1;
      while (n % prime[i] == 0) {
        n /= prime[i];
        cnt++;
      }
      divisor *= cnt;
    }
  }
  return divisor;
}
int main(){
    sieve();
    int t;
//    for(int i=0;i<20;i++){
//        cout<<prime.size()<<"\t";
//    }
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<countDivisor(n)<<endl;
    }
    return 0;
}
