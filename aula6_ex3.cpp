#include <cstdio>

int findgcd(int x, int y){
    if(x % y == 0)
        return y;

    return findgcd(y, x%y);
}

int main() {
    int x, y;

    while(scanf("%d %d", &x, &y) == 2){
        if(findgcd(x, y) == 1)
            printf("%10d%10d    Good Choice\n", x, y);
        else printf("%10d%10d    Bad Choice\n", x, y);
        printf("\n");
    }

    return 0;
}