int main() {
    int matrix[SIZE][SIZE];
    int flag = 0;
    int from =0,to=0;
    char ch = ' ';
    while(!flag){

        scanf("%c", &ch);
        switch(ch){
            case 'A':
                fill_matrix(matrix);
                break;
            case 'B':
                scanf("%d", &from);
                scanf("%d", &to);
                temp = floyd_warshall(matrix,from,to);
                if(temp!=-1)
                    printf("True\n");
                else
                    printf("False\n");
                break;
            case 'C':
                scanf("%d", &from);
                scanf("%d", &to);
                printf("%d\n",floyd_warshall(matrix,from,to));
                break;
            case 'D':
                flag = 1;
                break;
            default:
                break;
        }
    }
    printf("\n");



    return 0;

}
