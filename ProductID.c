#include<stdio.h>
#include<string.h>

struct Product{
    int Price;
    char Name[100];
    int ProductCode;
};

void SelectionSort(struct Product A[], int N){
    int largeQ, largeC, index;
    char LargeN[100];
    for(int i = N - 1; i >= 1; i--){
        largeQ = A[0].ProductCode;
        index = 0;
        largeC = A[0].Price;
        strcpy(LargeN, A[0].Name);
        for(int j = 1; j <= i; j++){
            if(largeQ < A[j].ProductCode){
                largeQ = A[j].ProductCode;
                largeC = A[j].Price;
                strcpy(LargeN, A[j].Name);
                index = j;
            }
        }
        A[index].ProductCode = A[i].ProductCode; 
        A[index].Price = A[i].Price;
        strcpy(A[index].Name, A[i].Name);
        A[i].ProductCode = largeQ;
        A[i].Price = largeC;
        strcpy(A[i].Name, LargeN);
    }
}

void Display(struct Product A[], int N, int Choice){
    if(Choice == 1){
        printf("\nSorted By ProductCode Low to High: \n");
        for(int i = 0; i < N; i++)
            printf("%d\t\t%s\t\t%d\n", A[i].Price, A[i].Name, A[i].ProductCode);
    }
    else{
        printf("\nSorted By ProductCode High to Low: \n");
        for(int i = N - 1; i >= 0; i--)
            printf("%d\t\t%s\t\t%d\n", A[i].Price, A[i].Name, A[i].ProductCode);
    }
}

int main(){
    int N;
    int Choice;
    printf("Enter Number of Products Information Needed to Sort: ");
    scanf("%d",&N);
    struct Product A[N];
    for(int i = 0; i < N; i++){
        printf("\nEnter Number of product Information %d: (Product Code) (Name - SingleWord) (ProductCode): ", i + 1);
        scanf("%d\t%s\t%d", &A[i].Price, A[i].Name, &A[i].ProductCode);
    }
    
    do{
        printf("\n Enter Sorting Order:\n Enter 1 to Sort Low to High \n Enter 2 to Sort High To Low \n Enter 3 to Exit\n");
        printf("\nInput Your Choice: ");
        InputChoice: scanf("%d", & Choice);

        if(Choice == 1 || Choice == 2){
            SelectionSort(A, N);
            Display(A, N, Choice);
        }
        else if(Choice == 3)
            printf("Exited Program, Thank You");
        else{
            printf("\nInvalid Input, Please Input Again !\n");
            goto InputChoice;
        }
    }while(Choice != 3);
    return 0;
}