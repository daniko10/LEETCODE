#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// my function must return number of different elements
// my function must sort an array without duplicates

void remove_duplicates(int *nums, int *n);
void print_tab(int *nums, int n);
void sort(int *nums, int n);

int main(void) {
    srand(time(NULL));

    int n = 10;
    int *nums = malloc(sizeof(int)*n); for(int i=0;i<n;i++) nums[i] = rand()%10;

    printf("Before sorting and deleting duplicates: "); print_tab(nums,n);
    sort(nums,n); print_tab(nums,n); remove_duplicates(nums,&n);
    printf("After sorting and deleting duplicates:  "); print_tab(nums,n);

    printf("k = %d",n);
}

void remove_duplicates(int *nums, int *n) {
    int max = nums[0]; for(int i=1; i<*n; i++) if(max<nums[i]) max = nums[i];
    int nmr_duplic = 0; 
    int var = *n;

    for(int i=0; i<var && nums[i] != max+1 ;i++) {
        int j = i+1;

        while(j<var && nums[j] == nums[i] ) {
            nmr_duplic++;
            nums[j] = max+1;
            j++;
        }

        sort(nums,var);
    }

    *n = var-nmr_duplic;
    nums = realloc(nums,sizeof(int) *(*n));
    
}

void print_tab(int *nums, int n) {
    for(int i=0;i<n;i++) printf("%d ",nums[i]); printf("\n");
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