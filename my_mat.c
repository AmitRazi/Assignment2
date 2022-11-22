
#include <stdio.h>
#include "my_mat.h"
#define SIZE 10
#define INF 9999

void fill_matrix(int matrix[SIZE][SIZE]);
int floyd_warshall(int mat[SIZE][SIZE],int from,int to);
int floyd_warshall(int mat[SIZE][SIZE],int from,int to){
    if(from == to)
        return -1;
    int dp[SIZE][SIZE],i,j,k;
    for(i = 0 ; i < SIZE ; i++){
        for(j = 0 ; j < SIZE ; j++){
            dp[i][j] = mat[i][j];
        }
    }
    for(i = 0 ; i < SIZE ; i++){
        for(j = 0 ; j < SIZE ; j++){
            for(k = 0 ; k < SIZE ; k++){
                if(dp[j][i] == 0 || dp[i][k] == 0 || i == j) continue;
                if(dp[j][i] + dp[i][k] < dp[j][k])
                    dp[j][k] = dp[j][i] + dp[i][k];
            }
        }
    }
    if(dp[from][to] < INF)
        return dp[from][to];
    return -1;
}

void fill_matrix(int matrix[SIZE][SIZE]) {
    int temp;
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            scanf("%d",&temp);
            if(temp == 0)
                temp = 9999;
            matrix[i][j]=temp;
        }
    }
}
