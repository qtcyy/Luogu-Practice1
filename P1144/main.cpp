#include <bits/stdc++.h>
using namespace std;

const int N = 5000005;
const int mod = 100003;

class Solution{
private:
    int n,m;
    struct node{
        int to,next;
    };
    node que[N];
    int head[N],dis[N];
    bool vis[N];
    int cnt=1,sum[N];
    inline void add(int u,int v){
        que[cnt].to=v;
        que[cnt].next=head[u];
        head[u]=cnt++;
    }

    void spfa(int s){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,false,sizeof(vis));
        memset(sum,0,sizeof(sum));
        queue<int> q;
        q.push(s);
        dis[s]=0;
        vis[s]=1;
        sum[s]=1;
        while (!q.empty()){
            int u=q.front();
            q.pop();
            for (int i=head[u];i!=0;i=que[i].next){
                int k=que[i].to;
                if (dis[k]>dis[u]+1){
                    dis[k]=dis[u]+1;
                    sum[k]=sum[u];
                    if (!vis[k]){
                        vis[k]=1;
                        q.push(k);
                    }
                }
                else if (dis[k]==dis[u]+1){
                    sum[k]+=sum[u];
                    sum[k]%=mod;
                }
            }
        }
    }

public:
    Solution(int n,int m){
        this->n=n;this->m=m;
        memset(head,0,sizeof(head));
        for (int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
    }
    int *getans(){
        spfa(1);
        return sum;
    }
};

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    Solution *sol=new Solution(n,m);
    int *ans=sol->getans();
    for (int i=1;i<=n;i++)
        cout<<*(ans+i)<<endl;

    return 0;
}