
#include <stdio.h>
#include "my_mat.h"
#define SIZE 10
#define INF 999999 //Indicates the absent of an edge

void fill_matrix(int matrix[SIZE][SIZE]);
int floyd_warshall(int mat[SIZE][SIZE],int from,int to);
int floyd_warshall(int mat[SIZE][SIZE],int from,int to){
    if(from == to) 
        return -1;
    int dp[SIZE][SIZE],i,j,k;
    
    //Copying the matrix into a new one which will be used to run the algorithm
    for(i = 0 ; i < SIZE ; i++){ 
        for(j = 0 ; j < SIZE ; j++){
            dp[i][j] = mat[i][j];
        }
    }
    for(i = 0 ; i < SIZE ; i++){ //i indicates the intermediate vertex on the path
        for(j = 0 ; j < SIZE ; j++){ //j the origin vertex
            for(k = 0 ; k < SIZE ; k++){ //k is the destination vertex
                if(dp[j][i] == INF || dp[i][k] == INF || i == j) continue; //if there's no path from j to i or no path from i to k or i = j, skip the iteration
                if(dp[j][i] + dp[i][k] < dp[j][k]) //check if path through the intermediate vertex is shorter then the current path from j to k
                    dp[j][k] = dp[j][i] + dp[i][k]; //if it is, update the length of the path
            }
        }
    }
    if(dp[from][to] < INF) //if the path is less the INF, a path exists
        return dp[from][to]; //return the length of the shortest path
    return -1; //else, -1 indicates no path exists
}

void fill_matrix(int matrix[SIZE][SIZE]) {
    int temp;
    for(int i = 0 ; i < SIZE ; i++){
        for(int j = 0 ; j < SIZE ; j++){
            scanf("%d",&temp); //Places users input into variable temp
            if(temp == 0)
                temp = INF; //Changing the value to INF for convenience
            matrix[i][j]=temp;
        }
    }
}
