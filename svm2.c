#include <stdio.h>

int main(){
    int n = 6315;
    long double x[n][18];
    int is[18];
    long double low[18], high[18];
    for(int i = 0; i < 18; ++i) is[i] = 0;
    FILE *fin = fopen("test", "rb");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 18; ++j) fscanf(fin, "%Lf", &x[i][j]);
        for(int j = 0; j < 18; ++j) if(x[i][j] != (long double)-1.0) is[j]++;
        for(int j = 0; j < 18; ++j) if(is[j] == 1) low[j] = high[j] = x[i][j], is[j]++;
        for(int j = 0; j < 18; ++j) if(is[j] >= 1 && x[i][j] != (long double)-1.0){
            low[j] = low[j] > x[i][j] ? x[i][j] : low[j];
            high[j] = high[j] < x[i][j] ? x[i][j] : high[j];
        }
    }
    fclose(fin);
    long double d[18];
    for(int i = 0; i < 18; ++i) d[i] = (high[i] + low[i]) / 2;
    FILE *fout = fopen("mean2", "wb");
    for(int i = 0; i < n; ++i){
        if(i) fprintf(fout, "\n");
        fprintf(fout, "+1 ");
        for(int j = 1; j < 18; ++j){
            if(x[i][j] == (long double)-1.0) fprintf(fout, "%d:%Lf ", j, d[j]);
            else fprintf(fout, "%d:%Lf ", j, x[i][j]);
        }
    }
    fclose(fout);
    return 0 ;
}
