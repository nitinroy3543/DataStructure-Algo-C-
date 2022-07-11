class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for row in range(1,len(triangle)):
            for col in range(row + 1):
                small_above = math.inf
                if col>0:
                    small_above = triangle[row-1][col-1]
                if col<row:
                    small_above = min(small_above, triangle[row-1][col])
                triangle[row][col] += small_above
        return min(triangle[-1])
            