#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void print(int *tab, int n);
bool check_if_duplicates(int *tab, int n);

int main(void) {
    srand(time(NULL));

    int n = 10;
    int *tab = malloc(sizeof(int) * n);
  
    for(int i=0; i<n; i++) tab[i] = rand()%50;
    print(tab,n);

    bool output = check_if_duplicates(tab,n);
    if(output) printf("Duplicates are FOUND");
    else printf("Duplicates are not FOUND");
}

void print(int *tab, int n) {
    for(int i=0; i<n; i++) printf("%d ",tab[i]); printf("\n");
}

bool check_if_duplicates(int *tab, int n) {
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) if(tab[i] == tab[j]) return true;
    }
    return false;
}