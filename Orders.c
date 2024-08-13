#include<stdio.h>
#include<string.h>

struct Order{
    int Order_ID;
    char Item_Name[100];
    int Priority;
};

void InsertionSort(struct Order A[], int N) {
    int i, j;
    struct Book key;
    for(i = 1; i < N; i++){
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j].Priority > key.Priority) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void Display(struct Order A[], int N, int Choice){
    if(Choice == 1){
        printf("\nSorted By Priority Low to High: \n");
        for(int i = 0; i < N; i++)
            printf("%d\t\t%s\t\t%d\n", A[i].Order_ID, A[i].Item_Name, A[i].Priority);
    }
    else if(Choice == 2){
        printf("\nSorted By Priority High to Low: \n");
        for(int i = N - 1; i >= 0; i--)
            printf("%d\t\t%s\t\t%d\n", A[i].Order_ID, A[i].Item_Name, A[i].Priority);
    }
    
}

int main(){
    int N;
    int Choice;
    printf("Enter Number of Books Information Needed to Sort: ");
    scanf("%d",&N);
    struct Order A[N];
    for(int i = 0; i < N; i++){
        printf("\nEnter Number of Book Information %d: (Book ID) (Item_Name - SingleWord) (Priority): ", i + 1);
        scanf("%d\t%s\t%d", &A[i].Order_ID,A[i].Item_Name, &A[i].Priority);
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
