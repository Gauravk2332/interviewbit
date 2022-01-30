/*
Problem Description

Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:
Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.


Problem Constraints

1 <= |A| <= 1005


Input Format

First and only argument is an string A.


Output Format

Return a integer denoting the length of longest palindromic subsequence in A.


Example Input

Input 1:

 A = "bebeeed"



Example Output

Output 1:

 4



Example Explanation

Explanation 1:

 The longest common pallindromic subsequence is "eeee", which has a length of 4

*/

##my solution
``` int
Solution::solve(string A)
{
    int n = A.size();
    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }

    for (int i = n - 2; i >= 0; i--) // --> tricky part --> filling of matrix
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    return dp[0][n - 1];
}
```