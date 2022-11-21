#include <stdio.h>
#include "my_mat.h"
#define SIZE 100

int main() {
    int matrix[SIZE][SIZE];
    int temp = 0;
    int flag = 0;
    int from =0,to=0;
    char ch = ' ';
    while(!flag){
        scanf("%c", &ch);
        switch(ch){
            case 'A':
                for(int i = 0 ; i < 3 ; i++){
                    for(int j = 0 ; j < 3 ; j++){
                        scanf("%d",&temp);
                        matrix[i][j]=temp;
                    }
                }
                break;
            case 'B':
                scanf("%d",&from);
                scanf("%d",&to);
                temp = floyd_warshall(matrix,from,to);
                if(temp!=-1)
                    printf("True\n");
                else
                    printf("False\n");
                break;
            case 'C':
                scanf("%d", &from);
                scanf("%d",&to);
                printf("%d\n",floyd_warshall(matrix,from,to));
                break;
            case 'D':
                flag = 1;
                break;
            default:
                printf("Invaild input, try again");
                break;
        }
    }
    printf("\n");
    return 0;

}
