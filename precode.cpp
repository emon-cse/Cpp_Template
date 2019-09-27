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

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
  return (a / gcd(a, b)) * b;
}
int x;
int i = 1;
void bi(int a){
        if(a==0)
            return;
        bi( a >> 1 );
        x += ( a & ( 1 ) );
        x *= i+=10;
}

int main()
{
    int n;
    cin >> n;

    bi(n);
    cout << x << endl;

    return 0;
}
