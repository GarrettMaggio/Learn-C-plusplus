// This example shows example of how to take in input from a file
// , sort the file and search the file for a given entry

# include <iostream>
# include <fstream>
# include "Header.h"
# include <iomanip>
# include <string>

using namespace std;

// global variables
ifstream inputfile;
const int Size = 10;
int value, leftBoundary, rightBoundary;

// function prototypes
void get_gmData(string[], int[], double[], int);
void prt_gmData(string[], int[], double[], int);
void sort_gmData(string[], int[], double[], int);
int search_gmData(int[], int, int, int, int);


int main()
{
	string name_Array[Size]; // array for the names
	//string *Name = name_Array; // pointer for name_Array
	int year_Array[Size]; // array for year
	//int *Year = year_Array; // pointer for year_Array
	double tuit_Array[Size]; // array for tuition
	//double* Tuition = tuit_Array; // pointer for tuit_Array
	int size = 10;
	int returnValue;



	// function calls
	head();
	get_gmData(name_Array, year_Array, tuit_Array, size);
	inputfile.close();// closes the input file.
	cout << left << "Original Data" << endl;
	prt_gmData(name_Array, year_Array, tuit_Array, size);
	sort_gmData(name_Array, year_Array, tuit_Array, size);
	cout << left << "Sorted Data" << endl;
	prt_gmData(name_Array, year_Array, tuit_Array, size);
	returnValue = search_gmData(year_Array, value, leftBoundary, rightBoundary, size);

	if (returnValue != -1) // determines if the year exist in the data.
	{
		cout << "Record present" << endl;
		cout << name_Array[returnValue] << "\t\t" << year_Array[returnValue] << "\t\t" << tuit_Array[returnValue] << endl;
	}
	else
	{
		cout << " Sorry record not found " << endl;
	}

	return 0;
}

// gets the data from the data file
void get_gmData(string names[], int year[], double tuition[], int size)
{

	inputfile.open("index.txt"); // opens the data file

	if (!inputfile)
	{
		cout << "failed to open file" << endl;
	}

	for (int count = 0; count < size; count++)
	{
		inputfile >> names[count] >> year[count] >> tuition[count]; // gets the data from the data file and stores
		// in the arrays
	}

}

void prt_gmData(string names[], int years[], double tuition[], int sizeOf)
{
	cout << left << "Name" << setw(15) << "\t" << "Year" << setw(15) << "\t" << "Tuition" << endl; // formatting

	for (int i = 0; i < sizeOf; i++)
	{
		cout << left << names[i] << setw(15) << "\t" << years[i] << setw(15) << "\t" << tuition[i] << endl;
		// prints the data
	}
	cout << endl;
}

void sort_gmData(string Names[], int Years[], double Tuition[], int Size)
{

	for (int i = 0; i < (Size -1) ; i++)
	{
		int minValue = i;
		for (int j = i + 1; j < Size; j++)
		{
			if ( Years[j] < Years[minValue])
			{
				minValue = j;
			}
			// sorts the years
			int TempYear = Years[i];
			Years[i] = Years[minValue];
			Years[minValue] = TempYear;


			// sorts the names
			string temp_Name = Names[i];
			Names[i] = Names[minValue];
			Names[minValue] = temp_Name;

			// sorts the tuitions
			double temp_tuition = Tuition[i];
			Tuition[i] = Tuition[minValue];
			Tuition[minValue] = temp_tuition;
		}

	}
}

// searches for a value
int search_gmData(int yearSearch[], int targetVal, int leftBound, int rightBound, int size)
{
	// defines the boundaries of the search.
	leftBound = 0;
	rightBound = size - 1;



	cout << "Please enter the year you wish to search for " << endl;
	cin >> targetVal; // holds the value being searched for.

	while (leftBound <= rightBound) // loop to find the searched value.
	{
		int middle = leftBound + (rightBound - leftBound) / 2;

		if (yearSearch[middle] == targetVal)
		{
			return middle; // the year found
		}
		if (yearSearch[middle] < targetVal)
		{
			leftBound = middle + 1; // exacutes if the target value is less than the middle
		}
		else
		{
			rightBound = middle - 1; // exacutes if the target value is greater than the middle
		}
	}
	return -1; // year was not found
}
