class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
       
		## APPROACH : DP ##
		## Similar to Leetcode 416. partition equal subset sum ##
		## LOGIC ##
		#	1. This problem can be decomposed to 0/1 Knapsack Problem, where you have n items with each having its own weight w and own profit p, 
        #      We have a limitation on maximum weight of the items that we can carry in a bag, so what is the maximum profit that can be achieved within the weight limit of the bag.
		#	2. m, n are the similar to limitations of the bag, strings being with items with weight w
		#	3. Each cell in DP indicates the number of strings that can be achieved with i zeros and j ones. We iterate with all strings and fill the matrix
        
		## TIME COMPLEXITY : O(Nx(mxn)) ##
		## SPACE COMPLEXITY : O(mxn) ##

        ## EXAMPLE ["10","0001","111001","1","0"] 5 3 ##
        ## STACK TRACE ##
        # [[0, 0, 0, 0], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1]]
        # [[0, 0, 0, 0], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 2, 2], [0, 1, 2, 2]]
        # [[0, 0, 0, 0], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 2, 2], [0, 1, 2, 2]]
        # [[0, 1, 1, 1], [0, 1, 2, 2], [0, 1, 2, 2], [0, 1, 2, 2], [0, 1, 2, 3], [0, 1, 2, 3]]
        # [[0, 1, 1, 1], [1, 2, 2, 2], [1, 2, 3, 3], [1, 2, 3, 3], [1, 2, 3, 3], [1, 2, 3, 4]]
        
        ## WATCH OUT FOR LOOPS,
        ## 1. We are traversing reverse to prevent sub problem overlapping, consider string "01" and m = 5, n = 3 and draw matrix from normal order and in reverse order, you'll understand
        ## 2. The lower limit is number of zeros and ones, coz before that you wont find any match
        dp = [[ 0 ] * (n+1) for _ in range(m+1)]
        for s in strs:
            zeros, ones = s.count("0"), s.count("1")
            for i in range(m, zeros - 1, -1):
                for j in range(n, ones - 1, -1):
                    # dp[i][j] indicates it has i zeros and j ones, can this string be formed with those ?
                    dp[i][j] = max( 1 + dp[i - zeros][j- ones], dp[i][j] )
            # print(dp)
        return dp[-1][-1]
        