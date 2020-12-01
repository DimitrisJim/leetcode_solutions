class Solution:

    def relativeSortArray(self, arr1, arr2):
        # dictionary holds order which we use to sort arr1.
        order = {j: i for i, j in enumerate(arr2)}
        get = order.get
 
        # use get(x, x+1000), this way when we don't have
        # a value in order for x we can build a sorting
        # relation based on the value of x (+1000 as the
        # max value arr1[i] can have.)
        arr1.sort(key=lambda x: get(x, x+1000))
        return arr1
