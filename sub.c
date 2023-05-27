#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fin = fopen("predict", "rb");
	FILE *fout = fopen("submit.csv", "wb");
	int y;
	int idx = 17170;
	fprintf(fout, "id,Danceability\n");
	while(fscanf(fin, "%d", &y) != EOF){
		fprintf(fout, "%d, %d\n", idx, y);
		idx++;
	}
	fclose(fin), fclose(fout);
	return 0;
}
