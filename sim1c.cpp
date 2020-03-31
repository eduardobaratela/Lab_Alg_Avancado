#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
vector<int> ans, lista;
int maior;

void dfs(int i, int soma,int cd[20], int n, int t){
    if(i>=t || soma >= n){
        if(soma>maior && soma<=n){
            ans = lista;
            maior = soma;
        }
        return;
    }

    lista.push_back(cd[i]);
    dfs(i+1, soma+cd[i], cd, n, t); //incluindo a musica atual
    lista.pop_back();
    dfs(i+1, soma, cd, n, t); //sem incluir a musica atual
}

int main(){
    int n, t, soma;

    while(cin>>n){
        int cd[20];
        maior = 0;
        cin>>t;
        for(int i=0; i<t; i++){
            cin>>cd[i];
        }
        dfs(0, 0,cd, n, t);
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<"sum:"<<maior<<endl;
    }    

    return 0;
}