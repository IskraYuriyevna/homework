#include <iostream>
using namespace std;

int main(){
    int i,j,k; //p[2],[3],[4]

    int ***p;
    p = new int **[2];
    for(i=0;i<2;i++){
        p[i] = new int*[3];
        for(i=0;j<3;j++)
            {p[i][j] = new int[4];}
    }

    //释放内存
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++){
            delete [] p[i][j];
        }
    }
    for(i=0;j<3;j++){
        delete [] p[i];
    }
    delete [] p;

    return 0;
}