class Solution:
    def calPoints(self, ops):
        def handle_cases(op, score):
            if op == 'C':
                score.pop()
            elif op == '+':
                score.append(score[-1] + score[-2])
            elif op == 'D':
                score.append(score[-1] * 2)
            else:
                # number
                score.append(int(op))

        # Guaranteed to start with an int.
        score, len_, i = [int(ops[0])], len(ops), 1
        while (i < len_ - 1):
            op1 = ops[i]
            if ops[i+1] == 'C' and op1 != 'C':
                # skip if op2 is C and op1 isn't C.
                i = i + 2
                continue
            handle_cases(op1, score)
            i = i + 1
        # final op.
        if i < len_:
            handle_cases(ops[-1], score)
        return sum(score)
