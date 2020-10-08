## [1431. Kids with greatest number of candies][1431]

Find max, compare values and return.

## [1470. Shuffle the Array][1470]

TODO: Come back to this.

`C`: Go through the array and select appropriate place to grab 
from based on if the index if odd or even. 

`Python`: `chain` and `zip` take care of this quickly. Since 
I'm more familiar with these, I opted for the one-liner.

`JavaScript`: Again, a more functional approach whereby I first 
grab the half of the lift (until `n`) and then, using `flatMap`
I flatten and then return `[index, index+n]` sublists. 

`Rust`: Tricky doing this in a functional way. Need to come 
back to this after further practice.

## [1480. Running Sum of 1d Array][1480]

Basically add as we go through the array. 
Also, basically the same as `itertools.accumulate`.

## [1512. Number of Good Pairs][1512]

Brute force leads to definite O(N^2). As such, we can first 
sort the array (O(nlogn)) and then, instead of comparing 
everything, notice that for a continuous sequence of equal 
elements we have:

```python
[1, 1, 1, 1, 1, ...., 1, 2, 2, ...]
```

Starting from index `0`, as long as we keep on encountering the same number, we increase a counter. Then, when we reach the end (find
a number not equal to previous one), we notice that the number of 
pairs thus far should be `n(n+1)/2` because the sequence of 
comparisons grows as:

```
1 + 2 + 3 + ... + n
```

Repeat this until we reach the end.

We could always use some combination of group-by's, len to 
move the explicit for loop in the backround.

[1480]: https://leetcode.com/problems/running-sum-of-1d-array/
[1431]: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
[1470]: https://leetcode.com/problems/shuffle-the-array/
[1512]: https://leetcode.com/problems/number-of-good-pairs/
