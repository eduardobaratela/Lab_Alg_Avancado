#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct Triplet{
  int  id, w, iq;
};

vector<Triplet>elephant;
vector<int>dp;
vector<int> prox;

bool cmp(Triplet a, Triplet b){
    if(a.w != b.w) 
        return a.w > b.w;

    return a.iq < b.iq;
}

int main(){
    int count, n = 0, start = -1;
    Triplet aux;

    while(scanf("%d %d",&aux.w, &aux.iq)==2){
        aux.id = ++n;
        elephant.push_back(aux);
        dp.push_back(1);
        prox.push_back(n-1);
    }

    sort(elephant.begin(), elephant.end(), cmp);
    count = 0;

    int tam = elephant.size();
    for (int i = 0; i < tam-1; i++){
        for (int j = i+1; j < tam; j++){
            if(elephant[i].w > elephant[j].w && elephant[i].iq < elephant[j].iq && dp[j] <= dp[i]+1){
                /*if(elephant[i].id == 7 && elephant[j].id == 8)
                    printf("j-%d, i-%d, cnt-%d\n", dp[j], dp[i], count);*/
                dp[j] = dp[i] + 1;
                prox[j] = i;
                if(dp[j] > count){
                    count = dp[j];
                    start = j;
                }
            }
        }
    }

    printf("%d\n", count);
    while(start >= 0){
        printf("%d\n", elephant[start].id);
        start = prox[start];
        if(start == prox[start]){
            printf("%d\n", elephant[start].id);
            break;
        }
    }

    return 0;
}