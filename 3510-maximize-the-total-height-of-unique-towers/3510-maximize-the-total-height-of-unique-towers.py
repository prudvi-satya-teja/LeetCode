class Solution:
    def maximumTotalSum(self, maximumHeight: List[int]) -> int:
        maximumHeight.sort(reverse=True)
        for i in range(len(maximumHeight)-1):
            if maximumHeight[i] <= maximumHeight[i+1]:
                maximumHeight[i+1]=maximumHeight[i]-1
            if maximumHeight[i+1]==0:
                return -1
        return sum(maximumHeight)
        
        