#include "functions.h"

// printing menu 
char printMenu()
{
	cout << "1 - Find the index of a number" << endl;
	cout << "2 - Edit the value of an index" << endl;
	cout << "3 - Append a number to the array" << endl;
	cout << "4 - Remove a number from an index" << endl;
	cout << "0 - Quit" << endl;
	char c;
	cin >> c;
	cout << endl;
	return c;
}

void readFile(ifstream& in, int arr[], int& arrSize)
{
	stringstream stream;
	string readString;
	int num;
	while (getline(in, readString)) {
		stream.clear();
		stream.str(readString);
		while (stream >> num)
		{
			addArray(arr, num, arrSize);
		}
	}
}

int searchIndex(int arr[], int num, int& arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (num == arr[i])
		{
			return i;
		}
	}
	return -1;
}

void editNumber(int arr[], int index, int& arrSize)
{
	try
	{
		int input;
		cout << "What value do you want to edit " << arr[index] << " to? " << endl;
		cin >> input;
		cout << arr[index] << " was edited to " << input << endl;
		arr[index] = input;
	}
	catch (exception& e)
	{
		cerr << "Invalid input" << endl;
	}
}

void addArray(int arr[], int num, int& arrSize)
{
	growArray(arr, 1, arrSize);
	arr[arrSize - 1] = num;
}

void growArray(int arr[], int size, int& arrSize)
{
	int oldSize = arrSize;
	//Calculate the new size
	arrSize += size;
	int* newArray = new int[arrSize];
	//Old array points to new with correct size
	std::copy(arr, arr + std::min(oldSize, arrSize), newArray);
	arr = newArray;
	delete[] newArray;
}

void removeArray(int arr[], int size, int& arrSize)
{
	//Store size of old array
	int oldSize = arrSize;
	//Calculate the new size
	arrSize += size;
	// Make a new array that our pointer will point to
	int* newArray = new int[arrSize];
	//Old array points to new with correct size
	std::copy(arr, arr + std::min(oldSize, arrSize), newArray);
	arr = newArray;
	delete[] newArray;
}

void removeNumber(int arr[], int index, int& arrSize)
{
	cout << arr[index] << " was removed" << endl << endl;
	for (int i = index; i < arrSize; ++i)
		arr[i] = arr[i + 1]; 
	removeArray(arr, -1, arrSize);
}

void printArray(int arr[], int& arrSize)
{
	cout << "[ ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl << endl;

}
