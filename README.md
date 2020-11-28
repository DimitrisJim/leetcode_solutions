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

## [461. Hamming Distance][461]

Get the xor of the two numbers (where bits differ) and then 
count set bits.

I'm under the impression I'm missing some other obvious 
solution here.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 82.30 | 28 - 76.20 |
| Mem Usage (MB-%)| 5.5 - 67.52 | 2 - 100.00 | 38.5 - 71.22 | 14.1 - 61.18 |

## [557. Reverse Words in a String III][561]

C mutates the string in-place because it's allowable there. 
The rest split on `' '`, iterate through the chunks and 
reverse them.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 93.81 | 0 - 100.00 | 88 - 74.93 | 24 - 97.41 |
| Mem Usage (MB-%)| 6.9 - 72.57 | 2.3 - 72.73 | 44.6 - 85.18 | 14.6 - 84.18 |

## [561. Array Partition I][561]

Sort the array in reverse order and sum every second 
element.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 52 - 80.25 | 8 - 96.15 | 120 - 93.30 | 244 - 97.34 |
| Mem Usage (MB-%)| 8.5 - 27.16 | 2.2 - 100.00 | 44 - 79.12 | 16.5 - 81.43 |

## [589. N-Ary tree pre-order traversal][589]

Option for Rust isn't available yet unfortunately.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 82.00 | N/A | 92 - 89.63 | 48 - 81.31 |
| Mem Usage (MB-%)| 19.9 - 24.00 | N/A | 43.1 - 13.39 | 15.6 - 86.89 |

## [590. N-Ary tree post order traversal][590]

All using iterative versions (probably partly explains why 
timings show sluggishness).

Option for Rust isn't available yet unfortunately.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 14.63 | N/A | 100 - 55.56 | 32 - 100.00 |
| Mem Usage (MB-%)| 24.4 - 9.76 | N/A | 43.7 - 9.69 | 15.8 - 57.01 |

## [617. Merge Two Binary Trees][617]

Don't recurse. Breadth first traversal using a queue. 
Add branches immediately when we can.

Pending: 

 - `C` because I need to make a small queue first.
 - `Rust`: Got to sit down and learn `Rc`s and `RefCell`s better. [OK, more familiar now].
 - `Javascript`: File added, timings need to improve.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| | 4 - 100.00 | | 80 - 96.68 |
| Mem Usage (MB-%)| | 2.2 - 100.00 | | 14.9 - 99.93 |

## [657. Robot Return to Origin][657]

Count occurences and compare. If number of 'D's matches number 
of 'U's and number of 'L's matches number of 'R's, we're good.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 95.76 | 0 - 100.00 | 80 - 90.34 | 32 - 94.10 |
| Mem Usage (MB-%)| 6 - 57.63 | 1.9 - 100.00 | 39.7 - 61.54 | 14.2 - 67.31 |

## [700. Search in a BST][700]

Straight-forward. Perform binary search. `C` code also contains 
a tail-recursive version, didn't seem to make much difference
in runtime/memory timings.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 89.04 | 4 - 100.00 | 44 - 98.93 | 64 - 97.56|
| Mem Usage (MB-%)| 15.1 - 73.25 | 2.6 - 57.14 | 44.4 - 76.63 | 15.8 - 94.95|

## [709. To lower case][709]

The `C` version is probably the most interesting. The rest 
just use the language provided conversion methods.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 53.05 | 20 - 97.94|
| Mem Usage (MB-%)| 5.7 - 20.65 | 2 - 100.00 | 38.4 - 8.75 |14.1 - 99.88|

## [728. Self Dividing Numbers][728]

Go through digits of number and check for divisibility. Basically
brute-forcing our way to an answer. Not sure if anything better
than brute-force is possible. 

Sidenote: Transforming to strings could be a better approach,
not sure.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 84 - 65.67 | 44 - 81.10 |
| Mem Usage (MB-%)| 6.2 - 14.75 | 2.2 - 100.00 | 38.8 - 11.69 | 14.1 - 100.00 |

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

