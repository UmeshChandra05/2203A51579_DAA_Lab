#include<stdio.h>
#include<string.h>

struct Package{
    char Destination[100];
    int EstTime;
};

void BubbleSort(struct Package A[], int N){
    int Temp;
    char TempN[100];
    for(int i = 0; i < N - 1; i ++){
        for(int j = 0; j < N - i - 1; j++){
            if(A[j].EstTime > A[j+1].EstTime){
                Temp = A[j].EstTime;
                A[j].EstTime = A[j+1].EstTime;
                A[j+1].EstTime = Temp;
                strcpy(TempN, A[j].Destination);
                strcpy(A[j].Destination, A[j+1].Destination);
                strcpy(A[j+1].Destination, TempN);
            }
        }
    }
}

void Display(struct Package A[], int N, int Choice){
    if(Choice == 1){
        printf("\nSorted By Estimated Time Low to High: \n");
        for(int i = 0; i < N; i++)
            printf("%s\t\t%d\n", A[i].Destination, A[i].EstTime);
    }
    else{
        printf("\nSorted By Estimated Time High to Low: \n");
        for(int i = N - 1; i >= 0; i--)
            printf("%s\t\t%d\n", A[i].Destination, A[i].EstTime);
    }
    
}


int main(){
    int N;
    int Choice;
    printf("Enter Number of Package Information Needed to Sort: ");
    scanf("%d",&N);
    struct Package A[N];
    for(int i = 0; i < N; i++){
        printf("\nEnter Number of Package Information %d: (Desitanation - SingleWord) (Estimated Time): ", i + 1);
        scanf("%s%d",A[i].Destination,&A[i].EstTime);
    }


    do{
        printf("\n Enter Sorting Order:\n Enter 1 to Sort Low to High \n Enter 2 to Sort High To Low \n Enter 3 to Exit\n");
        printf("\nInput Your Choice: ");
        InputChoice: scanf("%d", & Choice);

        if(Choice == 1 || Choice == 2){
            BubbleSort(A, N);
            Display(A, N, Choice);
        }
        else if(Choice == 3)
            printf("Exited Program, Thank You");
        else{
            printf("\nInvalid Input, Please Input Again !\n");
            goto InputChoice;
        }
    }while(Choice != 3);
}