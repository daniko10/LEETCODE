#include<stdio.h>

// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.

int main(void) {
    int nums[] = {1,43,5,2,3,54,67,2,1,34,54,234,22,1234,6,22,54,23,12,3435,4,223,1,123,42,545,6745,23,121,32,43,54,32,13,1,11};
    int n=sizeof(nums)/sizeof(int);
    int key = 44; // our value
    int index_1=-1, index_2=-1;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) if(nums[i] + nums[j] == key) { index_1 = i; index_2 = j; goto WE_FOUND;}
    }

    WE_FOUND:
    if( index_1 != -1 && index_2 != -1 ) printf("nums[%d] + nums[%d] == %d",index_1,index_2,key);
    else printf("We cannot sum two elements of tab nums to %d",key);
}