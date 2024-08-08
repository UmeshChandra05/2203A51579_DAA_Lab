#include<stdio.h>
#include<string.h>

struct Book{
    int Book_ID;
    char Name[100];
    int Price;
};

void InsertionSort(struct Book A[], int N) {
    int i, j;
    struct Book key;
    for(i = 1; i < N; i++){
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j].Price > key.Price) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}


void Display(struct Book A[], int N, int Choice){
    if(Choice == 1){
        printf("\nSorted By Price Low to High: \n");
        for(int i = 0; i < N; i++)
            printf("%d\t\t%s\t\t%d\n", A[i].Book_ID, A[i].Name, A[i].Price);
    }
    else if(Choice == 2){
        printf("\nSorted By Price High to Low: \n");
        for(int i = N - 1; i >= 0; i--)
            printf("%d\t\t%s\t\t%d\n", A[i].Book_ID, A[i].Name, A[i].Price);
    }
    
}

int main(){
    int N;
    int Choice;
    printf("Enter Number of Books Information Needed to Sort: ");
    scanf("%d",&N);
    struct Book A[N];
    for(int i = 0; i < N; i++){
        printf("\nEnter Number of Book Information %d: (Book ID) (Name - SingleWord) (Price): ", i + 1);
        scanf("%d\t%s\t%d", &A[i].Book_ID,A[i].Name, &A[i].Price);
    }
    do{
        printf("\n Enter Sorting Order:\n Enter 1 to Sort Low to High \n Enter 2 to Sort High To Low \n Enter 3 to Exit\n");
        printf("\nInput Your Choice: ");
        InputChoice: scanf("%d", & Choice);
        if(Choice == 1 || Choice == 2){
            InsertionSort(A, N);
            Display(A, N, Choice);
        }
        else if(Choice == 3)
            printf("Exited Program, Thank You");
        else{
            printf("Invalid Input, Please Input Again !");
            goto InputChoice;
        }
    }while(Choice != 3);
    return 0;
}