#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

class Solution{
private:
    int n,m;
    struct csys{
        int x,y,z;
        csys(int x,int y,int z){this->x=x;this->y=y;this->z=z;};
    };
    int f[N];
    vector<csys> cdt;

    inline int find(int x){
        if (f[x]==x) return x;
        return f[x]=find(f[x]);
    }
    
    static bool cmp(csys p1,csys p2){
        return p1.z<p2.z;
    }
public:

    Solution(int n,int m){
        this->n=n;
        this->m=m;
    }
    void add(int u,int v,int w){
        cdt.push_back(csys(u,v,w));
    }

    int kruskal(){
        for (int i=1;i<=n;i++)
            f[i]=i;
        sort(cdt.begin(),cdt.end(),cmp);
        int res=0,sum=0;
        for (auto p:cdt){
            int x=find(p.x),y=find(p.y);
            if (x!=y){
                f[x]=y;
                res+=p.z;
                if (++sum==n)
                    break;
            }
        }
        return res;
    }
};

signed main(){
    freopen("a.in","r",stdin);
    int n,m;
    cin>>n>>m;
    Solution *sol=new Solution(n,m);
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        sol->add(u,v,w);
    }
    cout<<sol->kruskal()<<endl;

    return 0;
}