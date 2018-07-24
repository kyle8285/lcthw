#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb) (int a, int b); // can use 'compare_db' like it's a type similar to int or char

/*
 * A classic bubble sort function that uses the
 * compare_cb callback to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int)); // array pointer into which we copy numbers

    if (!target)
        die("Memory error");

    memcpy(target, numbers, count * sizeof(int)); // the actual copying of numbers into target

    for (i =0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j+1]) > 0) { // calls 'cmp' which is a pointer
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b) // needs to have same definition as typedef that we created
{
    return (a > b) - (a < b);
}

int reverse_order(int a, int b) // needs to have same definition as typedef that we created
{
    return (a < b) - (a > b);
}

int strange_order(int a, int b) // needs to have same definition as typedef that we created
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/*
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp) // takes a function pointer 'compare_db'
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp); // returns a pointer

    if (!sorted)
        die("Failed to sort as requested");

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted); // release the memory
}

int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1; // basically the length of the arguments minus the filename itself
    int i = 0;
    char **inputs = argv + 1; // pointer to the second argument of argv (skipping over the filename)

    int *numbers = malloc(count *sizeof(int)); // pointer to memory where we will copy numbers
    if (!numbers) die("Memory error");

    for (i = 0; i <count; i++) {
        numbers[i] = atoi(inputs[i]); // convert str inputs from ascii to int and store in 'numbers'
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers); // release the memory

    return 0;
}
