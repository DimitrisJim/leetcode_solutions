def _precalc_mirror_rotations(k=3):
    """
    These are, relatively, expensive to calculate,
    this is why we call it to initialize class variable.

    These hold all values for which, if a preceding number is
    {2, 5, 6, 9}, need to be accounted for since that preceding
    number causes their rotation to be valid.

    That is, we need to count 5018 while we do not need to count
    18. (because 5018 -> 2018 while 18 -> 18.)
    """
    # numbers until 10 ** k (3 here, 1000.)
    lim = 10 ** k
    mirrors, accepted = [], {*'018'}
    for i in range(1, lim):
        if {*str(i)} <= accepted:
            mirrors.append(i)
    return mirrors

def _partial_rotation_values(k=3):
    """ These ammounts along with mults can be used to quickly count
    rotations until a given point. For a given number, i.e 8372, we
    use the ammounts along with mults to quickly calculate the rotations
    until 7999.

    This is possible because there's a pattern that emerges for the
    rotations. This pattern goes as follows:

      9 -> 4, 19 -> 8, 29 -> 15, 39 -> 15, 49 -> 15,
      59 -> 22, 69 -> 29, 79 -> 27, 89 -> 33 -> 90 -> 40

    A similar pattern repeats for larger N's. From this, it can be found
    that the sum of values until one of these points is:

        3 * 4 + 4 * (4 + 3)

    This is then the sum until 99. The pattern then repeats until 999 and
    we can see that now, the values follow:

        3 * 40 + 4 * (40 + 9)

    This repeats, again. It generalizes to:

      3 * previous_value_of_formula + 4 * (previous_value_of_formula + 3 ** p)

    where p is related to our magnitude (i.e for 5943 it is 3,
    for 837 it's 2 etc).
    """
    ammounts = [0]
    prev = ammounts[-1]
    for p in range(k):
        ammounts.append(3 * prev + 4 * (prev + 3 ** p))
        prev = ammounts[-1]
    return ammounts

class Solution:

    power = 3
    mults = (
        (1, 0), (2, 0), (2, 1), (2, 1), (2, 1),
        (2, 2), (2, 3), (2, 3), (3, 3), (3, 4),
    )
    mirrored_values = _precalc_mirror_rotations(power)
    ammounts = _partial_rotation_values(power)

    def include_mirror_rotations(self, j):
        """ Using the mults values along with ammounts, we can quickly
        calculate rotations until 9, 59, 599, 5999 etc.

        The problem lies when we have values such as 5498. Here, we will
        first calculate all rotations until 4999. Then, we can't just add
        the additional rotations for 498 and be done; we need to include the
        new rotations that can be present because 5 is a number that rotates
        to a new valid number. Need to count 5000, 5001, 5008 etc.

        This case only applies for i in {2, 5, 6, 9}.
        """
        count = 1
        for i in self.mirrored_values:
            if j < i:
                break
            count = count + 1
        return count

    def add_until_previous(self, v, p):
        """
        Uses mults to add the rotations until, but not including, v.
        """
        (i, j), prev = self.mults[int(v-1)], self.ammounts[p]
        return i * prev + j * (prev + 3 ** p)

    def rotatedDigits(self, N: int) -> int:
        p = self.power
        aup, imr = self.add_until_previous, self.include_mirror_rotations
        div, good_numbers = 10 ** p, 0
        while N:
            quot, N = divmod(N, div)
            div = div / 10
            if quot:
                # Add good numbers until quot.
                good_numbers = good_numbers + aup(quot, p)

                # done, nothing more to count since these don't
                # rotate to meaningfull number.
                if quot in {3, 4, 7}:
                    return good_numbers

                # Note: don't add if we're on final iteration.
                elif quot in {2, 5, 6, 9} and div:
                    good_numbers = good_numbers + imr(quot, N)
            p = p - 1
        return good_numbers
