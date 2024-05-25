#include <bits/stdc++.h>
using namespace std;

int t;

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    int n,m;
    while (t--){
        cin>>n>>m;
        vector<priority_queue<int,vector<int>,greater<int>>>g(n+1);
        for (int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            g[u].push(v);
        }
        for (int i=1;i<=n;i++){
            priority_queue<int,vector<int>,greater<int>> q=g[i];
            while (!q.empty()){
                cout<<q.top()<<' ';
                q.pop();
            }
            cout<<'\n';
        }
    }


    return 0;
}