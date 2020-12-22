class Solution:
    def reformatNumber(self, number: str) -> str:
        # Remove all '-' and ' '.
        number = number.translate({45: '', 32: ''})
        length = len(number)

        # find how many times to repeat and what will be left.
        left, repeat = length, 0
        while left > 4:
            left = left - 3
            repeat = repeat + 1

        # hold results
        result = []
        for i in range(0, repeat * 3, 3):
            result.append(number[i:i+3])

        # here we have left characters left:
        if left == 4:
            result.append(number[length-4:length-2])
            result.append(number[length-2:])
        else:
            result.append(number[length-left:])
        # join on '-'
        return "-".join(result)
