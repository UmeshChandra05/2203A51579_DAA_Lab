#include<stdio.h>
void SelectionSort(int x[], int n){
    int large,index;
    for (int i = n-1; i > 0; i--){
        large = x[i];
        index = i;
        for (int j = 1; j <= i; j++){
            if (large < x[j]){
                large = x[j];
                index = j;
            } 
        }
        x[index] = x[i];
        x[i] = large;
    }
}

void Display(int x[], int n){
    for (int i = 0; i < n; i++){
        printf("%d \t",x[i]);
    }
}

int main(){
    int n,a[10];
    printf("Enter Number Of Elements You Want To Store : ");
    scanf("%d",&n);
    for (int i = 0; i < n ; i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    SelectionSort(a,n);
    Display(a,n);
    return 0;
}
