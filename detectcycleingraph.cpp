#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln "\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    //cerr << '[' << endl;
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) cerr << "[ ]" << endl
#endif
#define pi  pair<int,int>
bool detectcycle(int node,vector<vector<ll>>&adj,vector<int>vis,vector<int>dfsvis,int n)
{
    vis[node]=1;
    dfsvis[node]=1;
    for(auto x:adj[node])
    {   
        if(!vis[x])
        {
        if(detectcycle(x,adj,vis,dfsvis,n)) return true;
        else if(dfsvis[x]) return true;
        }
    }
    dfsvis[node]=0;
    return false;
}
bool isCycle(vector<vector<ll>>&adj,int n)
{
    vector<int>vis(n,0),dfsvis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(detectcycle(i,adj,vis,dfsvis,n)) return true;
        }
    }
    return false;
}
void solve(){   
 int n,m;
  cin>>n>>m;
  vector<vector<ll>>adj;
adj.resize(n);
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    --u;
    --v;
      adj[u].push_back(v);
    if(isCycle(adj,n)) cout<<"YES"<<ln;
    else cout<<"NO"<<ln;
}
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}