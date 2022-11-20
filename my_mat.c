#include <stdio.h>
#define SIZE 100
int floyd_warshall(int matrix[SIZE][SIZE],int from,int to){
    int i,j,k;
    int dp[SIZE][SIZE];
    for(i = 0 ; i < SIZE ; i++){
        for(j = 0 ; j < SIZE ; j++){
            dp[i][j] = matrix[i][j];
        }
    }
    
    for(i = 0 ; i < SIZE ; i++){
        for(j = 0 ; j < SIZE ; j++){
            for(k = 0 ; k < SIZE ; k++){
                if(dp[i][k] == 0 || dp[k][j] == 0) {
                    continue;
                }
                else if(dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    if(dp[from][to]){
        return dp[from][to];
    }
    return -1;
}
