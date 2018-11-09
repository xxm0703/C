#include <stdio.h>
#include <stdlib.h>

typedef struct arr {
    int *first, lenght;
} arr;

void array_entry(arr *);

int even(arr *);

int odd(arr *);

void print_array(arr *);

int main() {
    int input = 0;
    arr array = {NULL, 0};
    while (input != 5) {
        printf("1. Enter array\n"
                       "2. Print array\n"
                       "3. Biggest odd\n"
                       "4. Smallest even\n"
                       "5. Exit\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                array_entry(&array);
                break;
            case 2:
                print_array(&array);
                break;
            case 3:
                printf("%d\n", odd(&array));
                break;
            case 4:
                printf("%d\n", even(&array));
                break;
            case 5:
                break;
            default:
                printf("Incorrect option\n");
                break;
        }
    }
    return 0;
}

int is_empty(arr *array) {
    if (!array->lenght) {
        printf("Empty\n");
        return 1;
    }
    return 0;
}

int even(arr *array) {
    if (is_empty(array)) return 1;
    int smallest = array->first[0];
    for (int i = 0; i < array->lenght; ++i)
        if ((smallest > array->first[i] || smallest % 2) && (!(array->first[i] % 2)))
            smallest = array->first[i];
    return smallest;
}

int odd(arr *array) {
    if (is_empty(array)) return 0;
    int biggest = array->first[0];
    for (int i = 0; i < array->lenght; ++i)
        if ((biggest < array->first[i] || !(biggest % 2)) && (array->first[i] % 2))
            biggest = array->first[i];
    return biggest;
}

void print_array(arr *array) {
    if (is_empty(array)) return;
    for (int i = 0; i < array->lenght; ++i) {
        printf("%d ", array->first[i]);
    }
    printf("\n");
}

void array_entry(arr *array) {
    free(array->first);
    array->first = (int *) malloc(sizeof(int));
    array->lenght = 0;
    while (scanf("%d", array->first + array->lenght)) {
        array->first = (int *) realloc(array->first, (++array->lenght + 1) * sizeof(int));
    }
    getchar();
}
