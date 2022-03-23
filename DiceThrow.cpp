/*

        Problem Description

        Given sum A, number of ways you can get that sum with dice roll[1-6].

        As the number of ways can be large return its modulo by 1e9 + 7.



        Problem Constraints

        1 <= A <= 10 2


        Input Format

        The first argument is the integer A.


        Output Format

        Return an integer .


        Example Input

        Input 1:
        A = 3
        Input 2:

        A = 4


        Example Output

        Output 1:
        4
        Output 2:

        8


        Example Explanation

        Explanation 1:

        The four possible ways to obtain 3 are: [1, 1, 1], [1, 2], [2, 1] and [3].




        Explanation 2:

        The eight possible ways to obrain 8 are: [1, 1, 1, 1], [1, 1, 2], [1, 2, 1], [2, 1, 1], [1, 3], [3, 1], [2, 2], [4].

*/

int mod=1e9+7;

int diceThrow(int i, vector<int> &dp){
    if(i==0 || i==1)    return 1;
    if(dp[i]!=0)    return dp[i];
    for(int x=1;x<=6;x++){
        if(x<=i){
            dp[i]=(dp[i]+diceThrow(i-x, dp))%mod;
        }
    }
    return dp[i];
}

int Solution::solve(int A){
    vector<int> dp(A+1, 0);
    return diceThrow(A, dp);
}