#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>
#define N 10001000
using namespace std;

bool check[N];
vector <long long> prime;

void sieve(){
    memset(check, true, sizeof(check));
 
    check [0] = false;
    check [1] = false;
 
    for(int i = 4; i < N; i += 2 ) 
        check[i] = false;
 
    for(int i = 3; i * i <= N; i += 2){
        if(check[i] ){
            for(int j = i * i; j < N; j += 2*i) 
                check[j] = false;
        }
    }
 
    prime.push_back (2);
 
    for(int i = 3; i < N; i += 2 ){
        if(check[i] ) 
            prime.push_back (i);
    }
}

int solve(int n, int m){
    if (m == 0)
        return false;

    int cnt, cnt2;
    long long tmp;
    int len = prime.size();

    for(int i = 0; i < len && prime[i]*prime[i] <= m; i++){
        if(m%prime[i] == 0){
            cnt = 0;
            while(m%prime[i] == 0){
                cnt++;
                m /= prime[i];
            }
            tmp = prime[i];
            cnt2 = 0;
            while(tmp <= n){
                cnt2 += n/tmp;
                tmp *= prime[i];
            }
            if(cnt2 < cnt)  
                return false;
        }
    }
    if(m != 1 && n < m)
        return false;
    
    return true;
}

int main(){
    int n, m;

    sieve();

    while(scanf("%d %d", &n, &m) == 2){
        if(solve(n, m))
            printf("%d divides %d!\n", m, n);
        else
            printf("%d does not divide %d!\n", m, n);
    }

    return 0;
}