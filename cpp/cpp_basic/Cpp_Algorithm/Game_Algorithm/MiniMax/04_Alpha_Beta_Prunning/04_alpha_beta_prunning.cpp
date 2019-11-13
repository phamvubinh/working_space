#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
const int MIN = -1000;

/* Return optimal value for current player
   Initially called for root and maximizer */
int minimax(int depth, int nodeIndex, bool maximizingPlayer,
	        int values[], int alpha, int beta)
{
	/* Reach the last depth, need to return value */
	if(depth == 3)
	{
		return values[nodeIndex];
	}

	if(maximizingPlayer)
	{
		int best = MIN;
		/* Recur for left and right children */
		for (int i = 0; i < 2; ++i)
		{
			int val = minimax(depth+1, nodeIndex*2 + i, false,
							  values, alpha, beta);

			best  = max(best, val);
			alpha = max(alpha, best);

			/* Alpha Beta prunning */
			if(beta <= alpha)
			{
				break;
			}
		}
		return best;
	}
	else
	{
		int best = MAX;
		/* Recur for left and right children */
		for(int i = 0; i < 2; i++)
		{
			int val = minimax(depth + 1, nodeIndex*2 + i, true,
				              values, alpha, beta);
			best = min(best, val);
			beta = min(beta, best);

			/* Alpha Beta prunning */
			if(beta <= alpha)
			{
				break;
			}
		}
		return best;
	}
}

int main()
{
	int values[8] = {3, 5, 6, 9, 1, 2, 0, -1};
	cout << "The optimal value is: " << minimax(0, 0, true, values, MIN, MAX);
	return 0;
}