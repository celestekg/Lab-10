//Celeste Going
//Lab 10
/*This program generates an array with random numbers,
searches and sorts the array, and prints the array.
The user can choose an ascending or descending order
for the array to be sorted before printing the values.
The program also allows the user to search for a
particular value within the array and its position.*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int arr[100];
int arrSize;

void printMenu();
void dispatch(int choice);
void getSize();
void fillArray();
void printArray();
void sortArrayInAscending();
void sortArrayInDescending();
int sequentialSearch(int target);
int binarySearch(int target);

int main()
{
	int choice;

	printMenu();
	cout << "Type in a choice: " << endl;
	cin >> choice;
	while (choice != 0)
	{
		dispatch(choice);
		printMenu();
		cout << "Type in a choice: " << endl;
		cin >> choice;
	}

	cout << endl;
	cout << "This program was coded by Celeste Going." << endl;
	return 0;
}

void printMenu()
{
	cout << endl;
	cout << "------------------MENU------------------" << endl;
	cout << "0. Exit." << endl;
	cout << "1. Get the size needed for today's use of the array." << endl;
	cout << "2. Fill an array with random numbers from 1-100." << endl;
	cout << "3. Print the array with position numbers." << endl;
	cout << "4. Sort the array in ascending sequence." << endl;
	cout << "5. Sort the array in descending sequence." << endl;
	cout << "6. Sequential search of the array for a target." << endl;
	cout << "7. Binary search of the array for a target." << endl;
}

void dispatch(int choice)
{
	int target;
	int index;

	switch (choice)
	{
	case 1:
		getSize();
		break;

	case 2:
		fillArray();
		break;

	case 3:
		printArray();
		break;

	case 4:
		sortArrayInAscending();
		break;

	case 5:
		sortArrayInDescending();
		break;

	case 6:
		cout << "Enter a value to be searched: ";
		cin >> target;

		index = sequentialSearch(target);

		if (index != -1)
			cout << "Found in position " << index << endl;
		else
			cout << "Not Found." << endl;
		break;

	case 7:
		cout << "Enter a value to be searched: ";
		cin >> target;

		index = binarySearch(target);

		if (index != -1)
			cout << "Found in position " << index << endl;
		else
			cout << "Not Found." << endl;
		break;

	case 0:
		break;

	default:
		cout << "Invalid choice!" << endl;
	}
}

void getSize()
{
	cout << "Enter the size needed for today's use of the array: ";
	cin >> arrSize;
}

void fillArray()
{
	srand(time(NULL));

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = 1 + rand() % 100;
	}
}

void printArray()
{
	cout << endl << "POS\tVALUE" << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << i << "\t" << arr[i] << endl;
	}
}

void sortArrayInAscending()
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sortArrayInDescending()
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		int minPos = i;

		for (int j = i + 1; j < arrSize; j++)
		{
			if (arr[j] > arr[minPos])
			{
				minPos = j;
			}
		}

		if (minPos != i)
		{
			int temp = arr[minPos];
			arr[minPos] = arr[i];
			arr[i] = temp;
		}
	}
}

int sequentialSearch(int target)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == target)
			return i;
	}

	return -1;
}

int binarySearch(int target)
{
	int first = 0;
	int last = arrSize - 1;

	while (first <= last)
	{
		int middle = (first + last) / 2;

		if (arr[middle] == target)
			return middle;

		if (arr[middle] < target)
			first = middle + 1;
		else
			last = middle - 1;
	}

	return -1;
}