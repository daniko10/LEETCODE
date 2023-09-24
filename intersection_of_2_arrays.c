#include<stdio.h>
#include<stdlib.h>

void print(int *tab, int n);
void sort(int *nums, int n);

int main(void) {
    int num1[] = {2,2,1,3,4,5,4,8,8,99}, num2[] = {2,2,1,3,3,99,4,4,8,89,8};
    int n1 = sizeof(num1)/sizeof(int), n2 = sizeof(num2)/sizeof(int);
    int *result = NULL;
    int n_result = 0;
    int var1 = 1;
    int var2 = 0;

    sort(num1,n1); sort(num2,n2);
    print(num1,n1);
    print(num2,n2);

    for(int i=0; i<n1;) {
        for(int j=i+1; num1[i]==num1[j] ; j++) var1++;
        for(int j=0; j<n2 ; j++) if(num1[i]==num2[j]) var2++; 
        if(var1 == var2) {
            n_result+=var1;
            result = realloc(result,sizeof(int) * n_result);
            for(int j=n_result-var1; j<n_result; j++) result[j] = num1[i];
        }
        i+=var1;
        var1=1;
        var2=0;
    }

    print(result,n_result);
}

void print(int *tab, int n) {
    if(tab) for(int i=0; i<n; i++) printf("%d ",tab[i]); printf("\n");
}

void sort(int *nums, int n) {
    for(int i = 1; i<n; i++) {
        int key = nums[i];
        int j = i-1;
        for(; j>=0 && key<nums[j]; j--) {
            nums[j+1] = nums[j];
        }
        nums[j+1] = key;
    }
}