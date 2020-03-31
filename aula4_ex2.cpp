#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>


using namespace std;

map<vector<int>, string> visit;
queue< vector<int> > q;

void push(vector<int> &v, string &path, char c){
    if (!visit.count(v)){
        q.push(v);
        string nextP = path;
        nextP.insert(nextP.end(), c);
        visit[v] = nextP;
    }
}

int main(){
    vector<int> now;
    for (int i = 1; i <= 9; i++)
        now.push_back(i % 9);
    visit[now] = "";
    q.push(now);
    while (!q.empty()){
        now = q.front();
        string path = visit[now];
        q.pop();

        int index;
        for (index = 0; index < 9; index++)
            if (!now[index]) break; // find the empty slot
        if (index % 3 != 2){
            vector<int> nextNum = now;
            swap(nextNum[index], nextNum[index + 1]);
            push(nextNum, path, 'l');
        }
        if (index % 3){
            vector<int> nextNum = now;
            swap(nextNum[index], nextNum[index - 1]);
            push(nextNum, path, 'r');
        }
        if (index > 2){
            vector<int> nextNum = now;
            swap(nextNum[index], nextNum[index - 3]);
            push(nextNum, path, 'd');
        }
        if (index < 6){
            vector<int> nextNum = now;
            swap(nextNum[index], nextNum[index + 3]);
            push(nextNum, path, 'u');
        }
    } // finished construct path
    printf("vai agora entao");
    int T;
    scanf("%d", &T);
    char lixo;
    lixo = getchar();
    printf("lixo = %d", lixo);
    lixo = getchar();
    printf("lixo = %d", lixo);
    lixo = getchar();
    printf("lixo = %d", lixo);

    for(int j=0; j<T; j++){
        lixo = getchar();
        printf("lixo = %d", lixo);

        char temp[20];
        fgets(temp, 20, stdin);
        printf("%s", temp);
        
        vector<int> resp;
        for (int i = 0; i < 20; i++){
            
            printf("char = %c\n", temp[i]);
            if (temp[i] > '0' && temp[i] <= '9') 
                resp.push_back(temp[i] - '0');
            else if (temp[i] == 'x') 
                resp.push_back(0);
        }

        bool find = visit.count(resp);
        if (find){
            string path = visit[resp];
            reverse(path.begin(), path.end());
            printf("%s\n", path.c_str());
        }
        else{
            printf("unsolvable");
        }
    }

    return 0;
}