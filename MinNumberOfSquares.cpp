/*

        Problem Description

        Given an integer A. Return minimum count of numbers, sum of whose squares is equal to A.



        Problem Constraints

        1 <= A <= 105



        Input Format

        First and only argument is an inetegr A.



        Output Format

        Return an integer denoting the minimum count.



        Example Input

        Input 1:

        A = 6
        Input 2:

        A = 5


        Example Output

        Output 1:

        3
        Output 2:

        2


        Example Explanation

        Explanation 1:

        Possible combinations are : (12 + 12 + 12 + 12 + 12 + 12) and (12 + 12 + 22).
        Minimum count of numbers, sum of whose squares is 6 is 3. 
        Explanation 2:

        We can represent 5 using only 2 numbers i.e. 12 + 22 = 5

*/

int perfSquares(int n, vector<int> &dp){
    if(n==0)    return 0;
    if(dp[n]!=-1)   return dp[n];
    dp[n]=1;
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++){
        ans=min(ans, perfSquares(n-(i*i), dp));
    }
    dp[n]+=ans;
    return dp[n];
}

int Solution::solve(int A){
    vector<int> dp(A+1, -1);
    return perfSquares(A, dp);
}