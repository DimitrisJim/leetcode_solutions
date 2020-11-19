class Solution:      
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        step = arr[1] - arr[0]
        return all(arr[i] == step + arr[i-1] for i in range(2, len(arr)))
