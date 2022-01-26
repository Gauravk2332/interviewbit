/* Problem Statement:
Given a N\*N board with the Knight placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each cell in which they are visited.

Naive Algorithm for Knight’s tour
The Naive Algorithm is to generate all tours one by one and check if the generated tour satisfies the constraints.

while there are untried tours
{
generate the next tour
if this tour covers all squares
{
print this path;
}
}

Backtracking works in an incremental way to attack problems. Typically, we start from an empty solution vector and one by one add items (Meaning of item varies from problem to problem. In the context of Knight’s tour problem, an item is a Knight’s move). When we add an item, we check if adding the current item violates the problem constraint, if it does then we remove the item and try other alternatives. If none of the alternatives works out then we go to the previous stage and remove the item added in the previous stage. If we reach the initial stage back then we say that no solution exists. If adding an item doesn’t violate constraints then we recursively add items one by one. If the solution vector becomes complete then we print the solution.

Backtracking Algorithm for Knight’s tour

Following is the Backtracking algorithm for Knight’s tour problem.

If all squares are visited
print the solution
Else
a) Add one of the next moves to solution vector and recursively
check if this move leads to a solution. (A Knight can make maximum
eight moves. We choose one of the 8 moves in this step).
b) If the move chosen in the above step doesn't lead to a solution
then remove this move from the solution vector and try other
alternative moves.
c) If none of the alternatives work then return false (Returning false
will remove the previously added item in recursion and if false is
returned by the initial call of recursion then "no solution exists"
*/

##solution

#include <iostream>
    using namespace std;
#define N 8
int isSafe(int x, int y, int sol[N][n])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

int solveKT(int x, int y, int move, int sol[N][n], int xMove[N], int yMove[N])
{
    if (move == N * N)
        return 1;

    for (int i = 0; i < 8; i++)
    {
        int xNext = x + xMove[i];
        int yNext = y + yMove[i];

        if (isSafe(xNext, yNext, sol))
        {
            sol[xNext][yNext] = move;
            if (solveKT(xNext, yNext, move + 1, sol, xMove, yMove) == 1)
                return 1;
            else
                sol[xNext][yNext] = -1;
        }
    }
    return 0;
}

int main()
{
    int sol[N][n];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = -1;

    // int xMove[8] = {2, 2, -2, -2, 1, -1, 1, -1}; -- > this direction sequence will give TLE
    // int yMove[8] = {1,-1,1,-1,2,2,-2,-2};

    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    sol[0][0] = 0;

    if (solveKT(0, 0, 1, sol, xMove, yMove) == 1) // solution exist
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}

/*
Time Complexity : 
There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from, so the worst running time is O(8N^2).

Auxiliary Space: O(N2)

Important Note:
No order of the xMove, yMove is wrong, but they will affect the running time of the algorithm drastically. For example, think of the case where the 8th choice of the move is the correct one, and before that our code ran 7 different wrong paths. It’s always a good idea a have a heuristic than to try backtracking randomly. Like, in this case, we know the next step would probably be in the south or east direction, then checking the paths which lead their first is a better strategy.
*/