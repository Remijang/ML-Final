#include <bits/stdc++.h>

using namespace std;

long double x[17171][17];
int y[17171];

int main(int argc, char *argv[]){
    FILE *fin = fopen(argv[1], "rb");
    srand(time(NULL));
    int n = 0, tmp;
    for(int t = 0; t < 17161; ++t){
        fscanf(fin, "+%d", &y[n]);
        for(int i = 0; i < 17; ++i) fscanf(fin, "%d:%Lf", &tmp, &x[n][i]);
        fscanf(fin, "\n");
        n++;
    }
    fclose(fin);
    int choose[n];
    for(int i = 0; i < n; ++i) choose[i] = i;
    for(int i = 0; i < n; ++i){
        int rd = i + rand() % (n - i);
        choose[i] ^= choose[rd] ^= choose[i] ^= choose[rd];
    }
    FILE *fout[6];
    fout[0] = fopen("val1", "wb");
    fout[1] = fopen("val2", "wb");
    fout[2] = fopen("val3", "wb");
    fout[3] = fopen("val4", "wb");
    fout[4] = fopen("val5", "wb");
    fout[5] = fopen("s", "wb");
    fprintf(fout[5], "\n");
    for(int i = 0; i < n; ++i){
        if(i > 4) fprintf(fout[i % 5], "\n");
        fprintf(fout[i % 5], "%d", y[choose[i]]);
        for(int j = 0; j < 17; ++j) fprintf(fout[i % 5], " %d:%Lf", j+1, x[choose[i]][j]);
    }
    for(int i = 0; i < 6; ++i) fclose(fout[i]);
    system("cat val2 s val3 s val4 s val5 > train1");
    system("cat val3 s val4 s val5 s val1 > train2");
    system("cat val4 s val5 s val1 s val2 > train3");
    system("cat val5 s val1 s val2 s val3 > train4");
    system("cat val1 s val2 s val3 s val4 > train5");
    system("./libsvm/svm-train -s 0 -t 2 -c 32768 -g 0.03125 -h 0 -e 0.000001 val1 model");
    system("./libsvm/svm-predict -q train1 model predict1");
    system("./libsvm/svm-train -s 0 -t 2 -c 32768 -g 0.03125 -h 0 -e 0.000001 val2 model");
    system("./libsvm/svm-predict -q train2 model predict2");
    system("./libsvm/svm-train -s 0 -t 2 -c 32768 -g 0.03125 -h 0 -e 0.000001 val3 model");
    system("./libsvm/svm-predict -q train3 model predict3");
    system("./libsvm/svm-train -s 0 -t 2 -c 32768 -g 0.03125 -h 0 -e 0.000001 val4 model");
    system("./libsvm/svm-predict -q train4 model predict4");
    system("./libsvm/svm-train -s 0 -t 2 -c 32768 -g 0.03125 -h 0 -e 0.000001 val5 model");
    system("./libsvm/svm-predict -q train5 model predict5");
    system("./dif train1 predict1");
    system("./dif train2 predict2");
    system("./dif train3 predict3");
    system("./dif train4 predict4");
    system("./dif train5 predict5");
    system("rm val1 val2 val3 val4 val5 train1 train2 train3 train4 train5 predict1 predict2 predict3 predict4 predict5");
    return 0;
}
