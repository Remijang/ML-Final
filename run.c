#include <stdio.h>
#include <stdlib.h>

int main(){
    float cs = 0.5316;
    float scale = 1000;
    char run[100];
    for(float i = 0.0001; i < 1001; i *= 10){
        for(float j = 0.0001; j < 101; j *= 10){
                sprintf(run, "./run.sh 5 %f %f", i, j);
                printf("%f %f\n", i, j);
                system(run);
        }
    }
}
