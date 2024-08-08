#include<stdio.h>
#include<stdlib.h>

int len = 0;

void InsertElement(int a[], int Index , int Val){
    if (Index <= len ){
        len++;
        for (int  i = len-1; i > Index ; i--){
            a[i] = a[i-1];
        }
        a[Index] = Val;
    }
}

void DeleteElement(int a[], int Index){
    if (Index <= len ){
        for (int  i = Index; i < len; i++){
            a[i] = a[i+1];
        }
        len--;
    }
}

void SearchKeyVal(int a[]){
    int key;
    int count = 0;
    printf("\n\t Enter Key Value : ");
    scanf("%d",&key);
    for (int i = 0 ; i < len ; i++){
        if (key == a[i]){
            printf("\n\tKey Value Found At Index %d\n",i);
            count++;
        }
    }

    if(!count){
        printf("Key Value Not Found In The Array !\n");
    }
}

int ArraySum(int a[],int n){
    if (n == 0)
        return a[0];
    else
        return a[n]+ArraySum(a,n-1);
}

void DisplayArray(int a[]){
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("\t%d", a[i]);
    printf("\n");
}

int main(){
    int a[10],Ch,Index,Val;

    printf("Enter Number Of Elements You Want To Store : ");
    scanf("%d",&len);

    for (int i = 0 ; i < len ; i++){
        printf("\nEnter Element a[%d] : ",i);
        scanf("%d",&a[i]);
    }

    while(1){
        printf("\n1.Insert An Element At The Begining Of Array\n");
        printf("2.Insert An Element At The End Of Array\n");
        printf("3.Insert An Element At The Specified Index Of Array\n");
        printf("4.Delete An Element At The Begining Of Array\n");
        printf("5.Delete An Element At The End Of Array\n");
        printf("6.Delete An Element At The Specified Index Of Array\n");
        printf("7.Searching For An Element In The Array\n");
        printf("8.Display Sum of Array\n");
        printf("9.Display Array Elements\n");
        printf("10.Exit\n");
        printf("\n\tEnter Your Choice : ");
        fflush(stdin);
        scanf("%d",&Ch);
        
        switch (Ch){
        case 1:
            printf("\nEnter Value You Want To Store At Begining : ");
            scanf("%d",&Val);
            InsertElement(a,0,Val);
            printf("Element Inserted Successfully At Begining\n");
            break;
        case 2:
            printf("\nEnter Value You Want To Store At End : ");
            scanf("%d",&Val);
            InsertElement(a,len,Val);
            printf("Element Inserted Successfully At End\n");
            break;
        case 3:
            printf("\nEnter Value You Want To Store : ");
            scanf("%d",&Val);
            printf("\nEnter At Which Index You Want To Store : ");
            scanf("%d",&Index);
            InsertElement(a,Index,Val);
            printf("Element Inserted Successfully At Index %d\n",Index);
            break;
        case 4:
            DeleteElement(a,0);
            printf("Element Deleted Successfully At Begining\n");
            break;
        case 5:
            DeleteElement(a,len);
            printf("Element Deleted Successfully At End\n");
            break;
        case 6:
            printf("Enter Index Of Element You Want To Delete : ");
            scanf("%d",&Index);
            DeleteElement(a,Index);
            printf("Element Deleted Successfully At Index %d\n",Index);
            break;
        case 7:
            SearchKeyVal(a);
            break;
        case 8:
            DisplayArray(a);
            break;
        case 9:
            printf("\nSum Of Elements In The Array : %d\n\n", ArraySum(a,len));
        case 10:
            exit(0);
        default: printf("\n\tWrong Input Please Enter Again : ");
            break;
        }
    }
    return 0;
}