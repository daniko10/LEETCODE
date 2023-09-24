#include<stdio.h>
#include <unistd.h>

void print(int *nums, int n);

int main(void) {
    int nums[] = {0,0,3,0,2,5,3,0,0,5,3,0,1,33,1,2,32,0};
    int n = sizeof(nums)/sizeof(int);
    int var;

    print(nums,n);
    for(int i=0; i<n; i++) {
        var = 0;
        if(nums[i] == 0) {
            // check how many 0`s
            for(int j=i; nums[j] == 0; j++) var++;
            for(int key = var; key > 0; key--) for(int j=i+1; j<n; j++) nums[j-1] = nums[j];
            nums[n-1] = 0;
        } 
    }
    print(nums,n);
}

void print(int *nums, int n) {
    for(int i=0; i<n; i++) printf("%d ",nums[i]); printf("\n");
}