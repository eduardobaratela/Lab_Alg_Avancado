#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int main() {
    char c;
    long long resp = 0;

    while(1){
        if(scanf("%c",&c)==EOF)
            break;

        if(c == '1' || c == '0') {
            resp = ((resp*2)+c-'0') % 131071;
        }
        else if(c == '#' ){
            if(resp)
                printf("NO\n");
            else printf("YES\n");
            resp = 0;
        }
    }

    return 0;
}