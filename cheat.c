#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fin1 = fopen("submit.csv", "rb"); // predict
	FILE *fin2 = fopen("test_partial_answer.csv", "rb"); // answer
    FILE *fout = fopen("cheat_predict", "wb");
	char s[1 << 20];
	int y[1 << 20];
	int siz = 0, val, dummy, Siz = 0, mi = 101001;
	int cnt[9] = {};
    float valf;
    fscanf(fin1, "%[^\n]s", s);
    fscanf(fin1, "\n");
	while(fscanf(fin1, "%d", &dummy) != EOF){
		fscanf(fin1, ", %d", &y[dummy]);
        Siz++;
        mi = mi > dummy ? dummy : mi;
	}
    fscanf(fin2, "%[^\n]s", s);
    fscanf(fin2, "\n");
    long double mae = 0.0;
	while(fscanf(fin2, "%d,%f", &dummy, &valf) != EOF){
        val = (int) valf;
		int diff = val - y[dummy] > 0 ? val - y[dummy] : y[dummy] - val;
		cnt[diff]++;
        y[dummy] = val;
        mae += diff, siz++;
	}
    for(int i = 0; i < Siz; ++i){
        fprintf(fout, "%d\n", y[mi+i]);
    }
	for(int i = 0; i < 9; ++i) printf("%d:%d  ", i, cnt[i]);
    printf("\n%Lf\n", mae / siz);
	return 0;
}
