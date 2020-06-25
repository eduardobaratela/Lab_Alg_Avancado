#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector< vector<long long> > a(500005);
long long vis[500005];
long long spread[500005];
long long user;

long long dfs(long long c){
    vis[c] = user;
    long long cnt = 1;
    long long tam = a[c].size();

    for(long long i = 0; i < tam; i++)
        if(!vis[a[c][i]])
            cnt += dfs(a[c][i]);

    return cnt;
}

int main(){
    long long n, m, k;

    cin>>n>>m;
    memset(vis, 0, sizeof(vis));

    for(long long i = 0; i < m; i++){
        long long x, y;
        cin>>k;
        if(k == 0) continue;
        else{
            cin>>x;
            for(long long i = 0; i < k-1; i++){
                cin>>y;
                a[x].push_back(y);
                a[y].push_back(x);
            }
        }
    }

    user = 1;
    for(long long i = 1; i <= n; i++){
        if(!vis[i]){
            spread[user] = dfs(i);;
            user++;
        }
        cout<<spread[vis[i]]<<" ";
    }
    printf("\n\n");

    return 0;
}