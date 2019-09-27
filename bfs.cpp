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
#define mx 100000000
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

vector<int>graph[ 100 ];
int visited[ 100 ];

void bfs(int start_node){
    memset(visited, 0, sizeof(visited));
    queue<int>q;

    visited[ start_node ] = 1;
    q.push( start_node );
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        f1( i, graph[ u ].size() ){
            int v = graph[ u ][ i ];
            if( !visited[ v ] ){
                q.push( v );
                visited[ v ] = visited[ u ] + 1;
            }
        }
    }
}


int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    f1( i, edges ){
        int u, v;
        cin >> u >> v;
        graph[ u ].pb( v );
        graph[ v ].pb( u );
    }
    int start_node, end_node;
    cin >> start_node >> end_node;
    bfs( start_node );
    cout << visited[ end_node ] - 1 << endl;


    return 0;
}
