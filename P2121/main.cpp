#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

class Solution{
private:
    int n,m,k;
    struct csys{
        int x,y,z;
        csys(int x,int y,int z){this->x=x;this->y=y;this->z=z;};
    };
    vector<csys> cdt;
    int f[N];

    inline int find(int x){
        if (f[x]==x) return x;
        return f[x]=find(f[x]);
    }
public:
    Solution(int n,int m,int k){
        this->n=n;
        this->m=m;
        this->k=k;
        for (int i=1;i<=n;i++)
            f[i]=i;
    }
    inline void add(int u,int v,int w){
        cdt.push_back(csys(u,v,w));
    }

    static bool cmp(csys p1,csys p2){
        return p1.z>p2.z;
    }

    int kruskal(){
        sort(cdt.begin(),cdt.end(),cmp);
        int res=0,sum=0;
        for (auto p:cdt){
            int x=find(p.x),y=find(p.y);
            if (x!=y){
                f[x]=y;
                res+=p.z;
                if (++sum==k)
                    return res;
            }
        }
    }
};

signed main(){
    freopen("a.in","r",stdin);
    int n,m,k;
    cin>>n>>m>>k;
    Solution *sol=new Solution(n,m,k);
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        sol->add(u,v,w);
    }
    cout<<sol->kruskal()<<endl;

    return 0;
}