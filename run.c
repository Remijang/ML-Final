#include <stdio.h>
#include <stdlib.h>

int main(){
    float cs = 0.5316;
    float scale = 1000;
    char run[100];
    for(float i = 10; i < 300; i *= 2){
        for(float j = 10; j < 31; j += 10){
                sprintf(run, "./run.sh 5 %f %f", i, j);
                printf("%f %f\n", i, j);
                system(run);
        }
    }
}
