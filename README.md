# LeetCode problems. 

Some small notes:

- I usually use the best execution/memory numbers I can achieve.
  Sometimes this makes me write code which is what you would call
  premature optimization (especially in Python.)
- Rust seems to optimize very well and uniformly, leading 
to `100%` execution/memory consistently.
- This leads me to believe that these metrics are hoarser 
than would be expected. Take them with a grain of salt (Especially
the metrics on memory).
- I usually try to write the big-Oh for worse cases, but 
I'm not very consistent I believe.
- I'm using Firefox, not sure if this has any impact on the 
  timings for Javascript.
- Search for `TODO: Improve` for places where I think I've 
messed up slightly.

## [709. To lower case][709]

The `C` version is probably the most interesting. The rest 
just use the language provided conversion methods.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 53.05 | 20 - 97.94%|
| Mem Usage (MB-%)| 5.7 - 20.65 | 2 - 100.00 | 38.4 - 8.75 |14.1 - 99.88%|

## [771. Jewels and Stones][771] 

Add the values of J to a set and count number of jewels by 
using the set membership test to quickly establish if a 
character is a jewel.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 73.22 | 24 - 93.75%|
| Mem Usage (MB-%)| 5.8 - 25.51 | 2.1 - 100.00 | 40.4 - 11.66 |14.2 - 99.99%|

## [804. Unique Morse Code Words.][804]

Build the morse code words and add them to a set. After adding 
all words just return the length of the, now, unique set of 
morse code words.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 86.43 | 24 - 99.14|
| Mem usage (mb-%)| 6.1 - 13.33 | 2 - 100.00 | 39.4 - 6.79 | 14.1 - 100.00 |

## [832. Flipping an Image][832]

Go through matrix and reverse/invert. Python/Rust/JS use a functional 
approach. C iterates through elements.

**TODO: Write version for C where pointer arithmetic is used.**

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 67.03 | 0 - 100.00 | 80 - 86.11 | 40 - 99.08|
| Mem usage (mb-%)| 7.2 - 72.54 | 2.1 - 100.00 | 40.2 - 18.30 | 13.9 - 100.00 |

## [905. Sort Array By Parity.][905]

The two ways I've done this is either by simply sorting with the 
appropriate key function or by using a deque.

Sorting takes `O(nlogn)` and `O(1)` space while using a deque 
results in `O(n)` runtime complexity and `O(n)` space.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 28 - 77.42 | 0 - 100.00 | 96 - 72.31 | 60 - 99.98%|
| Mem Usage (MB-%)| 9.3 - 97.35 | 2.1 - 100.00 | 40.6 - 10.20 | 14.6 - 36.39%|

## [938. Range Sum of BST][938]

**TODO: Improve Rust, don't know Ref/RefCell good enough 
to readjust root correctly. I've added a minimal 
Tree impl to work with in playground.**

Do an inorder traversal and sum the items. We can 
cut execution time considerably by adjusting the root 
before we begin the traversal. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 72 - 99.00% | 12 - 100.00% | 204 - 98.44% |184 - 99.93%|
| Mem Usage (MB-%)| 42.8 - 20.00% | 4.3 - 100.00% | 67.7 - 11.10% |22.3 - 99.95%|

## [1021. Remove Outermost Parentheses][1021]

Go through string and build resulting string with the help of a 
depth counter tracking how many parentheses we've seen.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 90.17 | 28 - 98.78 |
| Mem Usage (MB-%)| 6 - 5.77 | 2.2 - 100.00 | 41 - 6.21 | 14.3 - 100.00 |


## [1108. Defanging an IP Address][1108]

Instead of calling a replace function continuously, its 
better to just go through the string and build a new string 
with '.' replaced by '[.]'. 

At least, that's my naive first stab at it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100% | 0 - 100%| 72 - 79.62%|32 - 45.31%|
| Mem Usage (MB-%)|5.8 - 14.33%|0 - 100%|38.6 - 8.88%|14.1 - 99.95%|

## [1252. Cells with Odd Values in a Matrix][1252] 

**TODO: Describe algorithm better.**

Note: Peeked at hints for this problem.

The tldr; of the algorithm boils down to this. If both `m` and `n`
are `> 2`; the sum of all odd elements in the matrix can be 
calculated by solely knowing the number of odd rows and odd 
columns. 

Since we toggle between odd and even numbers we can keep track 
of which rows and which columns are left in an odd state and 
then sum of the cells according to a relatively (after some hours
and many printed arrays later) simple formula:

