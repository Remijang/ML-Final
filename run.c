#include <stdio.h>
#include <stdlib.h>

int main(){
    float cs = 0.5316;
    float scale = 1000;
    char run[100];
    for(int i = 1; i < 50; i += 2){
        for(float j = 0.1; j < 11; j *= 10){
                sprintf(run, "./run.sh %d %f", i, j);
                printf("%d %f\n", i, j);
                system(run);
        }
    }
}
