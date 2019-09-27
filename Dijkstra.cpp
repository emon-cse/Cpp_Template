
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define mx 1000005
#define vi vector<int>
#define vp vector<pii>
#define vs vector<string>
#define READ freopen("in.txt", "r", stdin)
#define ROUT freopen("out.txt", "w", stdout)
using namespace std;

const double PI = acos(-1.0);

void fast_cin_cout(){
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
vp G[200];
int distanc[200];
void dijkstra(int source){
    priority_queue<int>q;
    for(int i=0;i<200;i++)distanc[i]=mx;
     q.push(source);
      distanc[source]=0;
      while(!q.empty()){
         int u = q.top();
         q.pop();
         for(int i=0;i<G[u].size();i++){
                int v=G[u][i].first;
                int cost=G[u][i].second;
             if (distanc[u] + cost < distanc[v]){
                       distanc[v] = distanc[u] + cost;
                      q.push(v);
             }
         }
      }
}

int main(){


return 0;
}
