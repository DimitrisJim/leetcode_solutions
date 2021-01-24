class Solution:
    def largestAltitude(self, gain):
        max_height, height_i = 0, 0
        for i in gain:
            height_i = height_i + i
            if height_i > max_height:
                max_height = height_i
        return max_height
