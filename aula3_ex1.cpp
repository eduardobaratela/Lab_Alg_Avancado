#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int backtracking(vector<int> l, vector<int> pilha, int t, int n, int i, int soma, int ant){
    int perm = 0;

    if(soma == t){
        printf("%d", pilha[0]);
        int size = pilha.size();
        for(int j=1; j<size; j++){
            printf("+%d", pilha[j]);
        }
        printf("\n");

        return 1;
    }
    else if(soma > t)
        return 0;
    else{
        for(int j=i; j<n; j++){     
            //printf("soma = %d\n", soma);  
            /*printf("%d", l[0]);
            for(int k=1; k<pilha.size(); k++){
                printf(" + %d", pilha[k]);
            }
            printf("\n");*/
            if(l[j]!=ant && l[j]<= t){
                soma += l[j];
                pilha.push_back(l[j]);
                perm += backtracking(l, pilha, t, n, j+1, soma, ant);
                //printf("ant = %d / j = %d\n", ant, j);
                ant = l[j];
                soma -= l[j];
                pilha.pop_back();
            }
            /*printf("%d", l[0]);
            for(int k=1; k<pilha.size(); k++){
            printf(" + %d", pilha[k]);
            }
            printf("\n");*/
        }
    }

    return perm;
}

int main(){
    int t;
    int n;

    while(true){
        vector<int> l;
        vector<int> pilha;

        std::cin >> t >> n;
        if(n==0)
            return(0);

        int aux;
        for(int i=0; i<n; i++){
            std::cin >>aux;
            l.push_back(aux);
        }
        std::cout << "Sums of " << t << ":" << std::endl;
        int param = backtracking(l, pilha, t, n, 0, 0, -1);
        if(param == 0)
            printf("NONE\n");
    }

    return(0);
}
