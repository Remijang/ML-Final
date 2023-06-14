#include <stdio.h>

int main(){
    int n = 17170;
    long double a[18];
    int cnt[18], k, is[18], count[18];
    long double low[18], high[18];
    for(int i = 0; i < 18; ++i) cnt[i] = is[i] = count[i] = 0;
    FILE *fin = fopen("train", "rb");
    for(int i = 0; i < n; ++i){
        int tmp = 0;
        for(int j = 0; j < 18; ++j) fscanf(fin, "%Lf", &a[j]);
        for(int j = 0; j < 18; ++j) if(j != 13 && j != 14 && j != 15){
            if(a[j] == (long double)-1.0){
                cnt[j]++, tmp++;
            }
        }
        count[tmp]++;
    }
    printf("missing count\n");
    for(int i = 0; i < 18; ++i) printf("%d ", count[i]);
    fclose(fin);
    return 0 ;
}
