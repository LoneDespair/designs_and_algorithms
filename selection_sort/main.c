#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void selection_sort(int size, int input_list[]);
void print_array(int size, int input_list[]);
void merge_sort(int start, int end, int input_list[]);
void combine(int start, int end, int input_list[]);


int main()
{
    int input_list[] = {4, 1, 454, 234, 232, 11, 2};
    int byte_size = sizeof(input_list), size = byte_size / sizeof(int);

    // Different array for different algorithm
    int selection_inputs[size], merge_inputs[size];

    // Since each array is passed by reference,
    // we need to copy them into separate arrays
    memcpy(selection_inputs, input_list, byte_size);
    memcpy(merge_inputs, input_list, byte_size);

    selection_sort(size, selection_inputs);
    merge_sort(0, size - 1, merge_inputs);

    printf("Unsorted inputs: ");
    print_array(size, input_list);

    printf("Selection sort: ");
    print_array(size, selection_inputs);

    printf("Merge sort ");
    print_array(size, merge_inputs);

    return 0;
}


void selection_sort(int size, int input_list[])
{

    for (int first = 0; first < size; first++)
    {
        int min_value = input_list[first];

        for (int second = first + 1; second < size; second++)
        {
            if (input_list[second] >=  min_value) continue;

            min_value = input_list[second];

            input_list[second] = input_list[first];
            input_list[first] = min_value;
        }
    }

    printf("Array size %d\n", size);
}

void merge_sort(int start, int end, int input_list[])
{
    if (start >= end) return;

    int middle = (start + end) / 2;

    merge_sort(start, middle, input_list);
    merge_sort(middle + 1, end, input_list);

    combine(start, end, input_list);
}

void combine(int start, int end, int input_list[])
{
    int size = end - start + 1;
    int temp_list[size];

    int middle = (start + end) / 2;
    int left = start;
    int right = middle + 1;

    for (int idx = 0; idx < size; idx++) {
        // If true, then everything remaining is in the right
        if (left > middle)
            temp_list[idx] = input_list[right++];

        // If true, then everything remaining is in the left
        else if (right > end)
            temp_list[idx] = input_list[left++];

        else if (input_list[left] <= input_list[right])
            temp_list[idx] = input_list[left++];

        else
            temp_list[idx] = input_list[right++];
    }

    // Copy the temp list back to our primary array
    for (int i = 0; i < size; i++)
        input_list[start + i] = temp_list[i];
}


void print_array(int size, int input_list[])
{
    for (int first = 0; first < size; first++)
        printf("%d ", input_list[first]);

    printf("\n");
}


