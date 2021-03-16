class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        index = 0  # set to type by default
        if ruleKey == 'color':
            index = 1
        elif ruleKey == 'name':
            index = 2
        
        # O(N) -- traverse list.
        return sum(1 for item in items if item[index] == ruleValue)
