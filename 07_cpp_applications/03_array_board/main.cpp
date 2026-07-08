#include <iostream>
using namespace std;

bool isConsecutiveFour(int values[][7]);
bool isConsecutiveFour(int values[], int size);
const int numberOfRows = 8;
const int numberOfColumns = 7;
const int maxNumberOfElementsInDiagonal = 10;

int main()
{
	int board[][7] =
	{
	{8, 1, 0, 6, 1, 6, 1},
	{0, 1, 1, 8, 2, 0, 1},
	{5, 2, 2, 1, 3, 2, 9},
	{6, 5, 6, 1, 1, 2, 1},
	{9, 1, 2, 3, 1, 3, 4},
	{5, 2, 2, 1, 3, 2, 9},
	{6, 5, 6, 1, 1, 2, 1},
	{9, 1, 2, 3, 1, 3, 4},
	};
	
	cout << (isConsecutiveFour(board)? "true" : "false") << endl;	
}

bool isConsecutiveFour(int values[][7])
{
	// Check rows
	for (int i = 0; i < numberOfRows; i++)
	{
		if (isConsecutiveFour(values[i], numberOfRows))
		return true;
	}
	
	// Check columns
	for (int j = 0; j < numberOfColumns; j++)
	{
		int column[numberOfRows];
		// Get a column
		for (int i = 0; i < numberOfRows; i++)
		column[i] = values[i][j];
	
	if (isConsecutiveFour(column, numberOfRows))
		return true;	
	}
	
	// Check major diagonal down 
	for (int i = 0; i < numberOfRows - 3; i++)
	{
		int numberOfElementsInDiagonal
		= min(numberOfRows - i, numberOfColumns);
		int diagonal[maxNumberOfElementsInDiagonal];
		for (int k = 0; k < numberOfElementsInDiagonal; k++)
		diagonal[k] = values[k+i][k];
		
		if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
		return true;
	}
	
	// Check major diagonal up
	for (int j = 1; j < numberOfColumns - 3; j++)
	{
		int numberOfElementsInDiagonal
		= min(numberOfColumns - j, numberOfRows);
		int diagonal[maxNumberOfElementsInDiagonal];
		for (int k = 0; k < numberOfElementsInDiagonal; k++)
		diagonal[k] = values[k][k+j];
		
		if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
		return true;
	}
	
	// Check major diagonal left
	for (int j = 3; j < numberOfColumns; j++)
	{
		int numberOfElementsInDiagonal = min(j + 1, numberOfRows);
		int diagonal[maxNumberOfElementsInDiagonal];
		for (int k = 0; k < numberOfElementsInDiagonal; k++)
		diagonal[k] = values[k][j - k];
		
		if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
		return true;
	}
	
	// Check major diagonal right
	for (int i = 1; i < numberOfRows - 3; i++)
	{
		int numberOfElementsInDiagonal 
		= min(numberOfRows - i, numberOfColumns);
		int diagonal[maxNumberOfElementsInDiagonal];
		for (int k = 0; k < numberOfElementsInDiagonal; k++)
		diagonal[k] = values[k + i][numberOfColumns - k - 1];
		
		if (isConsecutiveFour(diagonal, numberOfElementsInDiagonal))
		return true;
	}

	return false;
	
}

bool isConsecutiveFour(int values[], int size)
{
	for (int i = 0; i < size - 3; i++)
	{
		bool isEqual = true;
		for (int j = i; j < i + 3; j++)
	{
		if (values[j] != values[j + 1])
		{
			isEqual = false;
			break;
		}
	}
	
	if (isEqual) return true;
	}
	
	return false;
}
