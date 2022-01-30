/*
Problem Description

Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.

Problem Constraints

1 <= |A|, |B| <= 1005

Input Format

First argument is an string A.

Second argument is an string B.

Output Format

Return the length of such longest common subsequence between string A and string B.

Example Input

Input 1:

A = "abbcdgf"
B = "bbadcgf"

Example Output

Output 1:

5

Example Explanation

Explanation 1:

The longest common subsequence is "bbcgf", which has a length of 5
*/

##my solution

    // int maxLength(string A,int n,string B,int m) // ---> recursive solution
    // {
    // if(n<=0 || m<=0)
    // return 0;

    // if(A[n-1]==B[m-1])
    // return 1 + maxLength(A,n-1,B,m-1);
    // else
    // return max(maxLength(A,n,B,m-1),maxLength(A,n-1,B,m));
    // }
    int
    Solution::solve(string A, string B)
{
  // return maxLength(A,A.size(),B,B.size()); // - recursive solution
  int n = A.size(), m = B.size();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {

      if (A[i - 1] == B[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  // for(int i=0;i<=n;i++)
  // {
  // for(int j=0;j<=m;j++)
  // cout<<dp[i][j]<<" ";
  // cout<<endl;
  // }
  return dp[n][m];
}