```python
(m - num_odd_cols) * num_odd_rows + (n - num_odd_rows) * num_odd_cols
```

The minor edge cases `n or m <= 2` can be handled separately.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 96.98 | 20 - 100.00|
| Mem Usage (MB-%)| 6 - 98.61% | 2 - 100.00 | 39.1 - 5.66 |14 - 7.53|

## [1266. Minimum Time Visiting All Points][1266]

Move as much as you can diagonally and then move horizontically or 
vertically according to the case. `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 98.64 | 0 - 100.00 | 76 - 89.95 | 52 - 96.32% |
| Mem Usage (MB-%)| 6.4 - 13.61 | 2.1 - 100.00 | 40 - 5.60 | 14.1 - 100.00|


## [1281. Subtract the Product and Sum of Digits of an Integer][1281] 

Continuously reduce `n` by `// 10` and add/multiply its modulo 
`10` (the rightmost digit).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00%  | 0 - 100.00% | 72 - 86.84% | 20 - 98.44%|
| Mem Usage (MB-%)| 5.7 - 14.29% | 2 - 100.00% | 38.5 - 20.85% | 14.1 - 99.96%|

## [1290. Convert Binary Number in a Linked List to Integer][1290]

Traverse the list adding the sum as we go. `O(N)` necessarily. 
`O(1)` space when adding the sum as we go.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00% | 0 - 100.00% | 76 - 50.45% | 20 - 98.93%|
| Mem Usage (MB-%)| 5.6 | 1.9 - 100.00% | 38.6 - 25.42% | 14.2 - 100.00%|

## [1295. Find Numbers with Even Number of Digits][1295]

See the Python (1295.py) for the more generic approach in which
we continuously divide by ten and use a toggle to check whether 
our divisions are odd or even until reaching zero (ok, until
reaching [10, 100] as a minor opt).

Hardcoding the ranges, though specific, is fastest.\*

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 | 36  - 99.95 |
| Mem Usage (MB-%)| 6.3 - 99.58 | 2 - 8.96 | 38.2 - 6.75 | 14.3 100.00 |

\* I've used the fastest times for the table.

## [1304. Find N Unique Integers Sum up to Zero][1304]

Fill the array up from the range `[i, (n/2) + 1)` with `i` and 
`-i` values. If the array is odd `n & 1 == 1`, add a `0` to 
complete it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 94.87 | 0 - 100.00 | 76 - 88.60 | 24 - 97.78 |
| Mem Usage (MB-%)| 6.8 - 27.35 | 2 - 8.33 | 39.1 - 9.00 | 14.3 - 100.00 |

## [1309. Decrypt String from Alphabet to Integer Mapping][1309]

In both cases that follow, we go from one character or set of 
characters to another. Since we can work with characters using 
their code points, we can calculate the correct mapping just by 
adding the appropriate numbers. The offset from going from `'1'` 
to `'a'` is `48`. That is, the code point for `'1'` (`49`) plus 
the offset of `48` leads to `97` which is the code point for `a`.
As such, whatever the case, we know we need to cover the offset 
of `48` by adding it.

First we through the characters in the string and check two cases:

 1. The second character from the one we're looking at is a `'#'`.
 2. It isn't. In this simpler case, we just convert into the 
    appropriate character using their code point value. 

In the first case, we then look at the following character 
from the one we're currently at. If it is a `1` we know we're 
looking at the set of the *ten* next characters in the mapping. 
As such, we acount for these by adding `10` to the offset of `48`
before adding the value for the code point. 

Similarly, if the following character is a `2`, we are looking 
at the final remaining 7 characters. As such, we add `20` to 
the offset to get to the correct output character.  

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 88.44 | 20 - 99.29 |
| Mem Usage (MB-%)| 5.8 - 9.46 | 2 - 100.00 | 38.9 - 5.19 | 14.2 - 100.00 |


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

## [1323. Maximum 69 Number][1323]

**TODO: Improve. I don't think this is best solution.**

After finding the largest 10 multiple `d`  of 9 that has the same 
number of digits as the number, we continuously divide until 
we can't anymore (signifying a `6`, consider `669 // 900`). 

When we reach that point we simply add `d // 3` to our original
number (again, consider `669 // 900`, we need `900 // 3 == 300` 
to reach our desired result `969`).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 47.88 | 20 - 98.80 |
| Mem Usage (MB-%)| 5.4 - 29.69 | 1.9 - 100.00 | 38.8 - 32.54 | 14.1 - 99.85 |

