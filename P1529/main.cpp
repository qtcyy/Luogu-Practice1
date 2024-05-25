#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n;

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
    q.push({0,s});
    dis[s]=0;
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=0;i=que[i].next){
            int k=que[i].to;
            if (dis[k]>dis[u]+que[i].s){
                dis[k]=dis[u]+que[i].s;
                q.push({dis[k],k});
            }
        }
    }
}

void spfa(int s){
    memset(vis,false,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for (int i=head[u];i!=0;i=que[i].next){
            int k=que[i].to;
            if (dis[k]>dis[u]+que[i].s){
                dis[k]=dis[u]+que[i].s;
                if (!vis[k]){
                    vis[k]=1;
                    q.push(k);
                }
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin>>n;
    vector<char> loc;
    for (int i=1;i<=n;i++){
        char u,v;int w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
        if (u>='A' && u<='Y')
            loc.push_back(u);
        if (v>='A' && v<='Y')
            loc.push_back(v);
    }
    dij('Z');
    char ans;int minn=0x3f3f3f3f;
    for (auto &p:loc)
        if (dis[p]<minn){
            minn=dis[p];
            ans=p;
        }
    cout<<ans<<' '<<minn<<endl;

    return 0;
}