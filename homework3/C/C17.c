#include <stdio.h>
#include <math.h>

struct vector{
    double x;
    double y;
    double z;
};

double area_of_parallelogram(struct vector* v1, struct vector* v2){
    double i,j,k,mod_vec;

    i = v1->y * v2->z - v2->y * v1->z;
    j = v2->x * v1->z - v2->z * v1->x;
    k = v1->x * v2->y - v2->x * v1->y;
    mod_vec = sqrt(pow(i,2)+pow(j,2)+pow(k,2));
    
    return mod_vec;
}

int main(){
    struct vector vec1,vec2;
    double square;

    scanf("%lf %lf %lf %lf %lf %lf",
    &vec1.x,&vec1.y,&vec1.z,
    &vec2.x,&vec2.y,&vec2.z);

    square = area_of_parallelogram(&vec1,&vec2);
    printf("%.4lf",square);

    return 0;
}