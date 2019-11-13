/* Find maximum score that maximum player can get */
#include <bits/stdc++.h>
using namespace std;

/*
			MAX                                 12
			MIN 				5								12
			MAX 		5				9				12             23
			MIN     3		5		2       9      12      5     23       23
/* Return the optimal value a maximizer can obtain */
/* Depth is current depth in game tree */
/* nodeINdex is index of current node in scores[] */
/* isMAx is tue if current move is of maximizer */
/* else false scores[] stores leaves of Game tree */
/* h is maximum height of Game tree */

int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h)
{
	/* Terminating condition leaf node is reached */
	if(depth == h)
	{
		return scores[nodeIndex];
	}

	/* If current move is maximizer, find the maximum attainable value */
	if (isMax)
	{
		return max(minimax(depth+1, nodeIndex*2, 	 false, scores, h),
				   minimax(depth+1, nodeIndex*2 + 1, false, scores, h));
	}
	/* If current move is minimizer then find the minimum attainable value */
	else
	{
		return min(minimax(depth+1, nodeIndex*2, 	 true, scores, h),
				   minimax(depth+1, nodeIndex*2 + 1, true, scores, h));
	}
	/* isMax value is switched due to MAX and MIN user will take turn sequently */
}

/* A utility function to find Log n in base 2 */
int log2(int n)
{
	if (n==1)
	{
		return 0;
	}
	else
	{
		return 1 + log2(n/2);
	}

}

int main()
{
	/* The number of elements in scores must be a power of 2 */
	int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
	int n = sizeof(scores)/sizeof(scores[0]);
	int h = log2(n);
	int res = minimax(0, 0, true, scores, h);
	cout << "The optimal value is: " << res << endl;
	return 0;
}
