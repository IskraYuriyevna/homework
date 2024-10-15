#include <stdio.h>
#include <stdlib.h>

int** creatMat(int rows, int cols) {
    //function to create matrix
    int** nix = (int**)malloc(rows * sizeof(int*));
    if (nix == NULL) {
        printf("-1\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        nix[i] = (int*)malloc(cols * sizeof(int));
        if (nix[i] == NULL) {
            printf("-1\n");
            for (int j = 0; j < i; j++) {
                free(nix[j]);
            }
            free(nix);
            return NULL;
        }
    }
    return nix;
}

void freeMat(int** nix, int rows) {
    //function to free matrix
    for (int i = 0; i < rows; i++) {
        free(nix[i]);
    }
    free(nix);
}


void mulMat(int** Mat1, int k, int l, int** Mat2, int m, int n) {
    //function to compute matrix multiplication and print 
    int** res = creatMat(k, n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int p = 0; p < l; p++) {
                res[i][j] += Mat1[i][p] * Mat2[p][j];
            }
        }
    }
    if (res != NULL){
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
        freeMat(res, k);
    }
}

int main() {
    int k, l, m, n;
    int** Mat1, **Mat2;

    //input first matrix
    scanf("%d %d", &k, &l);

    Mat1 = creatMat(k, l);
    if(Mat1 == NULL){
        return 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%d", &Mat1[i][j]);
        }
    }
    
    //input second matrix
    scanf("%d %d", &m, &n);

    Mat2 = creatMat(m, n);
    if(Mat2 == NULL){
        return 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &Mat2[i][j]);
        }
    }

    //compute matrix multiplication
    if (l != m) {
        printf("-1\n");
        freeMat(Mat1, k);
        return 0;
    }
    mulMat(Mat1, k, l, Mat2, m, n);

    freeMat(Mat2, m);
    freeMat(Mat1, k);

    return 0;
}