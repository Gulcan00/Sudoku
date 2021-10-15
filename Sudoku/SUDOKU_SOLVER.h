/** \file SUDOKU_SOLVER.h
*	\brief Contains class for the sudoku game 
*	\author Gulcan Damdelen
*	\date 04/10/2021
*/
#pragma once

#include <iostream>
using namespace std;

const int N = 9;


class Sudoku {
public:
	void initializeGrid();
	void insert(int row, int col, int num);
	void remove(int row, int col);
	bool isValid(int row, int col, int num) const; //checks if number is valid
	bool findUnassignedLocation(int& row, int& col); //finds first unassigned empty cell
	void displayGrid() const; //displays the grid
private:
	int grid[N][N] = { {5,3,0,0,7,0,0,0,0},
  {6,0,0,1,9,5,0,0,0},
  {0,9,8,0,0,0,0,6,0},
  {8,0,0,0,6,0,0,0,3},
  {4,0,0,8,0,3,0,0,1},
  {7,0,0,0,2,0,0,0,6},
  {0,6,0,0,0,0,2,8,0},
  {0,0,0,4,1,9,0,0,5},
  {0,0,0,0,8,0,0,7,9}, };
};

//Function prototypes
void solve(Sudoku& grid, int row, int col);

//generate a sudoku grid
void Sudoku::initializeGrid()
{
	
}

/**
* <code>insert</code> inserts a number into the grid at 
* @param row The row position to insert the number
* @param col The column position to insert the number
* @param num The number to insert into grid
*/
void Sudoku::insert(int row, int col, int num)
{
	grid[row][col] = num;
}

/**
* <code>remove</code> removes a number from the grid at
* @param row The row position of number to remove 
* @param col The column position of number to remove 
* @param num The number to be removed from grid
*/
void Sudoku::remove(int row, int col)
{
	grid[row][col] = 0;
}

bool Sudoku::isValid(int row, int col, int num) const 
{
	int i, j;
	//check the column 
	for (i = 0; i < N; i++)
	{
		if (i == row || grid[i][col] == 0)
			continue;
		if(num == grid[i][col])
			return false;
	}
	//check the row
	for (i = 0; i < N; i++)
	{
		if (i == col || grid[row][i] == 0)
			continue;
		if(num == grid[row][i])
			return false;
	}
	//check the grid
	if (row % 3 == 1)
		i = row - 1;
	else if (row % 3 == 2)
		i = row - 2;
	else i = row;
	for (int m = 0; m < 3; m++, i++)
	{
		if (col % 3 == 1)
			j = col - 1;
		else if (col % 3 == 2)
			j = col - 2;
		else j = col;
		for (int k = 0; k < 3; k++, j++)
		{
			if ((i == row && j == col) || grid[i][j] == 0)
				continue;
			if(num == grid[i][j])
				return false;
		}
	}
	return true;
}

bool Sudoku::findUnassignedLocation(int& row, int& col)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j] == 0)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	row = 0; 
	col = 0;
	return false;
}

//make it look nicer
void Sudoku::displayGrid() const
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << grid[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void solve(Sudoku& grid, int row, int col)
{
	if (!grid.findUnassignedLocation(row, col))
		grid.displayGrid();
	else {
		for (int i = 1; i <= N; i++)
		{
			if (grid.isValid(row, col, i)) {
				grid.insert(row, col, i);
				solve(grid, row, col);
				grid.remove(row, col);
			}
		}
	}
}