## [1342. Number of Steps to Reduce a Number to Zero][1342] 

Xor with 1 if even (to drop the 1) and right shift by 1 to divide by two. Count.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 78.28 | 28 - 78.69 |
| Mem Usage (MB-%)| 5.5 - 27.87 | 2 - 100.00 | 38.8 - 29.88 | 14.1 - 99.98 |

## [1351. Count Negative Numbers in a Sorted Matrix][1351]

**TODO: Describe logic. Overview of steps as seen in 1351.py**

The main idea is by going to the edges of the matrix (top-right 
corner and bottom-left) we can bulk count negative numbers by 
using the fact that the matrix is row and column sorted. 

If we find negative cells, we count everything after it. After 
doing that, we adjust our points to move around the matrix 
looking for the next negative cell.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 97.86 | 0 - 100.00 | 76 - 85.01 | 104 - 99.49 |
| Mem Usage (MB-%)| 7.1 - 77.14 | 2.3 - 100.00 | 39.9 - 7.13 | 14.9 - 99.62 |

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
| Runtime (ms-%)| 16 - 77.53  | 0 - 100.00 | 92 - 76.99 |44 - 99.38|
| Mem Usage (MB-%)| 7.4 - 64.10 | 2.2 - 100.00 | 40.9 - 9.53 |14 - 100.00|

## [1370. Increasing Decreasing String.][1370]

Create three supporting structures:

 - A sorted list of distinct characters. 
 - A reverse sorted list of distinct characters.
 - A count of the # of occurences for each character.

Then, by toggling between the sorted and the reverse sorted list,
we decrease the counts of the counts mapping. This is done until 
we reach 1. We then break and add all remaining elements. (Of 
course, we could add them and *then* break but meh.)

**TODO for C: Create a generic map that's correct and can be re-used. Add it 
to folder so I can re-use it when needed.** 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 13.46 | 4 - 90.00 | 100 - 80.77 | 44 - 100 |
| Mem Usage (MB-%)| 8.8 - 100.00 | 2.3 - 100.00 | 45.8 - 8.24 | 14.1 - 100.00|

## [1374. Generate a String With Characters That Have Odd Counts][1374]

Basically, two cases:

 - `n` is odd: Repeat one character `n-2` times and add two others.
 - `n` is even: Repeat one character `n-1` times and add one other. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 87.27 | 20 - 98.14 |
| Mem Usage (MB-%)| 6.2 - 74.04 | 2.2 - 100.00 | 39 - 19.09 | 14.3 - 100.00 |

## [1389. Create Target Array in the Given Order][1389]

**TODO: See again.**

Can't think of a better than O(N^2) solution yet. Come back to this at 
some point.

## [1431. Kids with greatest number of candies][1431]

Find max, compare values and return.

## [1436. Destination City.][1436]

