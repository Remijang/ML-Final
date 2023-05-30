#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fin1 = fopen(argv[1], "rb"); // test
	FILE *fin2 = fopen(argv[2], "rb"); // predict
	char s[1 << 20];
	int y[1 << 20];
	int siz = 0, val;
	int cnt[9] = {};
	while(fscanf(fin1, "%[^\n]s", s) != EOF){
		fscanf(fin1, "\n");
		sscanf(s, "%d", &y[siz]);
		siz++;
	}
	for(int i = 0; i < siz; ++i){
		fscanf(fin2, "%d", &val);
		int diff = val - y[i] > 0 ? val - y[i] : y[i] - val;
		cnt[diff]++;
	}
	for(int i = 0; i < 9; ++i) printf("%d:%d  ", i, cnt[i]);
	putchar('\n');
	return 0;
}
