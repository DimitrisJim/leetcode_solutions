class Solution:
    def minCostClimbingStairs(self, cost):
        cost_len = len(cost)
        table_len = cost_len + 2
        table = [10 ** 6] * table_len
        table[0] = 0
        for i in range(1, table_len):
            prev = table[i-1]
            table[i] = min(
                table[i],
                prev + (cost[i-1] if i < cost_len else 0)
            )
            if (j := i + 1) < table_len:
                table[j] = min(
                    table[j],
                    prev + (cost[i] if i < cost_len else 0)
                )
        # return final element.
        return table[-1]