## [811. Subdomain visit count.][811]

Hold domains/subdomains in a Counter and count values after 
splitting domain up.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 71.43 | 4 - 100.00 | 92 - 93.28 | 44 - 95.94|
| Mem usage (mb-%)| 9.6 - 28.57 | 2.2 - 25.00 | 43.4 - 70.71 | 14.4 - 26.05 |

## [832. Flipping an Image][832]

Go through matrix and reverse/invert. Python/Rust/JS use a functional 
approach. C iterates through elements.

**TODO: Write version for C where pointer arithmetic is used.**

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 67.03 | 0 - 100.00 | 80 - 86.11 | 40 - 99.08|
| Mem usage (mb-%)| 7.2 - 72.54 | 2.1 - 100.00 | 40.2 - 18.30 | 13.9 - 100.00 |

## [852. Peak index in a Mountain Array.][852]

A binary search throug the semi-sorted array. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 89.84 | 0 - 100.00 | 72 - 91.56 | 64 - 97.11 |
| Mem usage (mb-%)| 6.6 - 30.47 | 2.1 - 75.00 | 39.1 - 77.91 | 15 - 88.20 |


## [897. Increasing Order Search Tree][897]

Inorder traversal to gather nodes and then re-attaching 
accordingly.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 98.18 | 24 - 94.91|
| Mem usage (mb-%)| 6.2 - 59.26 | 2.2 - 100.00 | 38.9 - 61.82 | 14 - 77.72 |

## [905. Sort Array By Parity.][905]

The two ways I've done this is either by simply sorting with the 
appropriate key function or by using a deque.

Sorting takes `O(nlogn)` and `O(1)` space while using a deque 
results in `O(n)` runtime complexity and `O(n)` space.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 28 - 77.42 | 0 - 100.00 | 96 - 72.31 | 60 - 99.98|
| Mem Usage (MB-%)| 9.3 - 97.35 | 2.1 - 100.00 | 40.6 - 10.20 | 14.6 - 36.39|

## [922. Sort Array By Parity II][922]

Preallocate resulting array. Then go through input array and using two
variables to denote the positions of the odds and evens, fill the 
array.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 64 - 93.81 | 8 - 100.00 | 88 - 100.00 | 196 - 92.39 |
| Mem Usage (MB-%)| 13.5 - 51.55 | 2.1 - 77.78 | 44.4 - 74.18 | 16.8 - 15.40 |


## [933. Number of Recent Calls][933]

Keep t's in a Queue/Deque and using that find the correct 
amount of pings. Keeping the last ping around in a 
separate variable allows us to quickly answer with 1 and 
clear the Queue/Deque.

**TODO: Need to implement a Queue for C for it to run. Code 
is currently written as if using a Queue.**

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| | 32 - 94.22 | 228 - 72.72 | 260 - 99.58 |
| Mem Usage (MB-%)| | 5.6 - 84.39 | 50.2 - 29.84 | 18.7 - 91.13|

## [938. Range Sum of BST][938]

**TODO: Improve Rust, don't know Ref/RefCell good enough 
to readjust root correctly. I've added a minimal 
Tree impl to work with in playground.**

Do an inorder traversal and sum the items. We can 
cut execution time considerably by adjusting the root 
before we begin the traversal. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 72 - 99.00 | 12 - 100.00 | 204 - 98.44 |184 - 99.93|
| Mem Usage (MB-%)| 42.8 - 20.00 | 4.3 - 100.00 | 67.7 - 11.10 |22.3 - 99.95|

## [942. DI String Match][942]

Initialize counters, i to zero and j to the length of the string.
Iterate through characters of string and add i if character is 
'I' and j if char is 'D'. Increase and decrease the counters 
respectively afterwards.

Append either i or j at the end (they should be equal) to 
complete the sequence.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 32 - 98.51 | 4 - 71.43 | 100 - 65.91 | 56 - 94.27|
| Mem Usage (MB-%)| 11.6 - 34.33 | 2.2 - 28.57 | 43.1 - 21.59 | 14.9 - 83.63|

