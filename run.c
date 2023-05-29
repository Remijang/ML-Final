#include <stdio.h>
#include <stdlib.h>

int main(){
    float cs = 0.5316;
    float scale = 1000;
    char run[100];
    for(float i = 10; i <= 200; i += 10){
        for(float j = 5; j <= 25; j += 5){
                sprintf(run, "./run.sh 5 %f %f", i, j);
                printf("%f %f\n", i, j);
                system(run);
        }
    }
}
