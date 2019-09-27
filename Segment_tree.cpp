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
int binaryCal(int dn) {
    if (dn == 0) return 0;
    else return (dn % 2 + 10 * binaryCal(dn / 2));
}

int arr[mx];
int tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    //READ;
    //ROUT;
    //fasterIO();

    int n;
    cin >> n;
    f2(i, n)
            cin>> arr[i];
    init(1, 1, n);

    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;

    update(1, 1, n, 2, 2);
    cout << query(1, 1, n, 2, 2) << endl;

    // cerr<<"Time : "<<(double)clock()/(double)CLOCKS_PER_SEC<<"s\n";
    return 0;
}
