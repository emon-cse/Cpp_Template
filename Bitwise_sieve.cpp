//Md. Imran Nazir Emon
//Dept. of Computer Science & Engineering
//University of Asia Pacific
//Email: 18201071@uap-bd.edu

#include<bits/stdc++.h>

#define pf printf
#define sf scanf
#define vint vector<int>
#define vstr vector<string>
#define MX 10e7
#define mx 100001
#define pb push_back
#define SS stringstream
#define HI printf("HI ");
#define PASS printf("PASS");

#define f1(i, a) for(llu i=0; i<(a); i++)
#define f2(i, a) for(int i=1; i<=(a); i++)
#define f3(a, b) for(int i=(a); i<=(b); i++)
#define f4(i, a) for(int i=(a); i>0; i--)
#define test(z, a) for(int z=1; z<=(a); z++)

#define READ freopen("in.txt", "r", stdin)
#define ROUT freopen("out.txt", "w", stdout)

using namespace std;

typedef double db;
typedef long long ll;
typedef unsigned long long llu;
typedef long long ll;

const db PI = acos(-1.0);
const llu MAX = LONG_MAX;

void fasterIO(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int gcd (int num1, int num2) {
    return (num2 == 0) ? num1 : gcd (num2, num1 % num2);
}
int lastDigitSum(llu a, llu b){
    return (a%10)+(b%10);
}
int binaryCal(int dn) { if (dn == 0) return 0; else return (dn % 2 + 10 * binaryCal(dn / 2)); }


bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

int cnt = 1;
long long N = 100000;
int status[(mx/32)+2];
void sieve()
{
	 long long i, j, sqrtN;
     sqrtN = ll( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <= N; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }

	 //puts("2");
	 for(i=3;i<=N;i+=2)
	 if( Check(status[i>>5],i&31)==0) cnt++;
	 	// printf("%d\n",i);
	 	cout << cnt << endl;
}
int main()
{
    sieve();
    return 0;
}