## [944. Delete Columns to Make Sorted.][944]

I cannot see the best solution here. I'm definitely sure 
mine isn't the one.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 90.91 | 8 - 100.00 | 88 - 82.50 | 112 - 81.53 |
| Mem Usage (MB-%)| 8.3 - 40.91 | 2.3 - 100.00 | 42.5 - 76.67 | 14.4 - 84.557|

## [961. N repeated elements in size 2N Array][961]

Two ways to go about this:

 1. Build a set with 'seen' values. Break the moment we find a value we have already seen. Rust and Python use this.
 2. Iterate through the array and check triplets. Since we know 
that N-1 of the elements are the same, we're bound to bump into a triplet with two elements being equal. Edge case is 2N = 4, were the elements are in the beginning and end respectively.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 100.00 | 0 - 100.00 | 80 - 88.70 | 188 - 93.66%|
| Mem Usage (MB-%)| 7.2 - 73.91 | 2.1 - 100.00 | 41.9 - 76.92 | 15.3 - 65.97|

## [977. Squares of a Sorted Array][977]

Though a more convoluted way were we don't sort is 
possible, I don't think it's of much worth.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 100 - 96.55 | 8 - 98.46 | 116 - 84.11 | 184 - 99.84 |
| Mem Usage (MB-%)| 20.3 - 33.10 | 2.2 - 78.46 | 45.4 - 39.09 | 16.1 - 34.75 |

## [1021. Remove Outermost Parentheses][1021]

Go through string and build resulting string with the help of a 
depth counter tracking how many parentheses we've seen.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 90.17 | 28 - 98.78 |
| Mem Usage (MB-%)| 6 - 5.77 | 2.2 - 100.00 | 41 - 6.21 | 14.3 - 100.00 |

## [1022. Sum of root to leaf binary numbers][1022]

As we DFS our way to the bottom, we alter each node's value 
to add what we've already seen (parent's value). This can 
be done directly by using:

```python
node.val = (parent.val << 1) | node.val
```

When we reach a leaf, we add the value to an array which we 
sum when we've visited every node.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 85.42 | 0 - 100.00 | 84 - 80.08 | 28 - 97.19 |
| Mem Usage (MB-%)| 7.2 - 14.58 | 2.1 - 100.00 | 41.2 - 16.26 | 14.8 - 13.95 |

## [1047. Remove All Adjacent Duplicate Strings][1047]

Use a stack to filter out adjacent elements.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 94.52 | 0 - 100.00  | 84 - 95.59 | 48 - 99.13 |
| Mem Usage (MB-%)| 8.1 - 9.59 | 2.2 - 60.00 | 47.1 - 42.68 | 14.7 - 21.89 |


## [1051. Height Checker][1051]

Create a sorted target array and go through both arrays 
counting their differences.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 95.33 | 16 - 100.00 |
| Mem Usage (MB-%)| 5.7 - 70.92 | 2 - 40.00 | 38.4 - 81.16 | 14.1 - 69.05 |

## [1108. Defanging an IP Address][1108]

Instead of calling a replace function continuously, its 
better to just go through the string and build a new string 
with '.' replaced by '[.]'. 

At least, that's my naive first stab at it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100 | 0 - 100| 72 - 79.62|32 - 45.31|
| Mem Usage (MB-%)|5.8 - 14.33|0 - 100|38.6 - 8.88|14.1 - 99.95|

## [1207. Unique number of occurences.][1207] 

Create counts for each value. If, by using a Set, any values 
are filtered, we've got duplicates.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 94.09 | 28 - 94.97 |
| Mem Usage (MB-%)| 6.5 - 23.94 | 2.1 - 80.00 | 38.6 - 80.38 | 14.2 - 83.42|

## [1217. Minimum cost to move chips to the same position.][1217]

