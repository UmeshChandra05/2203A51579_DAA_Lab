#include<stdio.h>
void BubbleSort(int x[], int n){
    int Temp;
    for (int i = 0; i < n-2 ; i++){                   // i <= n-2
        for (int j = 0 ; j < n-1-i ; j++){            // j < n-1-i
            if(x[j]>x[j+1]){
                Temp = x[j];
                x[j] = x[j+1];
                x[j+1] = Temp;
            }
        }
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
    BubbleSort(a,n);
    Display(a,n);
    return 0;
}