#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

#include <stdbool.h>

bool is_safe(int *arr, int size) {
    if (size < 2) return true;  

    bool is_increasing = (arr[1] > arr[0]);
    bool is_decreasing = (arr[1] < arr[0]);
    for (int i = 1; i < size; i++) {
        int diff = arr[i] - arr[i - 1];

        if (diff == 0 || diff > 3 || diff < -3) {
            return false; 
        }

        if (diff > 0) {
            if (is_decreasing) return false; 
            is_increasing = true;
        }
        else if (diff < 0) {
            if (is_increasing) return false; 
            is_decreasing = true;
        }
    }

    return is_increasing || is_decreasing;
}

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return -1;
    }
}

int main() {

    FILE *file = fopen("input.dat", "r");

    char buffer[BUFFER_SIZE];

    int safe = 0;
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {

        int counter = 1;
        for (int i = 0; buffer[i] != '\n'; i++) {
            if (buffer[i] == ' ')
                counter++;
        }

        int arr[counter];

        int i = 0;
        int num = 0;
        int k = 0;
        while (buffer[i] != '\0') {
            if (isdigit(buffer[i])) {
                num = num * 10 + charToInt(buffer[i]);
            }

            else {
                arr[k++] = num;
                num = 0;
            }
            i++;
        }

        for (int i = 0; i < counter; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");

        if (is_safe(arr, counter)) {
            safe++;
        }
    }

    printf("%d\n", safe);
    fclose(file);

    return 0;
}