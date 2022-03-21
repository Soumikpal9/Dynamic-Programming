/*

        Problem Description

        Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

        You have the following 3 operations permitted on a word:

        Insert a character
        Delete a character
        Replace a character


        Problem Constraints

        1 <= length(A), length(B) <= 450



        Input Format

        The first argument of input contains a string, A.
        The second argument of input contains a string, B.



        Output Format

        Return an integer, representing the minimum number of steps required.



        Example Input

        Input 1:

        A = "abad"
        B = "abac"
        Input 2:

        A = "Anshuman"
        B = "Antihuman


        Example Output

        Output 1:

        1
        Output 2:

        2


        Example Explanation

        Exlanation 1:

        A = "abad" and B = "abac"
        After applying operation: Replace d with c. We get A = B.
        
        Explanation 2:

        A = "Anshuman" and B = "Antihuman"
        After applying operations: Replace s with t and insert i before h. We get A = B.

*/

int minCost(string A, string B, int i, int j, vector<vector<int>> &dp){
    if(i==-1 && j==-1)  return 0;
    else if(j==-1)  return i+1;
    else if(i==-1)  return j+1;
    if(dp[i][j]!=-1)    return dp[i][j];
    if(A[i]==B[j]){
        dp[i][j]=minCost(A, B, i-1, j-1, dp);
    }  
    else{
        dp[i][j]=min({1+minCost(A, B, i, j-1, dp), 1+minCost(A, B, i-1, j-1, dp), 1+minCost(A, B, i-1, j, dp)});
    }
    return dp[i][j];
}

int Solution::solve(string A, string B){
    vector<vector<int>> dp(A.size(), vector<int> (B.size(), 0));
    return minCost(A, B, A.size()-1, B.size()-1, dp);
}