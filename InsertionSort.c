#include<stdio.h>
void InsertionSort(int x[], int n){
    int Temp,j;
    for (int i = 1 ; i < n ; i++){
        Temp = x[i] ;
        for ( j = i-1 ; j >= 0 && Temp < x[j] ; j--){
            if(Temp < x[j]){
                x[j+1] = x[j];
            }
        }
        x[j+1] = Temp;
    }
}

void Display(int x[], int n){
    for (int i = 0; i < n; i++){
        printf("%d\t",x[i]);
    }
} 

int main(){
    int n,a[10],i;
    printf("Enter Number Of Elements You Want To Store In Array : ");
    scanf("%d",&n);
    printf("\n");
    for( i = 0 ; i < n ; i++ ){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nBefore Sorting :  ");
    Display(a,n);
    printf("\nAfter Sorting  :  ");
    InsertionSort(a,n);
    Display(a,n);
    return 0;
}