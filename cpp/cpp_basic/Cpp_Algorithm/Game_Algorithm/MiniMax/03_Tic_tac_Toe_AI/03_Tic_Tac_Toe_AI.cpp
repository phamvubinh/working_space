#include <bits/stdc++.h>
using namespace std;

struct Move
{
	int row, col;
};

char player = 'x', opponent = 'o';

/* This function return true if there are moves remaining on the board
   It return false if there are no moves left to play
*/
bool isMoveLeft(char board[3][3])
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(board[row][col] == '_')
			{
				return true;
			}
		}
	}
	return false;
}

/* Return a value based on who is winning */
/* b[3][3] is the Tic-Tac-Toe board */
int evaluate(char b[3][3])
{
	/* Checking for rows for X or O victory */
	for(int row = 0; row < 3; row++)
	{
		if(b[row][0]==b[row][1] && b[row][1]==b[row][2])
		{
			if(b[row][0]=='x')
			{
				return +10;
			}
			else if (b[row][0]=='o')
			{
				return -10;
			}
		}
	}

	/* Checking for cols for X or O victory */
	for(int col = 0; col < 3; col++)
	{
		if(b[0][col]==b[1][col] && b[1][col]==b[2][col])
		{
			if(b[0][col]=='x')
			{
				return +10;
			}
			else if (b[0][col]=='o')
			{
				return -10;
			}
		}
	}

	/* Checking for Diagnals for victory */
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]=='x')
        {
            return +10;
        }
        else if (b[0][0]=='o')
        {
            return -10;
        }
    }

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]=='x')
        {
            return +10;
        }
        else if (b[0][2]=='o')
        {
            return -10;
        }
    }

    /* Else if none of them have won then return 0 */
    return 0;
}

/* This is the minimax function.
   It consider all the possible ways the game can go and returns the value of the board */
int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	/* If Maximizer or Minimizer has won the game, return game score */

	/* Use depth to find the result with smallest step */
	if (score == 10)
	{
		return score - depth;
	}

	if (score == -10)
	{
		return score + depth;
	}

	/* If there is no more moves and no winner then it is a tie */
	if (isMoveLeft(board) == false)
	{
		return 0;
	}

	/* If it is maximizer, try to find the maximum value */
	if(isMax)
	{
		int best = -1000;

		/* Traverse all cells */
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(board[i][j] == '_')
				{
					/* Make the move */
					board[i][j] = player;
					/* Call minimax recursively and choose the minimum value */
					best = max(best, minimax(board, depth+1, !isMax));
					/* Undo the move */
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;

		/* Traverse all cells */
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				/* Check if cell is empty */
				if (board[i][j] == '_')
				{
					board[i][j] = opponent;
					best = min(best, minimax(board, depth+1, !isMax));
					/* Undo the move */
					board[i][j] = '_';
				}
			}
		}
		return best;
	}

}

/* Return best possible move for the player */
Move findBestMove(char board[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	/* Traverse all cells, evaluate minimax function for all empty cells.
	   And return the cell with optimal value */

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/* Check if cell is empty */
			if(board[i][j] == '_')
			{
				board[i][j] = player;

				/* false value because next move is opponent */
				int moveVal = minimax(board, 0, false);

				/* Undo the move */
				board[i][j] = '_';

				/* If the value of the current move is move than the best value, then update best */
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	cout << "The value of best Move is: " << bestVal;

	return bestMove;
}

int main()
{
	char board[3][3] =
	{
		{'x', '_', '_'},
		{'o', '_', 'x'},
		{'o', '_', '_'},
	};

	Move bestMove = findBestMove(board);

	cout << "The optimal move is: " << endl;
	cout << "ROW " << bestMove.row << endl;
	cout << "COL " << bestMove.col << endl;

	return 0;
}