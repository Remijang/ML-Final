#include <bits/stdc++.h>

using namespace std;

long double x[17170][17];
double y[17170];
long double gam = 1.0;

long double dis(int a, int b){
    long double diss = 0.0;
    for(int i = 0; i < 17; ++i) diss += (x[a][i] - x[b][i]) * (x[a][i] - x[b][i]);
    //return exp(-gam * diss);
    return sqrtl(diss);
}


int main(){
    FILE *fin = fopen("train", "rb");
    int tmp;
    for(int i = 0; i < 17170; ++i){
        fscanf(fin, "%d", &tmp);
        for(int j = 0; j < 17; ++j) fscanf(fin, "%Lf", &x[i][j]);
        fscanf(fin, "%lf", &y[i]);
    }
    fclose(fin);
    srand(time(NULL));
    int choose[17170];
    for(int i = 0; i < 17170; ++i) choose[i] = i;
    for(int i = 0; i < 17170; ++i) swap(choose[i], choose[i + rand() % (17170 - i)]);
    long double kernel[10][17];
    for(int i = 0; i < 10; ++i){
        for(int u = 0; u < 10; ++u){
            for(int v = 0; v < 17; ++v) kernel[u][v] = 0.0;
        }
        int cnt[17] = {};
        for(int j = 0; j < 1717; ++j){
            int idx = choose[i * 1717 + j];
            for(int k = 0; k < 17; ++k) if(x[idx][k] != -1) kernel[(int)y[idx]][k] += x[idx][k], cnt[k]++;
        }
        for(int u = 0; u < 10; ++u){
            for(int v = 0; v < 17; ++v){
                kernel[u][v] /= cnt[v];
                if(u == 0) printf("%.7Lf ", kernel[u][v]);
            }
        }
        cout << endl;
    }
    return 0;
}
