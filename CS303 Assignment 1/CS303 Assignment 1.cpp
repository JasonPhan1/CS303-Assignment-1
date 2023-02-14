//Name: Jason Phan
//E-mail: jtpdhg@umsystem.edu
//CS303
//Date: 2/11/2023
#include "functions.h"

int main()
{

	int* currentArray = new int[1];
	int arrSize = 0;

	ifstream inFile;
	inFile.open("input.txt");

	readFile(inFile, currentArray, arrSize);

	char c = 'z';
	while (c != '0')
	{
		c = printMenu();
		switch (c) {
			// finding the index with case 1
		case '1':
			try {
				int num;
				cout << "Enter value: ";
				cin >> num;
				cout << endl;
				int index = searchIndex(currentArray, num, arrSize);
				if (index == -1)
				{
					cout << "Value not found" << endl << endl;
				}
				else cout << "Value found at index: " << index << endl << endl;
			}
			catch (exception& e)
			{
				cerr << e.what() << endl;
			}
			printArray(currentArray, arrSize);
			break;

			// editing value with case 2
		case '2':
			try {
				int index;
				cout << "Enter value: ";
				cin >> index;
				cout << endl;
				if (index < 0 || index > arrSize)
				{
					cout << "Please enter a valid number";
				}
				editNumber(currentArray, index, arrSize);
			}
			catch (exception& e)
			{
				cerr << e.what() << endl;
			}
			printArray(currentArray, arrSize);
			break;
			// appending to array with case 3
		case '3':
			try {
				int num;
				cout << "Enter value: ";
				cin >> num;
				cout << endl;
				addArray(currentArray, num, arrSize);
			}
			catch (exception& e)
			{
				cerr << "Not a valid input!" << endl;
			}
			printArray(currentArray, arrSize);
			break;
			// delete number of an index with case 4
		case '4':
			
			try {
				int index;
				cout << "Enter index: ";
				cin >> index;
				cout << endl;
				if (index < 0 || index > arrSize)
				{
					cout << "Please enter a valid number";
				}
				removeNumber(currentArray, index, arrSize);
			}
			catch (exception& e)
			{
				cerr << e.what() << endl;
			}
			printArray(currentArray, arrSize);			break;

		default:
			break;
		}
	}
	inFile.close();
}
