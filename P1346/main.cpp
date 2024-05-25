#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int INF = 0x3f3f3f3f;

struct node{
    int s,to,next;
};
node que[N];

int n;
int head[N],dis[N];
bool vis[N];
int cnt=1;

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dis[s]=0;
    q.push({0,s});
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=que[i].next){
            int k=que[i].to;
            if (dis[k]>dis[u]+que[i].s){
                dis[k]=dis[u]+que[i].s;
                q.push({dis[k],k});
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    memset(head,-1,sizeof(head));
    int s,t;
    cin>>n>>s>>t;
    for (int i=1;i<=n;i++){
        int k;cin>>k;
        for (int j=1;j<=k;j++){
            int t;cin>>t;
            if (j==1)
                add(i,t,0);
            else
                add(i,t,1);
        }
    }
    dij(s);
    cout<<(dis[t]==INF?-1:dis[t])<<endl;

    return 0;
}