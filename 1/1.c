#include <stdio.h>
#include <stdlib.h>

int count_lines(char filename[]) {

    FILE *file = fopen(filename, "r");

    int num1, num2, count = 0;
    while (fscanf(file, "%d\t%d\n", &num1, &num2) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

int comparison(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int main() {

    int count = count_lines("input.dat");

    FILE *file = fopen("input.dat", "r");

    int arr1[count];
    int arr2[count];

    int num1, num2, k = 0;
    while (fscanf(file, "%d\t%d\n", &num1, &num2) == 2) {
        arr1[k] = num1;
        arr2[k] = num2;
        k++;
    }

    fclose(file);

    qsort(arr1, count, sizeof(int), comparison);
    qsort(arr2, count, sizeof(int), comparison);

    int dist;
    for (int i = 0; i < count; i++) {
        dist += abs(arr1[i] - arr2[i]);
    }

    printf("%d\n", dist);

    return 0;
}