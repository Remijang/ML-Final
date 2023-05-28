#include <stdio.h>

int main(){
    int n = 17170, m = 6315;
    long double x[17170 + 6315][17];
    double y[17170];
    int is[17];
    long double low[17], high[17], diff[17];
    for(int i = 0; i < 17; ++i) is[i] = 0;
    FILE *fin1 = fopen("train", "rb");
    FILE *fin2 = fopen("test", "rb");
    FILE *fout1 = fopen("train.scale", "wb");
    FILE *fout2 = fopen("test.scale", "wb");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 17; ++j) fscanf(fin1, "%Lf", &x[i][j]);
        fscanf(fin1, "%lf", &y[i]);
        if(i == 2071 || i == 6541 || i == 7001 || i == 11356 || i == 7757 || i == 16803 || i == 9384 || i == 12004 || i == 11337) continue;
        for(int j = 0; j < 17; ++j) if(x[i][j] != (long double)-1.0) is[j]++;
        for(int j = 0; j < 17; ++j) if(is[j] == 1) low[j] = high[j] = x[i][j], is[j]++;
        for(int j = 0; j < 17; ++j) if(is[j] > 1 && x[i][j] != (long double)-1.0){
            low[j] = low[j] > x[i][j] ? x[i][j] : low[j];
            high[j] = high[j] < x[i][j] ? x[i][j] : high[j];
        }
    }
    for(int i = n; i < n + m; ++i){
        for(int j = 0; j < 17; ++j) fscanf(fin2, "%Lf", &x[i][j]);
    }
    for(int i = 0; i < 17; ++i) diff[i] = high[i] - low[i];
    for(int i = 0; i < 17; ++i) printf("%Lf %Lf\n", low[i], high[i]);
    fclose(fin1);
    fclose(fin2);
    for(int i = 0; i < n; ++i){
        if(i == 2071 || i == 6541 || i == 7001 || i == 11356 || i == 7757 || i == 16803 || i == 9384 || i == 12004 || i == 11337) continue;
        if(i) fprintf(fout1, "\n");
        for(int j = 0; j < 17; ++j){
            if(j) fprintf(fout1, " ");
            if(x[i][j] != (long double)-1.0) fprintf(fout1, "%Lf", (x[i][j] - low[j]) / diff[j]);
            else fprintf(fout1, "-1.0");
        }
        fprintf(fout1, " %d", (int)y[i]);
    }
    for(int i = n; i < n + m; ++i){
        if(i > n) fprintf(fout2, "\n");
        for(int j = 0; j < 17; ++j){
            if(j) fprintf(fout2, " ");
            if(x[i][j] != (long double)-1.0) fprintf(fout2, "%Lf", (x[i][j] - low[j]) / diff[j]);
            else fprintf(fout2, "-1");
        }
    }
    fclose(fout1);
    fclose(fout2);
    return 0 ;
}
