#include <cstdio>
using namespace std;

#define N 30001
 
long long w[N];
int coins[5] = {1, 5, 10, 25, 50};
 
int main(){
    int n, c;
 
    for(int i = 1; i < N; i++)
        w[i] = 0;
    w[0] = 1;

    for(int i = 0; i < 5; i++){
        c = coins[i];
        for(int j =  c; j < N; j++){
            w[j] += w[j - c];
            //if(j == 21) printf("%d\n", w[j]);
        }
            
    }
 
    while(scanf("%d", &n) == 1){
        if(w[n] == 1)
            printf("There is only %lld way to produce %d cents change.\n", w[n], n);
        else
            printf("There are %lld ways to produce %d cents change.\n", w[n], n);
    }
    
    return 0;
}