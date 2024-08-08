#include<stdio.h>

void Fibbo (int N){   
    if(N > 0){
        a = b;
        b = c; 
        printf("%d \n",c);
        c = a + b;
        Fibbo(N-1);
    }
}

int a=0,b=1,c = 0;

int main (){
    int n , sol;
    printf("Number Of Terms : ");
    scanf("%d",&n);
    Fibbo(n);
    return 0;
}
