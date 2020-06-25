#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility> 
using namespace std;

//#define INF numeric_limits<int>::max()
#define INF 10000000
typedef pair <int,int> dupla;
typedef pair <dupla,int> tripla;

bool BellmanFord(int n, vector< vector <dupla> > wormhole){
    int cur;
    int dist[1000];
    bool inQ[1000];
    int cycles[1000];

    dist[0] = 0;
    for(int i = 1; i < n; i++)
        dist[i] = INF;
    queue<int> q;
	q.push(0);

    bool change = false;
    while (!change && !q.empty()){
        
        cur = q.front();
		q.pop();
        inQ[cur] = false;
        int tam = wormhole[cur].size();

        for(int j = 0; j < tam; j++){
            int y = wormhole[cur][j].first;
            int t = wormhole[cur][j].second;
            if(dist[cur] + t < dist[y]){   
                //printf("%d+%d-%d\n", dist[x], t, dist[y]);            
	            dist[y] = dist[cur] + t;
                cycles[y] = cycles[cur] + 1;
                if(cycles[y] >= n)
                    return true;
            }
            if(!inQ[y])
                q.push(y);
			    inQ[y] = true;
        }
        
    }
    
    return false;
}


int main() {
    int c, n, m, x, y, t;

    cin >> c;
    for(int i = 0; i < c; i++){
        vector< vector<dupla> > wormhole(1000);

        cin >> n >> m;
        for(int j = 0; j < m; j++) {
            cin >> x >> y >> t;
            wormhole[x].push_back(dupla(y, t));
        }
        //sort(wormhole.begin(), wormhole.end());

        if(BellmanFord(n, wormhole))
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}
