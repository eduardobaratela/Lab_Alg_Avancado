#include<algorithm>
#include<cstdio>
 
using namespace std;
 
int queens[8], path[8];
 
bool valid(int r, int c) {
    for(int j = 0; j < r; j++) {
        if(c == path[j]) 
            return false;
        if(abs(r - j) == abs(c - path[j])) 
            return false;
    }
    
    return true;
}
 
int search(int n) {
    if(n == 8) 
        return 0;

    int proc;
    int total = 100000;
    
    for(int i = 0; i < 8; i++){
        if(valid(n, i)) {
            path[n] = i;
            if(i == queens[n])
                proc = search(n+1);
            else proc = 1+search(n+1);
            
            total = min(total, proc);
        }
    }
 
    return total;
}
 
int main() {
    for(int T = 1;; T++) {
        for(int i = 0; i < 8; i++) {
            if(scanf("%d", &queens[i]) == -1) 
                return 0;

            queens[i]--; 
            path[i] = queens[i];
        }
 
        printf("Case %d: %d\n", T, search(0));
    }
}