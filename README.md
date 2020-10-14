# LeetCode problems. 

Some small notes:
 
 - Rust seems to optimize very well and uniformly, leading 
   to `100%` execution/memory consistently.
 - This leads me to believe that these metrics are hoarser 
   than would be expected. Take them with a grain of salt.
 - I usually try to write the big-Oh for worse cases, but 
   I'm not very consistent I believe.
 - Search for `TODO: Improve` for places where I think I've 
   messed up slightly.

## [938. Range Sum of BST][938]

**TODO: Improve Rust, don't know Ref/RefCell good enough 
to readjust root correctly. I've added a minimal 
Tree impl to work with in playground. **

Do an inorder traversal and sum the items. We can 
cut execution time considerably by adjusting the root 
before we begin the traversal. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 72 - 99.00% | 12 - 100.00% | 204 - 98.44% |184 - 99.93%|
| Mem Usage (MB-%)| 42.8 - 20.00% | 4.3 - 100.00% | 67.7 - 11.10% |22.3 - 99.95%|


## [1108. Defanging an IP Address][1108]

Instead of calling a replace function continuously, its 
better to just go through the string and build a new string 
with '.' replaced by '[.]'. 

At least, that's my naive first stab at it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100% | 0 - 100%| 72 - 79.62%|32 - 45.31%|
| Mem Usage (MB-%)|5.8 - 14.33%|0 - 100%|38.6 - 8.88%|14.1 - 99.95%|

## [1281. Subtract the Product and Sum of Digits of an Integer][1281] 

Continuously reduce `n` by `// 10` and add/multiply its modulo 
`10` (the rightmost digit).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00%  | 0 - 100.00% | 72 - 86.84% | 20 - 98.44%|
| Mem Usage (MB-%)| 5.7 - 14.29% | 2 - 100.00% | 38.5 - 20.85% | 14.1 - 99.96%|

## [1313. Decompress Run-Length encoded List][1313]

**TODO: Improve**

I feel I haven't found best solution here, need to look into 
it, especially the mem usage in Python bothers me.
(Yea, C code is also mediocre, there's 
definitely something better here.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 32 - 81.07% | 4 - 100.00%  | 92 - 85.55% | 64 - 89.35%|
| Mem Usage (MB-%)| 10.4 | 2.1 - 100.00% | 42.3 - 5.85% | 14.5 - 13.10%|



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

## [1389. Create Target Array in the Given Order][1389]

**TODO: See again.**

Can't think of a better than O(N^2) solution yet. Come back to this at 
some point.

## [1431. Kids with greatest number of candies][1431]

Find max, compare values and return.

## [1470. Shuffle the Array][1470]

**TODO: Come back to this.**

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

## [1486. XOR Operation in an Array][1486]

Just go through the 'array' (we don't need to build it obviously)
and reduce using xor. 
In Python, we take advantage of `functools.reduce` being implemented in `C`, in the others we just loop through.

Again with some memory issues in `C` and `JS` though. I'm pretty 
sure a XOR-trick for sequences should exist (appart from the 
common `x ^ x = 0` and `x ^ 0 = x`; can't seem to find it though.) 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00% | 0 - 100.00% | 72 - 86.39% | 28 - 78.99%|
| Mem Usage (MB-%)| 5.7 - 22.45% | 2.2 - 100.00% | 38.2 - 5.14% |14.2 - 100.00%|


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

## [1588. Sum of All Odd Length Subarrays][1588]

TODO: Explain the clusterfuck of the thing you call logic. 

Note: Javascript perf is quite bad. Not sure what I'm doing 
wrong or if another better trick exists. Surely, the mults array
doesn't *need* to be stored, we can compute it on the fly as 
we go through indexes. Maybe I'll fix that in the future.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00% | 0 - 100.00% | 84 - 50.48% | 36ms  - 94.20%|
| Mem Usage (MB-%)| 6 - 93.55% | 2 - 100.00% | 39 - 7.44% | 14 - 100.00%|


## [1603. Design Parking System][1603]

Mostly an OOP problem really.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 56 - 89.80% | 16 - 100.00% | 148 - 81.63% | 136 - 75.59% |
| Mem Usage (MB-%)| 20.8 - 100.00% | 2.4 - 45.00% | 46 - 26.12% | 14.6 74.11% |


[938]: https://leetcode.com/problems/range-sum-of-bst/submissions/
[1108]: https://leetcode.com/problems/defanging-an-ip-address/
[1281]: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
[1313]: https://leetcode.com/problems/decompress-run-length-encoded-list/
[1365]: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
[1389]: https://leetcode.com/problems/create-target-array-in-the-given-order/
[1431]: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
[1470]: https://leetcode.com/problems/shuffle-the-array/
[1480]: https://leetcode.com/problems/running-sum-of-1d-array/
[1486]: https://leetcode.com/problems/xor-operation-in-an-array/
[1512]: https://leetcode.com/problems/number-of-good-pairs/
[1528]: https://leetcode.com/problems/shuffle-string/
[1603]: https://leetcode.com/problems/design-parking-system/
