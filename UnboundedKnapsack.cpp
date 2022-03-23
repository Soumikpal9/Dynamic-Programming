/*

        Problem Description

        Given a knapsack weight A and a set of items with certain value B[i] and weight C[i], we need to calculate maximum amount that could fit in this quantity.

        This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.



        Problem Constraints

        1 <= A <= 1000

        1 <= |B| <= 1000

        1 <= B[i] <= 1000

        1 <= C[i] <= 1000



        Input Format

        First argument is the Weight of knapsack A

        Second argument is the vector of values B

        Third argument is the vector of weights C



        Output Format

        Return the maximum value that fills the knapsack completely



        Example Input

        Input 1:

        A = 10
        B = [5]
        C = [10]
        Input 2:

        A = 10
        B = [6, 7]
        C = [5, 5]


        Example Output

        Output 1:

        5
        Output 2:

        14


        Example Explanation

        Explanation 1:

        Only valid possibility is to take the given item.
        Explanation 2:

        Take the second item twice.

*/

int unboundedKnapsack(vector<int> &A, vector<int> &B, int i , int j, vector<vector<int>> &dp){
    if(i==0 || j==0)    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    if(j>=B[i-1]){
        dp[i][j]=max(unboundedKnapsack(A, B, i-1, j, dp), A[i-1]+unboundedKnapsack(A, B, i, j-B[i-1], dp));
    }
    else{
        dp[i][j]=unboundedKnapsack(A, B, i-1, j, dp);
    }
    return dp[i][j];
}

int Solution::solve(vector<int> &A, vector<int> &B, int C){
    vector<vector<int>> dp(B.size()+1, vector<int> (C+1, -1));
    return unboundedKnapsack(A, B, B.size(), C, dp);
}