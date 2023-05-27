#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fin1 = fopen(argv[1], "rb"); // test
	FILE *fin2 = fopen(argv[2], "rb"); // predict
	char s[1 << 20];
	int y[1 << 20];
	int siz = 0, val, cnt = 0;
	while(fscanf(fin1, "%[^\n]s", s) != EOF){
		fscanf(fin1, "\n");
		sscanf(s, "%d", &y[siz]);
		siz++;
	}
	for(int i = 0; i < siz; ++i){
		fscanf(fin2, "%d", &val);
		cnt += val - y[i] > 0 ? val - y[i] : y[i] - val;
	}
	long double ans = ((long double) cnt) / siz;
	printf("%.6Lf\n", ans);
	return 0;
}
