#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

map<string,string> f;

inline string find(string x){
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

inline void merge(string x,string y){
    x=find(x);
    if (x!=y)
        f[y]=x;
}

signed main(){
    freopen("a.in","r",stdin);
    string now;
    while (1){
        char c;string s;
        cin>>c>>s;
        if (f.find(s)==f.end())
            f[s]=s;
        if (c=='#'){
            now=s;
        }
        else if (c=='+')
            merge(now,s);
        else if (c=='?'){
            find(s);
            cout<<s<<' '<<f[s]<<endl;
        }
        else if (c=='$')
            break;
    }

    return 0;
}