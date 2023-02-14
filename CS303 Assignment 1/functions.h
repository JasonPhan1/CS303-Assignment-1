
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

char printMenu();
//PRE: none
//POST: print the menu and return the user's choice

void readFile(ifstream& inFile, int arr[], int& arrSize);
//PRE: have an input file
//POST: reads through the input file and sets up the array

int searchIndex(int arr[], int num, int& arrSize);
//PRE: have an array
//POST: find the index of a number in the array

void editNumber(int arr[], int index, int& arrSize);
//PRE: have an array
//POST: change the value of an index in the array

void addArray(int arr[], int num, int& arrSize);
//PRE: have an array
//POST: adds a number to the end of the array

void growArray(int arr[], int size, int& arrSize);
//PRE: have an array
//POST: resizes array to fit if something was added or taken out (add in this case)

void removeArray(int arr[], int size, int& arrSize);
//PRE: have an array
//POST:resizes array to fit if something was added or taken out (subtract in this case)

void removeNumber(int arr[], int index, int& arrSize);
//PRE: have an array
//POST: remove a number from an index of the array

void printArray(int arr[], int& arrSize);
//PRE: have an array
//POST: print the array