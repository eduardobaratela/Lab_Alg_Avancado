#include <iostream>
#include <cstring>
#include <cmath>

int quadrado(int n){
    int root = (int)(sqrt(n)+0.5);
    if(n == root * root)
        return 1;

    return 0;
}

int main() {
    int T, N;
    int a[50], ret[50];
    for(N = 1; N <= 50; N++){
        int pecks = 0;
        for(int i = 1; true; i++){
        int ok = 0;
        for(int p = 0; p < N; p++){          
            if(p >= pecks || quadrado(a[p]+i)){
            ok = 1;
            a[p] = i;
            if(p >= pecks)
                pecks++;
            break;
            }
        }

        if(!ok) {
            ret[N-1] = i-1;
            break;
            }
        }
    }

    std::cin >> T;
    for(int cas = 0; cas < T; cas++) {
        std::cin >> N;
        std::cout << ret[N-1] << std::endl;
    }
    return 0;
}