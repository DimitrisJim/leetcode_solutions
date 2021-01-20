class Solution:
    def reorderLogFiles(self, logs):
        # special case, empty or logs with 1 log.
        if len(logs) < 2:
            return logs
        # bring these in local scope.
        digit, letter, join = (
            str.isdigit, 
            str.isalpha,
            " ".join
        )

        # Split beforehand in order to not split constantly.
        # Build arrays of digit and letter rows. Digit rows
        # stay as they are.
        logs_tr = list(map(str.split, logs))
        d_rows = [join(i) for i in logs_tr if digit(i[1][0])]
        l_rows = [i for i in logs_tr if letter(i[1][0])]
        
        # Sort l_rows, add identifier to end in order to act as
        # tiebraker if needed.
        l_rows.sort(key=lambda x: join([join(x[1:]), x[0]]))

        # Extend with d_rows and return
        return [*map(join, l_rows), *d_rows]
