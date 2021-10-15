/** \file Sudoku.cpp 
*   \brief 
*   \author Gulcan Damdelen
*   \date 02/10/2021
*/

#include <iostream>
#include "SUDOKU_SOLVER.h"
using namespace std;

int main()
{
	Sudoku board;
	cout << "Welcome to SUDOKU!\n";

	int choice, row, col, num;
	bool solved = false;
	do {
		board.displayGrid();
		cout << "\n1) Enter number ";
		cout << "\n2) Sudoku solution";
		cout << "\nEnter choice: ";
		cin >> choice;

		solved = !board.findUnassignedLocation(row, col);
		if (choice == 1) {
			do {
				cout << "Enter row (1 - 9): ";
				cin >> row;
			} while (row < 1 || row > 9);
			do {
				cout << "Enter column (1 - 9): ";
				cin >> col;
			} while (col < 1 || col > 9);
			do {
				cout << "Enter number (1 - 9): ";
				cin >> num;
			} while (num < 1 || num > 9);

			if (board.isValid(row, col, num))
				board.insert(row, col, num);
			else cout << "Invalid move!";
		}
		else if (choice == 2) {
			cout << "The solution is: \n";
			solve(board, 0, 0);
			solved = true;
		}
		else cout << "Invalid option!";
	} while (!solved);
	
	cout << "Goodbye!\n";
	return 0;
}

