#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define mx 1000005
#define vi vector<int>
#define vs vector<string>
#define READ freopen("in.txt", "r", stdin)
#define ROUT freopen("out.txt", "w", stdout)
using namespace std;

int arr[mx];
struct info {
    int prop, sum;
} tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].sum = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    //READ;
    //ROUT;
    //fasterIO();

    int n;
    cin >> n;
//    f2(i, n)
//            cin>> arr[i];
    init(1, 1, n);

    update(1, 1, n, 2, 4, 2);
    cout << query(1, 1, n, 1, 3) << endl;

    update(1, 1, n, 2, 4, -2);
    cout << query(1, 1, n, 1, 2) << endl;

    // cerr<<"Time : "<<(double)clock()/(double)CLOCKS_PER_SEC<<"s\n";
    return 0;
}