Count evens and odds. Answer is the minimum between those two
since all values of `max{evens, odds}` can be moved to one pile
via 2-steps (with zero cost) leaving the `min{evens, odds}` as
the cost we need to count (note that no matter their distance.


| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 74.31 | 24 - 95.45 |
| Mem Usage (MB-%)| 5.8 - 63.86 | 2 - 94.23 | 37.8 - 96.26 | 14.1 - 78.87|

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

## [1299. Replace Elements with Greatest Element on Right Side][1299]

Go backwards, continously updating the maximum value seen as we go through.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 52 - 90.45 | 4 - 96.67 | 88 - 96.36 | 104 - 99.74 |
| Mem Usage (MB-%)| 12.7 - 48.64 | 2.2 - 100.00 | 42.1 - 5.56 | 15.3 - 6.78 |

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

## [1380. Lucky numbers in a Matrix][1380]

Build a set to hold minimum values of each row and a 
list/array to hold maximum values for each column. 

After iterating through each row and filling the previous 
structures us, return any elements in the array/list that 
are also present in the set. 


| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 100.00 | 0 - 100.00 | 76 - 96.19 | 116 - 95.12 |
| Mem Usage (MB-%)| 7 - 17.65 | 2.1 - 100.00 | 40.7 - 87.20 | 14.3 - 49.67 |

## [1389. Create Target Array in the Given Order][1389]

**TODO: See again.**

Can't think of a better than O(N^2) solution yet. Come back to this at 
some point.

## [1403. Minimum Sequence in non increasing order,][1403]

Get the sum of the sequence and then sort it (ideally 
descending). Initialize a value for counting the sum of 
the subsequence seen so far. Then for every value in the 
sequence:

 1. sum the current value to the subsequence sum. 
 2. subtrack the current value from the sum of the sequence.
 3. if the sum from 1 is strictly larger than that of 2, we     are done and we return the slice until that point. Else 
  we continue through the values.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 96.00 | 0 - 100.00 | 84 - 92.78 | 52 - 97.26 |
| Mem Usage (MB-%)| 6.5 - 88.00 | 2 - 75.00 | 39.7 - 91.67 | 14.2 - 63.63 |

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
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 86.58 | 28 - 97.73 |
| Mem Usage (MB-%)| 5.8 - 80.17 | 2.2 - 100.00 | 38.3 - 29.39 | 14.2 - 100.00|

## [1460. Make Two Arrays Equal by Reversing Sub-Arrays][1460]

Sort and compare element-wise.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 97.78 | 0 - 100.00 | 72 - 99.53 | 64 - 99.47 |
| Mem Usage (MB-%)| 6.6 - 26.67 | 2.1 - 50.00 | 40.6 - 46.34 | 14.3 - 79.93 |


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

## [1502. Can make arithmetic progression from sequence.][1486]

Sort the array and find the step by subtracting first two 
elements. Go through the array and check that step is 
present through-out.

Worse-case `O(NlogN)` due to sorting.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 89.04 | 0 - 100.00 | 76 - 88.50 | 32 - 95.03 |
| Mem Usage (MB-%)| 6.1 - 76.71 | 1.9 - 100.00 | 38.7 - 86.58 | 14.1 - 89.94 |

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

## [1640. Check Array Formation Through Concatenation][1640]

Build a set-like supporting structure for fast O(1) look-ups.
Go through each element in second array:
 
 -  If the sub-array has a single element, check if its contained
    in the set-like structure and bail if not.
 -  If the sub-array has more than one elements. Find index of 
    subarray[0] in original array and try and match the rest of 
    the values in the sub-array.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 92.31 | 0 - 100.00 | 80 - 67.57 | 36 - 93.55 |
| Mem Usage (MB-%)| 6.7 - 100.00 | 2.2 - 100.00 | 38.8 - 5.11 | 14.1 - 100.00 |

## [1656. Design An Ordered Stream][1656]

There's probably a different way for this. I've created a 
mapping to hold id-value pairs and after every insert I 
simply create the resulting array by increasing ptr and 
checking if a key with that value exists in the mapping.

Pretty sure there's got to be a simpler way.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 84 - 62.50  | 20 - 93.33 | 184 - 89.38 | 200 - 98.57 |
| Mem Usage (MB-%)| 33.5 - 12.50 | 2.9 - 40.00 | 49.5 - 100.00 | 14.7 - 75.25 |

## [1662. Check if two string arrays are equivalent.][1662]

Go through characters and check, alternatively, build resulting string and 
compare the string.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 91.70 | 24 - 97.07 |
| Mem Usage (MB-%)| 5.9 - 91.49 | 2 - 80.00 | 38 - 99.79 | 14 - 96.79 |


[461]: https://leetcode.com/problems/hamming-distance/
[589]: https://leetcode.com/problems/n-ary-tree-preorder-traversal
[561]: https://leetcode.com/problems/array-partition-i/
[590]: https://leetcode.com/problems/n-ary-tree-postorder-traversal
[617]: https://leetcode.com/problems/merge-two-binary-trees/
[657]: https://leetcode.com/problems/robot-return-to-origin/
[709]: https://leetcode.com/problems/to-lower-case/
[728]: https://leetcode.com/problems/self-dividing-numbers
[771]: https://leetcode.com/problems/jewels-and-stones/ 
[804]: https://leetcode.com/problems/unique-morse-code-words/
[811]: https://leetcode.com/problems/subdomain-visit-count/
[832]: https://leetcode.com/problems/flipping-an-image/
[852]: https://leetcode.com/problems/peak-index-in-a-mountain-array/
[897]: https://leetcode.com/problems/increasing-order-search-tree/
[905]: https://leetcode.com/problems/sort-array-by-parity/
[933]: https://leetcode.com/problems/number-of-recent-calls
[938]: https://leetcode.com/problems/range-sum-of-bst/
[942]: https://leetcode.com/problems/di-string-match/
[944]: https://leetcode.com/problems/delete-columns-to-make-sorted
[961]: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
[977]: https://leetcode.com/problems/squares-of-a-sorted-array/
[1021]: https://leetcode.com/problems/remove-outermost-parentheses
[1022]: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers
[1047]: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
[1051]: https://leetcode.com/problems/height-checker
[1108]: https://leetcode.com/problems/defanging-an-ip-address/
[1207]: https://leetcode.com/problems/unique-number-of-occurrences/
[1217]: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
[1252]: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
[1266]: https://leetcode.com/problems/minimum-time-visiting-all-points/
[1281]: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
[1290]: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
[1295]: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
[1299]: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
[1304]: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
[1309]: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
[1313]: https://leetcode.com/problems/decompress-run-length-encoded-list/
[1323]: https://leetcode.com/problems/maximum-69-number/
[1342]: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
[1351]: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
[1365]: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
[1370]: https://leetcode.com/problems/increasing-decreasing-string/
[1374]: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
[1380]: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
[1389]: https://leetcode.com/problems/create-target-array-in-the-given-order/
[1403]: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
[1431]: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
[1436]: https://leetcode.com/problems/destination-city/
[1450]: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
[1460]: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
[1464]: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
[1470]: https://leetcode.com/problems/shuffle-the-array/
[1475]: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
[1480]: https://leetcode.com/problems/running-sum-of-1d-array/
[1486]: https://leetcode.com/problems/xor-operation-in-an-array/
[1502]: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
[1512]: https://leetcode.com/problems/number-of-good-pairs/
[1528]: https://leetcode.com/problems/shuffle-string/
[1534]: https://leetcode.com/problems/count-good-triplets 
[1572]: https://leetcode.com/problems/matrix-diagonal-sum/
[1588]: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
[1603]: https://leetcode.com/problems/design-parking-system/
[1614]: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses
[1640]: https://leetcode.com/problems/check-array-formation-through-concatenation
[1656]: https://leetcode.com/problems/design-an-ordered-stream/
[1662]: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent
