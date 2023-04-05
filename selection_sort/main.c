#include <stdio.h>
#include <stdlib.h>

void selection_sort(int size, int input_list[]);
void print_array(int size, int input_list[]);
void merge_sort(int start, int end, int input_list[]);
void combine(int start, int end, int input_list[]);


int main()
{
    int input_list[] = {4, 1, 454, 234, 232, 11, 2};
    int size = sizeof(input_list) / sizeof(int);

    selection_sort(size, input_list);
    print_array(size, input_list);

    return 0;
}


void selection_sort(int size, int input_list[])
{

    for (int first = 0; first < size; first++)
    {
        int min_value = input_list[first];

        for (int second = first + 1; second < size; second++)
        {

            if (input_list[second] < min_value)
            {
                min_value = input_list[second];

                input_list[second] = input_list[first];
                input_list[first] = min_value;
            }
        }
    }

    printf("Array size %d\n", size);

}





void merge_sort(int start, int end, int input_list[])
{
    if (start >= end) return;

    int middle = (end + start) / 2;

    merge_sort(start, middle, input_list);
    merge_sort(middle + 1, end, input_list);


}




void print_array(int size, int input_list[])
{
    for (int first = 0; first < size; first++)
    {
        printf("%d ", input_list[first]);
    }

    printf("\n");
}


