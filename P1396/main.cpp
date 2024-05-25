#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

struct csys{
    int x,y,z;
};
csys cdt[N];

int n,m,s,t;
int f[N];

bool cmp(csys p1,csys p2){
    return p1.z<p2.z;
}

inline int find(int x){
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

signed main(){
    freopen("a.in","r",stdin);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cdt[i]={u,v,w};
    }
    sort(cdt+1,cdt+m+1,cmp);
    for (int i=1;i<=n;i++)
        f[i]=i;
    for (int i=1;i<=m;i++){
        int x=find(cdt[i].x),y=find(cdt[i].y);
        if (x!=y)
            f[x]=y;
        if (find(s)==find(t)){
            cout<<cdt[i].z<<endl;
            break;
        }
    }


    return 0;
}