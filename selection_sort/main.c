#include <stdio.h>
#include <stdlib.h>

void selection_sort(int size, int input_list[]);
void print_array(int size, int input_list[]);


int main()
{
    int input_list[] = {4, 1, 454, 234, 232, 11, 2};

    int size = sizeof(input_list) / sizeof(int);

    selection_sort(size, input_list);

    printf("Main size %d\n", size);
    return 0;
}


void selection_sort(int size, int input_list[])
{

    for (first = 0; first < size; first++)
    {
        int min_value = input_list[first];

        for (second = first + 1; second < size; second++)
        {

            if (input_list[second] < min_value)
            {
                min_value = input[second];

                input_list[second] = input_list[first];
                input_list[first] = min_value;
            }
        }
    }

    printf("Array size %d\n", size);

}


void print_array(int size, int input_list[])
{

}


