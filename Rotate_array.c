#include<stdio.h>

// rotate the array to the right by k steps, where k is non-negative.
// nmus  = [1,2,3,4,5,6,7] k = 3
//Output: [5,6,7,1,2,3,4]

void print(int *nums, int n);

int main(void) {
    int nums[] = {1,2,3,4,5,6,7};
    int key_0 = 4; // 3 times rotate to the right
    int n = sizeof(nums)/sizeof(int);
    int var, key; // helps with rotation

    print(nums,n);

    for(int j = 0; j<key_0; j++) { 
        var = nums[0];
        for(int i=1; i<n; i++) {
            key = nums[i];
            nums[i] = var;
            var = key;
        }
        nums[0] = var;
    }

    print(nums,n);

}
void print(int *nums, int n) {
    for(int i=0; i<n; i++) printf("%d ",nums[i]); printf("\n");
}