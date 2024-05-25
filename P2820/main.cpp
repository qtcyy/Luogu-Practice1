#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct csys{
    int x,y,z;
    csys(int x,int y,int z){this->x=x;this->y=y;this->z=z;};
};

int n,k;
vector<csys> cdt;
int f[N];

inline int find(int x){
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

bool cmp(csys p1,csys p2){
    return p1.z<p2.z;
}

signed main(){
    freopen("a.in","r",stdin);
    cin>>n>>k;
    for (int i=1;i<=n;i++) f[i]=i;
    int res=0,ans=0,sum=0;
    for (int i=1;i<=k;i++){
        int x,y,z;
        cin>>x>>y>>z;
        cdt.push_back(csys(x,y,z));
        res+=z;
    }
    sort(cdt.begin(),cdt.end(),cmp);
    for (auto p:cdt){
        if (p.z==0) continue;
        int x=find(p.x),y=find(p.y);
        if (x!=y){
            f[x]=y;
            ans+=p.z;
            if (++sum==n-1)
                break;
        }
    }
    cout<<res-ans<<endl;

    return 0;
}