#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fin = fopen(argv[1], "rb");
    int count[10] = {}, t;
    while(fscanf(fin, "%d", &t) != EOF){
        count[t]++;
    }
    for(int i = 0; i < 10; ++i) printf("%d:%d\t", i, count[i]);
    putchar('\n');
    return 0;
}
