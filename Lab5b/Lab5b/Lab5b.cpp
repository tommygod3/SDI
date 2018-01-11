// Lab5b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int maxLength = 6;

void swap(int *swap1, int *swap2);

void printArray(int array[], int size);

void selectionSort(int array[], int size);

void insertionSort(int array[], int size);

void bubbleSort(int array[], int size);

int main()
{
	int list[maxLength] = { 50,15,28,1,23,22 };
	printArray(list, maxLength);
	//selectionSort(list, maxLength);
	//insertionSort(list, maxLength);
	bubbleSort(list, maxLength);
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
	int i, j, k;
	for (i = 1; i < size; i++)
	{
		k = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > k)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = k;
		printArray(array, size);
	}
}

void bubbleSort(int array[], int size)
{
	bool flag = 0;
	while (flag == 0)
	{
		bool change = 0;
		for (int i = 0; i < size-1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				change = 1;
			}
		}
		if (change == 0)
		{
			flag = 1;
		}
		printArray(array, size);
	}
}