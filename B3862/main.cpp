#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

struct node{
    int to,next;
};
node que[N];

int head[N],cnt=1;
bool vis[N];

inline void add(int u,int v){
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

int bfs(int u){
    queue<int> q;
    memset(vis,false,sizeof(vis));
    q.push(u);
    vis[u]=1;
    int v=u;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int i=head[u];i!=0;i=que[i].next){
            int k=que[i].to;
            v=max(v,k);
            if (!vis[k]){
                vis[k]=1;
                q.push(k);
            }
        }
    }
    return v;
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    for (int i=1;i<=n;i++){
        cout<<bfs(i)<<' ';
    }
    cout<<endl;

    return 0;
}