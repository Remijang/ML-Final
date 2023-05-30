#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fin1 = fopen("new_train", "rb");
    FILE *fin2 = fopen("new_test", "rb");
    FILE *fout1 = fopen("new_train.svm", "wb");
    FILE *fout2 = fopen("new_test.svm", "wb");
    float y;
    long double x[18];
    for(int i = 0; i < 17170; ++i){
        if(i) fprintf(fout1, "\n");
        fscanf(fin1, "%f", &y);
        for(int j = 0; j < 18; ++j) fscanf(fin1, "%Lf", &x[j]);
        fprintf(fout1, "%d", (int)y);
        for(int j = 0; j < 18; ++j) fprintf(fout1, " %d:%Lf", j+1, x[j]);
    }
    for(int i = 0; i < 6315; ++i){
        if(i) fprintf(fout2, "\n");
        for(int j = 0; j < 18; ++j) fscanf(fin2, "%Lf", &x[j]);
        fprintf(fout2, "-1 ");
        for(int j = 0; j < 18; ++j) fprintf(fout2, " %d:%Lf", j+1, x[j]);
    }
    fclose(fin1), fclose(fin2), fclose(fout1), fclose(fout2);
    return 0;
}
