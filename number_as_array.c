#include<stdio.h>
#include<stdlib.h>

//Increment the large integer by one and return the resulting array of digits.

int main(void) {
    int nmr[] = {3,1,5,9};
    int *result = NULL;
    int n = sizeof(nmr)/sizeof(int);
    int var = 322; // we want to add this

    printf("("); for(int i=0; i<n; i++) printf("%d ",nmr[i]); printf(")\n");

    result = realloc(result, sizeof(int)*n); nmr[n-1]+=var;
    
    for(int i=n-1; i>=0; i--) {
        if(nmr[i] >= 10) {
            result[i] = nmr[i]%10;
            nmr[i-1]+=nmr[i]/10;
        }
        else result[i] = nmr[i];
    }

    printf("("); for(int i=0; i<n; i++) printf("%d ",result[i]); printf(")\n");
}