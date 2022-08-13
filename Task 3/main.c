#include <stdio.h>

int main() {
    int array[100];
    int choice;
    int exit = 1;
    int size = 0;
    int new = 0;
    int i = 0,j = 0,temp = 0;
    while (exit == 1)
    {
        printf("to add element to array press: 1\n");
        printf("to sort array in ascending order press: 2\n");
        printf("to sort array in descending order press: 3\n");
        printf("to print array press: 4\n");
        printf("to exit press: 5\n");

        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("enter new array element\n");
                scanf("%d", &new);
                array[size] = new;
                size++;
                break;

            case 2:
                for (i = 0; i < size; i++)
                {
                    for (j = i + 1; j < size; j++)
                    {
                        if (array[i] > array[j])
                        {
                            temp =  array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                break;

            case 3:
                for (i = 0; i < size; i++)
                {
                    for (j = i + 1; j < size; j++)
                    {
                        if (array[i] < array[j])
                        {
                            temp =  array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                break;

            case 4:
                printf("array : \n");

                for (i = 0; i < size; ++i)
                    printf("%d\n", array[i]);
                printf("\n");
                break;

            case 5:
                exit = 0;
                break;

            default:
                printf("Wrong choice!! please choose a valid number\n");
        }
    }
}
