## [1108. Defanging an IP Address][1108]

Instead of calling a replace function continuously, its 
better to just go through the string and build a new string 
with '.' replaced by '[.]'. 

At least, that's my naive first stab at it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100% | 0 - 100%| 72 - 79.62%|32 - 45.31%|
| Mem Usage (MB-%)|5.8 - 14.33%|0 - 100%|38.6 - 8.88%|14.1 - 99.95%|

## [1365. How Many Numbers Are Smaller Than the Current Number][1365]

By sorting the array we can find the # of elements faster in 
one pass through the array since we know that all consequent 
elements will be larger (or smaller, depending on sort type).

Using a Map we can then keep track of the occurences of elements already seen and set that as the value for an element.

Finally we can go through the nums array and for every element
get the occurence for it and place it in the final resulting 
array.

We use quite the extra space but avoid O(N^2) this way 
(and instead result in O(nlogn)).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 77.53%  | 0ms 100.00% | 92 - 76.99% |44 - 99.38%|
| Mem Usage (MB-%)| 7.4 - 64.10% | 2.2 - 100.00% | 40.9 - 9.53% |14 - 100.00%|


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

## [1528. Shuffle String][1528]

Create a new array and fill it in, basically. 
`O(N)` time *and* `O(N)` space. I'm sure there should be a 
way for inplace swaps.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 88.85% | 0 - 100.00% | 76 - 97.38% | 56 - 65.00%|
| Mem Usage (MB-%)| 6.2 - 100.00% | 2 - 100.00% | 40.3 - 10.15% |14.1 - 99.95%|



[1108]: https://leetcode.com/problems/defanging-an-ip-address/
[1365]: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
[1431]: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
[1470]: https://leetcode.com/problems/shuffle-the-array/
[1480]: https://leetcode.com/problems/running-sum-of-1d-array/
[1512]: https://leetcode.com/problems/number-of-good-pairs/
[1528]: https://leetcode.com/problems/shuffle-string/
