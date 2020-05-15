#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    int km, leak, fuel_cons, s_0;
    double tam_tanque, cur;
    string cmd;
    bool end = false;

    while(end == false){
           cur = 0;
            tam_tanque = 0;
            fuel_cons = 0;
            s_0 = 0;
            leak = 0;
        while(1){
            cin >> km;
            cin >> cmd;
            //cout << km << ' ' << cmd << endl;

            cur += leak * (km - s_0);
            cur += fuel_cons * (km - s_0) / 100.0;
            //printf("cur = %.3lf\n", cur);
            tam_tanque = max(tam_tanque, cur);
            if (cmd[0] == 'G' && cmd[1] == 'o'){
                printf("%.3f\n", tam_tanque);
                break;
            } 
            else if (cmd[0] == 'M') 
                leak = 0;
            else if (cmd[0] == 'G' && cmd[1] == 'a'){
                cin >> cmd;
                cur = 0.0;
            } 
            else if (cmd[0] == 'L') 
                leak++;
            else if (cmd[0] == 'F'){
                cin >> cmd;
                cin >> fuel_cons;
                //cout << 'f' << fuel_cons << endl;
                if(fuel_cons == 0){
                    end = true;
                    break;
                }
            }
		    s_0 = km;
        }
    }

    return 0;
}
