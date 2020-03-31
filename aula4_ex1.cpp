#include <cstdio>
#include <queue>

using namespace std;

struct comb{
    int digit[4];
    int steps;
};

int moves[8][4] = { {1,0,0,0},
					{-1,0,0,0},
					{0,1,0,0},
					{0,-1,0,0},
					{0,0,1,0},
					{0,0,-1,0},
					{0,0,0,1},
					{0,0,0,-1}};

void giraRoda(comb c, comb next[8]){
    for (int i = 0; i < 8; i++){
        next[i].steps = c.steps + 1;
        //printf("next[%d].stepes = %d", i, next[i].steps);
        for (int j = 0; j < 4; j++){
            next[i].digit[j] = c.digit[j] + moves[i][j];
            if(next[i].digit[j] > 9)
                next[i].digit[j] = 0;
            else if(next[i].digit[j] < 0)
                next[i].digit[j] = 9;
        }
    }
}

int compara(comb a, comb b){
    for (int i = 0; i < 4; i++){
        if(a.digit[i] != b.digit[i])
            return 0;
    }
    
    return 1;
}

int BFS(comb atual, comb final, int testados[10][10][10][10]){
    queue<comb> q;
    comb next[8];

    //Checa se estado inicial não é proibido
    if(testados[atual.digit[0]][atual.digit[1]][atual.digit[2]][atual.digit[3]] == 0){
        //Marca estado inicial como testado
        testados[atual.digit[0]][atual.digit[1]][atual.digit[2]][atual.digit[3]] = 1;

        //Começa BFS
        q.push(atual);
        while(!q.empty()){
            atual = q.front();
            q.pop();
            
            //Checa se chegou na combinação desejada
            if(compara(atual, final))
                return atual.steps;

            giraRoda(atual, next);
            //Marca next como testado e adiciona na queue
            for (int i = 0; i < 8; i++){
                if(testados[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]] == 0){
                    testados[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]] = 1;
                    q.push(next[i]);
                }
            }
            
        }
    }

    return -1;
}

int main(){

    int tests, proib;
    comb inicial, final;
    int testados[10][10][10][10];
    int aux[4];

    scanf("%d", &tests);
    for (int i = 0; i < tests; i++){
        scanf("%d %d %d %d", &inicial.digit[0], &inicial.digit[1], &inicial.digit[2], &inicial.digit[3]);
        inicial.steps = 0;

        scanf("%d %d %d %d", &final.digit[0], &final.digit[1], &final.digit[2], &final.digit[3]);

        //Coloca todas as combinações como não visitadas
        for (int i = 0; i < 10; ++i){
			for (int j = 0; j < 10; j++){
				for (int k = 0; k < 10; k++){
					for (int l = 0; l < 10; l++){
						testados[i][j][k][l] = 0;
					}
				}
			}
		}

        //Marca as combinações proibidas
        scanf("%d", &proib);
        for (int i = 0; i < proib; i++){
            scanf("%d %d %d %d", &aux[0], &aux[1], &aux[2], &aux[3]);
            testados[aux[0]][aux[1]][aux[2]][aux[3]] = 1;
        }

        int resp;
        resp = BFS(inicial, final, testados);
        printf("%d\n", resp);   
    }

    return 0;
}