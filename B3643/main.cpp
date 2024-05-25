#include <bits/stdc++.h>
using namespace std;

int n,m;
int mp[1005][1005];

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<set<int>> g(n+1);
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        mp[u][v]=mp[v][u]=1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cout<<mp[i][j]<<' ';
        cout<<'\n';
    }
    for (int i=1;i<=n;i++){
        cout<<g[i].size()<<' ';
        for (auto x:g[i])
            cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}