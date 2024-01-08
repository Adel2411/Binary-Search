#include <stdlib.h>
#include <stdio.h>

int BinarySearchIterative(int* t, int d, int f, int Val) {
    while (d <= f)
    {
        int m = (d+f)/2;
        if (Val == t[m])
            return m;
        if (Val > t[m]) {
            d = m + 1;
        } else {
            f = m - 1;
        }   
    }
    return -1;
}

int BinarySearchRecursive(int* t, int d, int f, int Val) {
    if (d > f)
        return -1;

    int m = ( d + f ) / 2;

    if (Val == t[m])
        return m;
    
    if (Val > t[m]) {
        return BinarySearchRecursive(t, m + 1, f, Val);
    } else {
        return BinarySearchRecursive(t, d, m - 1, Val);
    } 
}

void InsertionSort(int* t, int N) {
    for (int i = 1; i < N; i++)
    {
        int temp = t[i];
        int j = i - 1;
        while (j >= 0 && t[j] > temp)
        {
            t[j + 1] = t[j];
            j--;
        }
        t[j + 1] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int tab[9] = {3, 7, 0, 78, 5, 89, 23, 2, 11};
    InsertionSort(tab, 9);
    for (int i = 0; i < 9; i++)
        printf("%3d", tab[i]);
    
    printf("\nEnter the value you want to search : ");
    int X;
    scanf("%d", &X);
    int A = BinarySearchIterative(tab, 0, 8, X);
    int B = BinarySearchRecursive(tab, 0, 8, X);

    printf("\n---------- ITERATIVE BINARY SEARCH ----------");
    if (A != -1)
        printf("\nYOUR VALUE EXISTS :) (position == %d)\n", A);
    else
        printf("\nYOUR VALUE DOESN'T EXIST :(\n");

    printf("\n---------- RECURSIVE BINARY SEARCH ----------");
    if (B != -1)
        printf("\nYOUR VALUE EXISTS :) (position == %d)\n\n", B);
    else
        printf("\nYOUR VALUE DOESN'T EXIST :(\n\n");

    return 0;
}