Use two sets, sources and destinations, and return the result 
of the difference between destinations and sources (We know 
that it will contain only one result due to the constraints.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 95.41 | 0 - 100.00 | 80 - 78.81 | 44 - 98.44 |
| Mem Usage (MB-%)| 7.6 - 48.62 | 2.4 - 100.00 | 41.7 - 5.08 | 14.1 - 100.00|

## [1450. Number of Students Doing Homework at a Given Time][1450]

Go through first vector (start times) and for every start time 
that is smaller equal to the queryTime, check the second vector 
(end times) to see if we fall in range.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 86.58 | 28 - 97.73% |
| Mem Usage (MB-%)| 5.8 - 80.17 | 2.2 - 100.00 | 38.3 - 29.39 | 14.2 - 100.00|

## [1464. Maximum Product of Two Elements in an Array][1464]

Though sorting the array and grabbing the last two elements seems
like the best way to do this, it's better even to find the max 
value, then remove it from the array/vector and then call max 
again.

Sorting alone is `O(nlogn)`.
Max, remove(1) and max is `O(N) + O(N) + O(N) => O(N)`.

(1): remove can also be done in O(1) if we have the index of the 
first maximum. We don't remove it but instead replace its value 
with a minimum value thereby removing it from consideration when 
we find the next max.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 92.82 | 0 - 100.00 | 76 - 84.17 | 40 - 98.94% |
| Mem Usage (MB-%)| 6 - 99.52 | 2.3 - 100.00 | 38.6 - 6.57 | 14.2 - 100.00%|

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

## [1475. Final Prices With a Special Discount in a Shop][1475]

Brute force this. For each element of the array loop through
the rest of the array looking for the min element.

Can, at least, re-use the array we're given.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 98.68 | 0 - 100.00 | 80 - 91.33 | 44 - 97.07 |
| Mem Usage (MB-%)| 6.6 - 56.58 | 2.2 - 100.00 | 40.2 - 5.61 |14.3 - 100.00|

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
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 86.39 | 28 - 78.99|
| Mem Usage (MB-%)| 5.7 - 22.45 | 2.2 - 100.00 | 38.2 - 5.14 |14.2 - 100.00|


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

## [1534. Count Good Triplets][1534]    

Not good. Can't think of a way to reduce the combinatorial 
explosion by removing elements from the array that will never 
satisfy the conditions. 

I thought maybe some elements can be disqualified beforehand but, that doesn't seem to be the case (running the code with test data shows that all elements can appear).  As such, I don't know how 
to reduce the complexity. 

**Update:** Remembered the 3-way set disjointness problem I had 
encountered. We enter the third inner loop only if one of the 
inequalities is satisfied (for which we need two inner loops to 
check, see code). This way, we can skip many of the combinations 
that don't match and reduce the overall explosion.  

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 100.00 | 0 - 100.00 | 76 - 97.33 | 288 - 98.17 |
| Mem Usage (MB-%)| 5.8 - 87.04 | 2 - 5.41 | 38.7 - 5.34 | 14 - 5.03 |

## [1572. Matrix Diagonal Sum][1572]

Go through the array and concurrently sum both diagonals. Remove 
the middle element (to handle double counting) if the matrix has 
an odd length. `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 100.00 | 0 - 100.00 | 68 - 97.94 | 96 - 99.21 |
| Mem Usage (MB-%)| 6.6 | 2.1 - 100.00 | 40.6 - 25.18 | 14.2 - 100.00 |

 

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
| Runtime (ms-%)| 56 - 89.80 | 16 - 100.00 | 148 - 81.63 | 136 - 75.59 |
| Mem Usage (MB-%)| 20.8 - 100.00 | 2.4 - 45.00 | 46 - 26.12 | 14.6 - 74.11 |

## [1614. Maximum Nesting Depth of the Parentheses][1614]

Traverse string while keeping count of depth. Runtime `O(n)` and 
space `O(1)`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 96.16 | 24 - 95.18 |
| Mem Usage (MB-%)| 5.7 - 85.33 | 2.2 - 100.00 | 39.2 - 76.73 | 14.1 - 100.00 |

[709]: https://leetcode.com/problems/to-lower-case/
[771]: https://leetcode.com/problems/jewels-and-stones/ 
[804]: https://leetcode.com/problems/unique-morse-code-words/
[832]: https://leetcode.com/problems/flipping-an-image/
[905]: https://leetcode.com/problems/sort-array-by-parity/
[938]: https://leetcode.com/problems/range-sum-of-bst/
[1021]: https://leetcode.com/problems/remove-outermost-parentheses
[1108]: https://leetcode.com/problems/defanging-an-ip-address/
[1252]: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
[1266]: https://leetcode.com/problems/minimum-time-visiting-all-points/
[1281]: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
[1290]: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
[1295]: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
[1304]: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
[1309]: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
[1313]: https://leetcode.com/problems/decompress-run-length-encoded-list/
[1323]: https://leetcode.com/problems/maximum-69-number/
[1342]: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
[1351]: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
[1365]: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
[1370]: https://leetcode.com/problems/increasing-decreasing-string/
[1374]: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
[1389]: https://leetcode.com/problems/create-target-array-in-the-given-order/
[1431]: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
[1436]: https://leetcode.com/problems/destination-city/
[1450]: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
[1464]: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
[1470]: https://leetcode.com/problems/shuffle-the-array/
[1475]: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
[1480]: https://leetcode.com/problems/running-sum-of-1d-array/
[1486]: https://leetcode.com/problems/xor-operation-in-an-array/
[1512]: https://leetcode.com/problems/number-of-good-pairs/
[1528]: https://leetcode.com/problems/shuffle-string/
[1534]: https://leetcode.com/problems/count-good-triplets 
[1572]: https://leetcode.com/problems/matrix-diagonal-sum/
[1588]: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
[1603]: https://leetcode.com/problems/design-parking-system/
[1614]: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses
