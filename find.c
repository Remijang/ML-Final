#include <stdio.h>

int main(){
    int n = 17170;
    long double a[19];
    int cnt[19], k, is[19], count[19];
    long double low[19], high[19];
    for(int i = 0; i < 19; ++i) cnt[i] = is[i] = count[i] = 0;
    FILE *fin = fopen("train", "rb");
    for(int i = 0; i < n; ++i){
        int tmp = 0;
        for(int j = 0; j < 19; ++j) fscanf(fin, "%Lf", &a[j]);
        for(int j = 0; j < 19; ++j){
            if(a[j] == (long double)-1.0){
                cnt[j]++, tmp++;
            }
            else is[j]++;
        }
        count[tmp]++;
        for(int j = 0; j < 19; ++j) if(is[j] == 1) low[j] = high[j] = a[j], is[j]++;
        for(int j = 0; j < 19; ++j) if(is[j] >= 1 && a[j] != (long double)-1.0){
            low[j] = low[j] > a[j] ? a[j] : low[j];
            high[j] = high[j] < a[j] ? a[j] : high[j];
        }
    }
    printf("id missing number lowest highest\n");
    for(int i = 0; i < 19; ++i) printf("%d\t%d\t%Lf\t%Lf\n", i, cnt[i], low[i], high[i]);
    printf("missing count\n");
    for(int i = 0; i < 19; ++i) printf("%d ", count[i]);
    fclose(fin);
    return 0 ;
}
