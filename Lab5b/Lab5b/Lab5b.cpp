// Lab5b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int maxLength = 6;

void swap(int *swap1, int *swap2);

void printArray(int array[], int size);

void selectionSort(int array[], int size);

void insertionSort(int array[], int size);

int main()
{
	int list[maxLength] = { 50,15,28,1,23,22 };
	printArray(list, maxLength);
	selectionSort(list, maxLength);
    return 0;
}

void swap(int *swap1, int *swap2)
{
	int temp = *swap1;
	*swap1 = *swap2;
	*swap2 = temp;
}

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void selectionSort(int array[], int size)
{
	//Change boundary one by one
	for (int i = 0; i < size-1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		swap(&array[minIndex], &array[i]);
		printArray(array, size);
	}
}

void insertionSort(int array[], int size)
{
	//
}