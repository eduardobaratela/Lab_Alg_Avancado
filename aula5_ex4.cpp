#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <bitset>
#include <string.h>
#define N 100000
using namespace std;

bitset<N>check;
bitset<1000001>composto;
vector <long long> prime;
int len;

void sieve(){
    //memset(check, true, sizeof(check));
 
    check.set();
    check[0] = false;
    check[1] = false;
 
    for(int i = 4; i < N; i += 2 ) 
        check[i] = false;
 
    for(int i = 3; i * i <= N; i += 2){
        if(check[i]){
            for(int j = i * i; j < N; j += i) 
                check[j] = false;
        }
    }
 
    prime.push_back (2);
 
    for(int i = 3; i < N; i += 2 ){
        if(check[i] ) 
            prime.push_back (i);
    }
    len = prime.size();
}

void setComposto(long long l, long long u){
    long long start;

    composto.reset();

        for(int i = 0; i < len && prime[i] * prime[i] <= u; i++){
            if(l % prime[i] == 0)
                start = l;
            else
                start = l + (prime[i] - l % prime[i]);

           for(long long j = start; j <= u; j += prime[i]){
                if (j != prime[i])
                    composto.set(j - l);
            }
        }

        if (l == 1)
            composto.set(0);
}

int main(){
    long long l, u, last, menor, maior;
    int flag;

    sieve();

    while(scanf("%lld %lld", &l, &u) == 2){
        long long c1, c2, d1, d2;
        flag = 0;
        last = -1;
        menor = 1000001;
        maior = 0;

        setComposto(l, u);

        for(long long i = l; i <= u; i++){
            if(!composto[i-l]){
                if(last != -1){
                    if(i-last < menor){
                        menor = i-last;
                        c1 = last;
                        c2 = i;
                    }
                    if(i-last > maior){
                        maior = i-last;
                        d1 = last;
                        d2 = i;
                    }
                    last = i;
                    flag = 1;
                }
                last = i;
            }
        }
        if(flag == 0)
            printf("There are no adjacent primes.\n");
        else printf("%lld,%lld are closest, %lld,%lld are most distant.\n", c1, c2, d1, d2);
    }

    return 0;
}