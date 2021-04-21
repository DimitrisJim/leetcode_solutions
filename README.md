# LeetCode problems. 

Some small notes:

- I usually use the best execution/memory numbers I can achieve.
  Sometimes this makes me write code which is what you would call
  premature optimization (especially in Python.)
- Rust seems to optimize very well and uniformly, leading 
to `100%` execution/memory consistently. (Update: Low number of submissions
  also has an effect.
- Search for `TODO: Improve` for places where I think I've messed up slightly
  (also see Revisit.md).
- Problems that are new have skewed timings because of the initial low
  number of submissions.

Additionally:

 - Python and C also have a Concurrency folder where attempts at the concurrency problems are
added. I will not offer any sort of guarantees on those.

## [1. Two Sum.][1]

Similar to other Two Sum problems. We again use a cache in the form of a mapping
that keeps track of the appropriate index to use when we finally find the match.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 96.96 | 0 - 100.00 | 72 - 94.33 | 28 - 99.99 |
| Mem Usage (MB-%)| 6 - 68.00 | 2.3 - 68.01 | 38.4 - 91.28 | 14.4 - 47.87 |

## [7. Reverse Integer.][7]

We can work with arrays of the digits in order to reverse the numbers. Care needs to be
taken specifically for largest negative `i32 (0x80000000)` and for inputs that contain
`10` digits in total (which, when reversed, might not fit in 32 bits).

To combat first case, we can just bail early if `x == 0x80000000`. To combat the second case,
we check the digits of the result against the maximum value allowed. If, at any point, we discover
input the would result in a number too large to represent, we bail.

Overall, this is `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 88 - 94.61 | 20 - 99.44 |
| Mem Usage (MB-%)| 6 - 14.40 | 1.9 - 85.78 | 40.8 - 14.78 | 14.4 - 11.58 |

## [9. Remove Element.][9]

Use a swap-remove. As found in Rusts `Vec.swap_remove`. Basically, replace the
value you want to remove with the value at the end of the list/array. This way,
`O(1)` removes can be achieved. Overall complexity is `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 98.77 | 28 - 90.92 |
| Mem Usage (MB-%)| 6.1 - 39.77 | 2.1 - 67.18 | 38.6 - 60.38 | 14.3 - 46.75 |

## [13. Roman to Integer.][13]

Keep a set of the special cases and go through each character in `s`. If the character
we've currently looking at and its next one are in the special cases, handle the case
and increase our counter to then look at the next character two positions over. Else,
just add the character seen.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 89.64 | 0 - 100.00 | 152 - 95.49 | 36 - 97.76 |
| Mem Usage (MB-%)| 5.7 - 98.67 | 2 - 92.20 | 44.4 - 92.17 | 14 - 94.68 |

## [21. Merge two sorted lists.][21]

For `Rust`, go through both linked lists and build vector of values, then, build
resulting vector.

For others, go through nodes of linked list and incrementally build resulting linked
list.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 4 - 100.00 | 84 - 92.62 | 32 - 91.62 |
| Mem Usage (MB-%)| 6.3 - 47.94 | 2 - 83.19 | 40.1 - 91.86 | 14.1 - 83.79 |

## [35. Search insert position.][35]

Again, binary searching for the right spot, i.e `O(logN)`.

Start points to position in list for which all elements with index smaller than start have a value
than target and all elements with index larger than it have a `value >= target`.

When finished, start will either point to target or the leftmost position in which to insert it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 98.11 | 40 - 97.25 |
| Mem Usage (MB-%)| 6 - 85.77 | 2 - 100.00| 38.7 - 72.22| 15.1 - 52.12 |

## [64. Summary Ranges.][64]

Keep a tracker around to track the sequence as it increases. If at any point, the number in
the array doesn't match the tracker, a new sequence should be added. Care is needed when
ending the loop to accound for two cases (ended on a single number or while going through a
range). Overall, `O(N)` time and space.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 97.06 | 24 - 93.79 |
| Mem Usage (MB-%)| 5.7 - 73.33 | 2.1 - 54.55 | 38.2 - 92.51 | 14.4 - 16.10 |

## [66. Plus One][66]

Relatively straight-forward, if we encounter a `9`, we need to zero it and move
left to the next item in the array. If it isn't a nine, we increment and return.

Care is needed to detect when the array is basically full of `9`s in which case we
need to prepend a `1` before we return. 

Runtime complexity is `O(N)`, we perform constant operations for each item in the
array. Space complexity is `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 99.75 | 24 - 97.53 |
| Mem Usage (MB-%)| 5.8 - 99.54| 2 - 93.75 | 38.6 - 69.35 | 14.3 - 48.72 |

## [88. Merge sorted array.][88]

Place elements from `nums2` at the end of `nums1` (replacing zero elements) and sort it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 98.93 | 28 - 96.98 |
| Mem Usage (MB-%)| 6.2 - 39.46 | 2 - 66.67 | 38.5 - 92.89 | 14.2 - 85.77 |

## [100. Same Tree][100]

C recursively solves it while the others use the iterative approach. In all cases
this really just involves traversing the same nodes and checking that their values
are the same and they both have the same numbers of children. 

Care is needed to handle case where one tree has been exhausted while the other tree
still has nodes we haven't seen.

Complexity is `O(N)` where N is the number of nodes since we perform constant 
operations for each node. Not sure about space complexity of the top of my head.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 92.99 | 24 - 95.46 |
| Mem Usage (MB-%)| 6 - 34.24 | 2 - 52.17 | 38.8 - 77.73 | 14.2 - 65.65 |

## [102. Binary Tree level order traversal.][102]

There's a similar problem to this one, I remember it. All in all, use a stack where we
keep nodes/level tuples. DFS traversal and use the level saved for each node as index in
the results vec/list that holds the result values. `O(N)` space/memory.

C: Too much hassle with 2D arrays but I hope I'll get back to it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| | 0 - 100.00 | 80 - 85.22 | 24 - 98.58 |
| Mem Usage (MB-%)| | 2 - 97.96 | 40.3 - 44.58 | 14.5 - 88.37 |

## [104. Maximum depth of Binary Tree][104]

Rust contains both iterative and recursive approaches. C/Javascript use 
recursive, Python uses iterative.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 92.16 | 0 -100.00 | 80 - 94.64 | 36 - 89.43 |
| Mem Usage (MB-%)| 8.1 - 50.63 | 2.5 - 94.87 | 41 - 96.55 | 15.2 - 91.21 |

## [107. Binary Tree Level Order Traversal II,][107]

Breadth first traversal, use an additional value to mark the level which we use to
correctly place into subarrays. Return result reversed.

C Version: Not mentally ready to go through the allocation hell, yet.

Complexity: Time should be `O(N)`, not sure about space.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| Nope. | 0 - 100.00 | 76 - 95.89 | 24 - 98.69 |
| Mem Usage (MB-%)| NOPE. | 2.1 - 88.89 | 40.3 - 25.94 | 14.7 - 49.77 |

## [108. Convert Sorted Array to BST.][108]

Need to balance resulting tree (i.e max difference of height between two children of 
a given node to equal 1).

Since we have a sorted array, we know we can separate the array in a triplet consisting
of `(lower_than_mid, mid, higher_than_mid)`. Using this we can then use:

 - `mid`: as our new node.
 - `lower_than_mid`: as our left branch.
 - `higher_than_mid`: as our right branch.

Recursively solving this is straight-forward.

| Stats/Lang  | C | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 94.69 | 0 - 100.00 | 84 - 95.62 | 56 - 99.93 |
| Mem Usage (MB-%)| 18 - 59.59 | 2.9 - 71.43 | 41.7 - 93.78 | 16.6 - 22.27 |

## [111. Minimum depth of binary tree.][111]

Typical depth first recursion. We can stop recursing when we reach a depth which is bigger
than a minimum we've already found, though. Worse case complexity is still `O(N)` as is the
memory complexity.

| Stats/Lang  | C | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 132 - 99.58 | 32 - 97.73 | 232 - 99.61 | 468 - 93.47 |
| Mem Usage (MB-%)| 75.4 - 99.16 | 11.4 - 100.00 | 75.4 - 17.90 | 49.3 - 72.86 |

## [118. Pascal's triangle.][118]

Becomes easy once you look up on Pascal's Triangle and find the [formula for
finding a row](https://en.wikipedia.org/wiki/Pascal%27s_triangle#Calculating_a_row_or_diagonal_by_itself).

Not sure about complexity here. Since for each `n` we perform `1 + 2 + 3 + .... + n`
iterations, though, I believe it must be around `O(n^2)`.

| Stats/Lang  | C | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 99.32 | 24 - 95.43 |
| Mem Usage (MB-%)| 5.9 - 95.86 | 2.3 - 6.67 | 38.6 - 21.82 | 14.3 - 59.05 |

## [119. Pascal's triangle II.][119]

Becomes easy once you look up on Pascal's Triangle and find the [formula for
finding a row](https://en.wikipedia.org/wiki/Pascal%27s_triangle#Calculating_a_row_or_diagonal_by_itself).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 99.83 | 24 - 96.72 |
| Mem Usage (MB-%)| 5.9 - 65.63 | 2.4 - 5.00 | 38.3 - 82.37 | 14.3 - 54.93 |

## [122. Best time to buy and sell stock II.][122]

Buy on local minimums and sell on local maximums. This can be done by going through
the prices in pairs and buying only if the price of the previous day was smaller
than that of the next day and only selling if the price of the previous day is larger
than that for the next.

A toggle for the action is used to differentiate the cases (buying/selling).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 97.15 | 0 - 100.00 | 76 - 92.04 | 52 - 96.93 |
| Mem Usage (MB-%)| 6.9 - 46.64 | 2.1 - 76.47 | 39.2 - 72.89 | 15.1 - 54.54 |

## [136. Single Number][136]

Pretty well known xor trick. Based on the property that xor of two equal
numbers is zero.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 99.30 | 0 - 100.00 | 80 - 92.47 | 112 - 99.63 |
| Mem Usage (MB-%)| 7.1 - 99.80 | 2.1 - 81.55 | 39.9 - 98.51 | 16.7 - 29.16 |

## [155. Min Stack.][155]

See each file for detailed comments. Basically, hold min around and update it if we
pop it off at any point.

All operations other than pop (which is `O(N)`) are done in `O(1)` or amortized `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 24 - 97.52 | 0 - 100.00 | 112 - 96.23 | 48 - 99.24 |
| Mem Usage (MB-%)| 12.6 - 93.39 | 5.5 - 96.15 | 45.4 - 71.54 | 17.9 - 66.92 |

## [167. Two sum II input array is sorted.][167]

Array is sorted, use two counters (start, end) and increase, reduce respectively
until we reach our target sum.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 99.02 | 0 - 100.00 | 72 - 97.24 | 56 - 95.51 |
| Mem Usage (MB-%)| 6.6 - 99.02 | 2.1 - 60.71 | 38.8 - 71.96 | 14.5 - 91.92 |

## [171. Excel Sheet column number][171]

To find the column number we can follow the following formula where `s` is the input
string and `n` is its length:

```
col = sum((charCodePoint - 64) * (pow(26, i)) for i in [0..n])
```

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 88 - 95.33 | 24 - 96.97 |
| Mem Usage (MB-%)| 5.6 - 69.08 | 2 - 100.00 | 39.8 - 84.74 | 14.2 - 66.98 |

## [190. Reverse Bits.][190]

Count how many leading zeros exist in a 32bit padded (with zeros from MSB) version of the input number. Then just
add the bits from the input number to the result. This is done by shifting the result left by one and adding `n & 1` to
it and then shifting `n` to the right. Finally, we shift right as many times as we counted for the leading zeroes.

Javascript: couldn't adapt same solution. TODO.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | - | 28 - 87.17 |
| Mem Usage (MB-%)| 5.3 - 75.25 | 2 - 71.43 | - | 14.3 - 8.01 |

## [191. Number of 1 bits.][191]

Not much point in adding things here. The most efficient implementation is discussed in the [wiki page](https://en.wikipedia.org/wiki/Hamming_weight#Efficient_implementation) which also discusses a good strategy to optimize by using a cache of the result for all 16
bit sequences (which we can use for 32bit numbers by viewing them as two 16bit sequences).

For all intents and purposes, the algorithm I would run (if the language doesn't offer an implementation (rust, python do)) would be the
common iterative `O(N)`:


    int count = 0;
    while (n) {
        n &= n - 1;
        count += 1;
    }
    return count;


## [206. Reverse Linked List][206]

`C` contains both iterative and recursive. The rest use iterative.

Note: Needless to say, Rust timings seem a bit off! Check again if you see
this in the future, future me.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 81.03 | 280 - 100.00 | 80 - 84.82 | 32 - 85.73 |
| Mem Usage (MB-%)| 6.2 - 98.35 | 2.5 - 51.56 | 40 - 94.38 | 15.4 - 69.73 |

## [217. Contains Duplicate.][217]

Can use a set and check if we've seen an element before (or, build a full set and
compare its size against that of the size of the original array.)

(`C` and `uthash` again seem slow)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 24 - 41.52 | 0 - 100.00 | 76 - 98.14 | 108 - 96.99 |
| Mem Usage (MB-%)| 17 - 10.73 | 2.7 - 84.62 | 45 - 54.84 | 20.1 - 81.21 |

## [225. Implement Stack Using Queues.][225]

Don't particularly like these problems (also see Queue using Stacks). I'll just
add the Python solution, not really planning on adding others.

Uses a single queue actually since I really couldn't see the point of using a
second queue instead of rotating, adjusting to use second queue is straight-forward.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| N/A | N/A | N/A | 24 - 94.57 |
| Mem Usage (MB-%)| N/A | N/A | N/A | 14.4 - 46.41 |

## [226. Invert Binary Tree][226]

Most (`C`, `Javascript` and `Rust` (because I hate myself, apparently)) 
use recursion to swap the nodes. Python uses an iterative approach by
utilizing a stack.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 95.23 | 20 - 99.04 |
| Mem Usage (MB-%)| 5.8 - 99.02 | 2 - 88.89 | 38.9 - 55.11 | 14.2 - 39.78 |

## [231. Power of two.][231]

`x = 2 ** n <=> n = log2(x)`. For non-powers of two `log2(x)` is not an integer. This boils down
to checking if `log2(x)` is an integer which can be done with `ceil(log2(x)) == log2(x)`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 98.66 | 24 - 95.94 |
| Mem Usage (MB-%)| 5.5 - 56.84 | 2.5 - 6.25 | 40.2 - 13.07 | 14.2 - 40.52 |

## [232. Implement Queue using Stacks.][232]

Only uses stack equivalent operations. Two lists are created, one that holds values
pushed and one that holds values that will be popped. When time comes to pop/peek,
we check to see if the list holding values to be popped is empty. 

If it's emtpy, we continuously push the values popped from the other list (thereby
restoring the FIFO principle). 

If it isn't empty, we immediatelly just pop/peek from it.

`is_empty` is `O(1)`. The rest are amortized `O(1)` operations (`push` definitely is,
at least. I'm relatively certain `peek` and `pop` are too).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 99.36 | 20 - 98.63 |
| Mem Usage (MB-%)| 5.8 - 96.97 | 1.9 - 100.00 | 38.4 - 67.68 | 14.1 - 98.99 |

## [237. Delete node in a Linked List][237]

Swap contents of `node` with contents of `node.next`. Rust version not
available.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 95.10 | N/A | 80 - 94.74 | 20 - 100.00 |
| Mem Usage (MB-%)| 6.3 - 99.87 | N/A | 40.2 - 84.74 | 14.7 - 19.26 |

## [242. Valid anagram.][242]

All except for C use a counter. No idea why `Rust` can't go lower than `4` though
I believe I could get it there with the same hack as in `C`.

Note: `C` case just seems hacky as hell, read comments (which do a pretty poor job
of explaining). 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 4 - 61.40 | 84 - 95.92 | 28 - 99.36 |
| Mem Usage (MB-%)| 5.8 - 85.24 | 2.1 - 100.00 | 40.9 - 64.49 | 14.5 - 69.02 |

## [257. Binary Tree Paths,][257]

Recursively build path by holding (and passing) the partially constructed path
as an argument to the recursive function.

The path is added to the result once we reach a leaf.

Runtime complexity should be `O(N)` since we traverse each node. Space complexity
is related to the number of branches.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 99.71 | 24 - 97.96 |
| Mem Usage (MB-%)| 6.1 - 100.00 | 2 - 100.00 | 40.1 - 86.55 | 14 - 99.37 |

## [258. Add digits,][258]

This is one of those cases where you need to examine what the results are in order
to realize the solution. After running mucho input cases, notice that the result
is `num % 9` with special cases if `num == 0` and `num % 9 == 0`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 99.49 | 20 - 99.19 |
| Mem Usage (MB-%)| 5.7 - 39.50 | 2 - 100.00 | 39.9 - 84.01 | 14.2 - 36.59 |

## [268. Missing Number,][268]

Yet another variation of the xor trick. Since all numbers are in range `[0, n)` and
we know only one is missing, we can use another variable ranging from `[0, n)` and
xor it along with all the numbers in the numbers array. 

Since numbers with the same value will be xored out, the missing number will be the
one left.

Runtime complexity is `O(N)`, space complexity is `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 92.23 | 0 - 100.00 | 80 - 91.77 | 120 - 96.29 |
| Mem Usage (MB-%)| 6.5 - 75.34 | 2 - 97.30 | 41.3 - 34.19 | 15.3 - 82.34 |

## [278. First bad version.][278]

Binary search, again.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 96.69 | 24 - 93.25 |
| Mem Usage (MB-%)| 5.5 - 53.47 | 2 - 81.08 | 38.4 - 45.85 | 14.1 - 73.36 |

## [283. Move zeroes.][283]

In order to minimize the comparisons made, our `run` variable always begins scanning
from the position in which a non-zero value was last found (which is zero in the
beginning). This way we only see each element in the nums array twice (once for the
`on_zero` variable tracking zeroes and once for the `run` variable tracking non-zero
values).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 100.00 | 0 - 100.00 | 76 - 98.15 | 32 - 99.97 |
| Mem Usage (MB-%)| 7.6 - 89.22 | 2.1 - 97.87 | 40.3 - 51.81 | 15.2 - 68.67 |

## [292. Nim Game,][292]

After some experimenting, we can see that the losing starting position is a multiple
of `4`. This makes sense, if we are on a multiple of `4`, our opponent can always
make the total stones decrease by `4` when playing optimally. This will lead to a
final count of `4` with us having to play and not being able to win the game.

In all other positions we can do the same, taking the correct ammount initially in
order to leave our opponent to make their first move with a number of rocks that is 
a multiple of `4`.

Space/Time complexity is `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 89.79 | 20 - 98.68 |
| Mem Usage (MB-%)| 5.5 - 41.79 | 1.9 - 75.00 | 38.2 - 76.88 | 13.9 - 97.16 |

## [326. Powers of three.][326]

Similar to powers of two. Find `log3(n)` and then check how close `round(log3(n))` is to `log3(n)`. Powers of
three will have a value of `log3(n)` close to some integer `x`. I'm under the impression a better solution
exists but it is 4am and no.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 97.77 | 4 - 100.00 | 244 - 76.58 | 56 - 98.86 |
| Mem Usage (MB-%)| 6.5 - 13.41 | 2.6 - 5.00 | 49.4 - 43.63 | 14.4 - 13.70 |

## [342. Power of four.][342]

Exactly the same as Powers of three, only difference is that we use `log4(n)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 100.00 | 24 - 95.62 |
| Mem Usage (MB-%)| 5.9 - 12.62 | 2.7 - 5.56 | 40 - 36.68 | 14.3 - 6.03 |

## [344. Reverse String][344]

Typical swapping.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 44 - 96.89 | 16 - 94.12 | 100 - 96.48 | 184 - 96.43 |
| Mem Usage (MB-%)| 12.4 - 74.64 | 5.4 - 98.82 | 45.5 - 79.32 | 18.7 - 14.37 |

## [347. Top k frequent elements.][347]

Counting + Building a k-element heap. Complexity of operation is `O(NlogK)` instead of
`O(NlogN)`. Python contains a built-in version of this `Counter.most_common` so Rust is
probably the best place to look for each of these steps layed out sequentially.

C: Not up for implementing my own binary heap (probably should and just keep it around).
Javascript: Priority Queue available seems somewhat broken to me? I can't seem to get it to
work for some reason.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| | 0 - 100.00 | | 88 - 98.51 |
| Mem Usage (MB-%)| | 2.4 - 65.63 | | 18.7 - 76.49 |

## [349. Intersection of two arrays.][349]

Build sets and get intersection (or write it for `C` and `JS` cases.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 98.18 | 32 - 99.40 |
| Mem Usage (MB-%)| 7.7 - 12.87 | 2.1 - 77.78 | 40.5 - 28.27 | 14.4 - 22.10 |

## [374. Guess number higher or lower.][374]

Simple binary search for the number. `O(logn)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 88.26 | 20 - 98.89 |
| Mem Usage (MB-%)| 5.5 - 52.67 | 1.9 - 66.67 | 38.3 - 81.91 | 14.2 - 42.20 |

## [383. Ransom Note][383]

Use a counter to check that the required ammount of characters are present. 

In C, Rust and JavaScript, an array of size 26 is filled up with the characters in the
magazine and then the characters from the ransom note are subtracted. If at any point
the value inside the array is zero, it means we've run out of characters.

Runtime complexity is `O(N + M)` where `N` and `M` are the sizes of the strings given.
Space complexity is `O(1)` since we only have 26 characters.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 99.57 | 40 - 86.90 |
| Mem Usage (MB-%)| 6.4 - 96.59 | 2.1 - 100.00  | 41.2 - 91.14 | 14.1 - 99.69 |

## [384. Shuffle an Array.][384]

Uses Fisher-Yates algorithm (the Durstenfeld's version) in order to shuffle sequence. This
leads to `O(N)` execution.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 212 - 82.28 | 24 - 100.00 | 228 - 89.90 | 264 - 89.11 |
| Mem Usage (MB-%)| 36.9 - 29.54 | 5.4 - 60.00 | 51.5 - 96.63 | 19.4 - 71.11 |

## [387. Find Unique Character in String.][387]

Build a Counter (in Python we use library supplied, in others, just use an array with
26 slots to act as Counter) and then go through characters of `s` and find the first
for which the count is equal to `1`.

Runtime complexity is `O(N)` for all, space is `O(1)` I believe since we always have
a collection with 26 elements regardless of string length.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 99.00 | 0 - 100.00 | 96 - 95.44 | 88 - 90.37 |
| Mem Usage (MB-%)| 6.9 - 80.90 | 2 - 78.26 | 42.4 - 58.18 | 14.4 - 70.26 |

## [389. Find the difference.][389]

Xor trick, different problem statement.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 98.01 | 28 - 92.43 |
| Mem Usage (MB-%)| 5.7 - 96.92 | 2 - 100.00 | 39 - 96.03 | 14.1 - 94.66 |

## [405. Convert a number to hexadecimal.][405]

Use a small table `[0, 1, 2, ..., 14, 15] => ['0', '1', '2', ..., 'e', 'f']` to translate between
the values from `[0-15]` to appropriate hex symbols. We manipulate the input number `n` in pairs of
`4`bits (`n & 15` and `n >> 4`) which we use to look up the value in the table. 

To handle 2's complement (infinite 1's to the left), we simply bound the loop to generate a maximum of
`8` hex symbols.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 90.67 | 24 - 94.23 |
| Mem Usage (MB-%)| 5.4 - 85.25 | 2 - 100.00 | 38.4 - 90.67 | 14.3 - 11.14 |

## [412. Fizz-buzz.][412]

Straight-forward translation of statement, only trick is not performing `i % 3` and
`i % 5` twice do see if a number is a multiple of both `5` and `3`. We can use the
result of `i / 3` and see if that is divided by `5`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 69.37 | 0 - 100.00 | 76 - 96.82 | 34 - 92.74 |
| Mem Usage (MB-%)| 7 - 86.04 | 2.6 - 95.24 | 41.4 - 5.36 | 15 - 73.21 |

## [429. N-ary Tree Level Order Traversal.][429]

Similar to problem [Binary Tree Level Order Traversal][102]. The only difference being
that we know iterate through all children and add them to the stack. (implicit or explicit one.)
Complexity is the same, `O(N)` runtime/memory.

Rust: not available.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| - | N/A | 92 - 94.98 | 44 - 95.28 |
| Mem Usage (MB-%)| - | N/A | 43.7 - 26.96 | 16 - 87.08 |

## [448. Find all numbers disappeared in an array.][448]

Couldn't see (yet) how to do it with `O(1)` space. For now, I use `O(N)` space
in the form of a vector or set in order to find disappeared numbers.

*TODO: Revisit but not urgently.*

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 92 - 98.94 | 8 - 98.04 | 96 - 99.71 | 312 - 99.29 |
| Mem Usage (MB-%)| 18.4 - 18.62 | 2.6 - 43.14 | 47.4 - 47.02 | 24.7 - 17.49 |

## [460. Minimum Changes to make alternating binary string.][460]

Need to count changes both version of alternating strings (`'010101..', '101010..'`). Call
a counting function that finds the counts for each of these cases and return the min value. Since
we only iterate through `s`, runtime complexity is `O(N)`. Space complexity is `O(1)`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 92.66 | 40 - 92.84 |
| Mem Usage (MB-%)| 5.7 - 100.00 | 2 - 100.00 | 39.4 - 51.05 | 14.2 - 96.60 |

## [461. Hamming Distance][461]

Get the xor of the two numbers (where bits differ) and then 
count set bits.

I'm under the impression I'm missing some other obvious 
solution here.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 82.30 | 28 - 76.20 |
| Mem Usage (MB-%)| 5.5 - 67.52 | 2 - 100.00 | 38.5 - 71.22 | 14.1 - 61.18 |

## [476. Number Complement.][476]

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 76 - 85.35 | 24 - 94.21 |
| Mem Usage (MB-%)| 5.6 - 63.49 | 2 - 80.00 | 38.1 - 94.27 | 14 - 95.98 |

## [485. Max Consecutive Ones][485]

We have to scan the full array looking for the max consecutive number of ones. Runtime
complexity is `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 36 - 95.44 | 0 - 100.00 | 80 - 92.82 | 332 - 96.94 |
| Mem Usage (MB-%)| 7.4 - 97.54 | 2 - 85.71 | 41,6 - 32.50 | 14.3 - 92.44 |

## [496. Next greater element I.][496]

Python has three solutions, brute force, with a bit of supporting structures and
with a lot. Last is used and in the others and described here.

We initialize the resulting array to all -1's and create a mapping from values to
their indices. We go through each element in `nums2` and for each:

 1. If it is contained in our mapping, we add it to a set that keeps track of values
	seen. 
 2. We iterate through the values of seen, if, for any value of seen, we find that
	it is smaller than the element of `nums2` we're iterating through, we add it
	to the result array (where we add it is found by using the mapping). 

For any values not in `nums1` and for any values in `nums1` for which no larger
element exists on the right, the initial value of `-1` stays. The trick here is
that for each element of `nums2` we only iterate over a very small subset of
`nums1` (the ones in `seen`). This way we can reduce the overall iterations
performed.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 76 - 97.12 | 36 - 98.72 |
| Mem Usage (MB-%)| 10.4 - 6.67 | 2 - 100.00 | 40.5 - 42.45 | 14.6 - 18.78 |

## [500. Keyboard Row][500]

Make sets out of rows on keyboard and check if input strings are contained
in the sets.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 97.03 | 24 - 92.53 |
| Mem Usage (MB-%)| 5.8 - 20.69 | 2 - 100.00 | 38.6 - 33.83 | 14.1 - 44.11 |

## [509. Fibonacci Number][509]

Calculate it iteratively.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 97.37 | 20 - 98.15 |
| Mem Usage (MB-%)| 5.4 - 86.96 | 2 - 48.78 | 38.3 - 56.54 | 14.1 - 34.89 |

## [520. Detect Capital.][520]

We can just check the second character and disambiguate which case we're examining.
Then we just make sure all the following characters match the case.

`O(N)` runtime complexity with `O(1)` space complexity.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 100.00 | 20 - 98.83 |
| Mem Usage (MB-%)| 5.5 - 98.33 | 2 - 60.00 | 39.8 - 81.21 | 14.2 - 48.87 |

## [521. Longest Uncommon Subsequence.][521]

If the strings are equal, all subsequences are the same, return -1.
Else, return the largest among the strings.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 95.35 | 24 - 93.63 |
| Mem Usage (MB-%)| 5.4 - 100.00 | 2 - 100.00 | 38.4 - 61.63 | 14 - 98.24 |

## [530. Minimum absolute difference in bst.][530]

C and Rust both traverse the bst and build a sorted vector. Python and Javascript
use a generator to yield back values. Whatever the case, we then traverse through
the value and find the minimum.

Note: Javascript would probably be faster if I didn't use generators. Problem is,
I really like generators so I don't care.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 97.44 | 0 - 100.00 | 128 - 14.84 | 48 - 96.33 |
| Mem Usage (MB-%)| 10.8 - 20.51 | 2.9 - 25.00 | 46.2 - 9.03 | 16.3 - 32.45 |

## [535. Encode and Decode TinyURL.][535]

As basic as it gets implementation. (Note: just returning the string as-is actually
works, they don't test to guard against this).

There's an issue with Rust in that the test code declares the coder as immutable
thereby not allowing us to pass it mutably by reference.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| | N/A | 84 - 93.40 | 24 - 97.30 |
| Mem Usage (MB-%)| | N/A | 40 - 83.96 | 14.2 - 58.76 |

## [538. Convert BST to Greater Tree][538]

Code used is exactly the same for [Binary Search Tree to Greater Sum Tree](1038).
As such, see `1038.*` files for the code. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 92.86 | 0 - 100.00 | 100 - 100.00 | 72 - 98.64 |
| Mem Usage (MB-%)| 13.7 - 100.00 | 2.9 - 83.33 | 47.7 - 28.72 | 16.7 - 80.07 |

## [557. Reverse Words in a String III][561]

C mutates the string in-place because it's allowable there. 
The rest split on `' '`, iterate through the chunks and 
reverse them.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 93.81 | 0 - 100.00 | 88 - 74.93 | 24 - 97.41 |
| Mem Usage (MB-%)| 6.9 - 72.57 | 2.3 - 72.73 | 44.6 - 85.18 | 14.6 - 84.18 |

## [559. Maximum depth of N-Ary Tree][559]

Common recursive approach (call depth on all children.)

Note: For some reason, `maxDepth` in `C` is defined as returning `int *`.
Note: Rust case not applicable, they don't allow the option yet.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00  | N/A | 84 - 95.55 | 40 - 91.04 |
| Mem Usage (MB-%)| 7.3 - 8.70 | N/A | 42.1 - 33.27 | 16.2 - 7.06 |

## [561. Array Partition I][561]

Sort the array in reverse order and sum every second 
element.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 52 - 80.25 | 8 - 96.15 | 120 - 93.30 | 244 - 97.34 |
| Mem Usage (MB-%)| 8.5 - 27.16 | 2.2 - 100.00 | 44 - 79.12 | 16.5 - 81.43 |

## [566. Reshape the matrix.][566]

Check that new dimensions can hold elements and then go through each
element in `nums` and place it in new position based on `r` and `c`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 36 - 100.00 | 0 - 100.00 | 96 - 96.50 | 84 - 99.31 |
| Mem Usage (MB-%)| 11.4 - 100.00 | 2.3 - 100.00 | 44.6 - 51.05 | 15.2 - 59.61 |

## [575. Distribute Candies][575]

Use a set and compare its size with the ammount prescribed (Goes south for `C`
though, which might mean there's a different better way at it.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 224 - 21.43 | 24 - 100.00 | 128 - 90.75 | 764 - 92.56 |
| Mem Usage (MB-%)| 68.3 - 7.14 | 2.2 - 86.67 | 52.7 - 35.24 | 16.5 - 8.60 |

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

## [606. Construct string from binary tree.][606]

Preorder traversal through the tree and build the string. If we don't have a left
subchild but do have a right one, we need to add the extra `'()'` as stated in
the problem statement.

For C, couldn't be buggered, really. Need to recurse through the tree with a
pointer to `char *` array and add things to it. Then, join them all together
at the end. Might do some point in the future, for now, nope.

Time complexity is `O(N)`, space complexity is probably the same.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| - | 0 - 100.00 | 84 - 97.62 | 40 - 98.24 |
| Mem Usage (MB-%)| - | 3.1 - 100.00 | 48.6 - 5.56 | 16.5 - 10.29 |

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

## [637. Average of Levels in Binary Tree][637]

Python, Rust use iterative approach: we use a deque that holds a special
marker (i.e `None`) which we use to track on which level we are on. Until we
reach that marker, we add the values and count the nodes. When we reach the
marker, we take the average and add it to the result array.

The iteration stops when for a given level, the number of Nodes we've counted
is zero.

`C` and `Javascript` use a recursive approach whereby each level of the tree
is represented by a `level` parameter of the recursive function. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 84 - 97.80 | 36 - 99.85 |
| Mem Usage (MB-%)| 20.7 - 5.36 | 3 - 50.00 | 45 - 18.13 | 16.5 - 60.71 |

## [643. Maximum average subarray I.][643]

`O(N)`, the main thing to notice (I believe) is the fact that you do not need to calculate the
full summation for the average each time (k terms added and divided by k). Instead, you can build
the summation until `k` and then move along the array looking for the max. At the end of each loop
we remove the first term of the summation and add the term we've currently looked at.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 100 - 100.00 | 12 - 100.00 | 92 - 97.89 | 780 - 96.34 |
| Mem Usage (MB-%)| 10.5 - 50.75 | 2.4 - 33.33 | 47.9 - 37.19 | 18.1 - 10.88 |

## [653. Two Sum IV - Input is a BST.][653]

Use a set to hold the values and traverse tree. For each node see if `k - node.value`
is present inside the set, if so, done.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 98.11 | 0 - 100.00 | 104 - 97.44 | 68 - 97.46 |
| Mem Usage (MB-%)| 25.6 - 18.87 | 3.3 - 80.00 | 48.7 - 22.16 | 16.3 - 94.07 |

## [654. Maximum Binary Tree.][654]

Work with ranges. Start by calling recursive function in full range. Find max and its
index in the nums array and then recurse on `[start, id_max]` for the left subtree
and `[id_max + 1, end]` for the right subtree.

Create node and return.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 36 - 98.11 | 8 - 100.00 | 108 - 96.08 | 192 - 88.87 |
| Mem Usage (MB-%)| 26.9 - 90.57 | 2.1 - 100.00 | 45.1 - 77.94 | 15.1 - 8.05 |

## [657. Robot Return to Origin][657]

Count occurences and compare. If number of 'D's matches number 
of 'U's and number of 'L's matches number of 'R's, we're good.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 95.76 | 0 - 100.00 | 80 - 90.34 | 32 - 94.10 |
| Mem Usage (MB-%)| 6 - 57.63 | 1.9 - 100.00 | 39.7 - 61.54 | 14.2 - 67.31 |

## [669. Trim a binary Search Tree.][669]

Initially we need to see where our root value lies. If it isn't inside the
acceptable range, we need to adjust it until it is. This is done by setting
the root to right or left depending if the value of root is smaller than
`low` or larger than `high` respectively.

After we have found a new root, we continuously recurse on children and, by
keeping a reference to their parent, trim any node not inside the range by
re-assigning pointers/attributes. Recursion is terminated when we reach
all leaves.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 76.47 | 0 - 100.00 | 88 - 86.70 | 40 - 97.47 |
| Mem Usage (MB-%)| 10.6 - 64.71 | 2.9 - 87.50 | 44.2 - 83.74 | 14.1 - 46.08 |

## [682. Baseball Game][682]

While loop your way through the operations, make sure you skip performing an
operation if it is followed by a `"C"`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 92.51 | 32 - 96.73|
| Mem Usage (MB-%)| 6.2 - 55.17 | 2.1 - 100.00 | 38.9 - 90.64 | 14.4 - 53.20 |

## [690. Employee Importance][690]

Transform employees into a dictionary keyed by the id. Then we can build a list of
all subordinates by continuously keying the dictionary and build up the overall
importance.

*NOTE: Rust and C versions not available.* 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| N/A | N/A | 80 - 97.80 | 144 - 98.93 |
| Mem Usage (MB-%)| N/A | N/A | 44.2 - 17.56 | 15.5 - 53.57 |

## [693. Binary Number with alternating bits.][693]

Check adjacent bits until we reach end. If at any point a pair of adjacent bits is the
same, return False.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 95.92 | 20 - 99.27 |
| Mem Usage (MB-%)| 5.5 - 55.67 | 1.9 - 66.67 | 38.6 - 53.06 | 14.4 - 5.57 |

## [696. Count binary substrings.][696]

Go through each character and build count of adjacent groups by using a couple
of flags. Count of adjacent groups can then be found easily.

Note: Rust :(

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 93.75 | 4 - 60.00 | 84 - 93.42 | 112 - 96.53 |
| Mem Usage (MB-%)| 6.7 - 100.00 | 2 - 100.00 | 41.8 - 92.11 | 14.5 - 88.91 |

## [697. Degree of an Array.][697]

Build a counter of the numbers in the array in order to find the maximum degree
along with which numbers have that maximum degree.

After that we can iterate through the numbers array from the left (start) and 
right (end) and look for the leftmost and rightmost occurences for each of the 
numbers that has that maximum degree.

The minimum difference `end - start` for each of the numbers with max degree is
the result.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 100.00 | 4 - 100.00 | 84 - 98.22 | 196 - 99.93 |
| Mem Usage (MB-%)| 9.8 - 22.22 | 2.2 - 100.00 | 44.5 - 36.89 | 15.2 - 98.41 |

## [700. Search in a BST][700]

Straight-forward. Perform binary search. `C` code also contains 
a tail-recursive version, didn't seem to make much difference
in runtime/memory timings.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 89.04 | 4 - 100.00 | 44 - 98.93 | 64 - 97.56|
| Mem Usage (MB-%)| 15.1 - 73.25 | 2.6 - 57.14 | 44.4 - 76.63 | 15.8 - 94.95|

## [704. Binary Search.][704]

Well, binary search. `O(logn)` complexity, `O(1)` space.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 28 - 98.79 | 0 - 100.00 | 76 - 92.07 | 216 - 99.84 |
| Mem Usage (MB-%)| 6.9 - 99.19 | 2.1 - 100.00 | 42.4 - 52.53 | 15.5 - 91.95 |

## [705. Design HashSet][705]

Python contains implementations for both separate chaining and open addressing, so
does `Rust` (well, an attempt at separate chaining, at least).

Have some odd bug in Javascript which I'll give up on trying to track down for now.
Adding code so far.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 76 - 100.00 | 16 - 100.00 | N/A | 196 - 57.80 |
| Mem Usage (MB-%)| 26.1 - 96.83 | 5.6 - 66 | N/A | 18.9 - 53.31 |

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

## [748. Shortest completing word][748]

To be frank, don't think things are good here. Might need to place this problem in
the revisited section. I won't much bother with `C` with the current solution that
uses a host of maps/sets.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| | 4 - 66.67 | 96 - 75.76 | 60 - 97.43 |
| Mem Usage (MB-%)| | 2.1 - 66.67 | 43.7 - 51.51 | 14.6 - 24.70 |

## [766. Toeplitz Matrix][766]

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 98.44 | 0 - 100.00 | 84 - 91.64 | 80 - 86.38 |
| Mem Usage (MB-%)| 6 - 98.44 | 2 - 75.00 | 40.5 - 40.68 | 14.1 - 90.26 |

## [771. Jewels and Stones][771] 

Add the values of J to a set and count number of jewels by 
using the set membership test to quickly establish if a 
character is a jewel.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 73.22 | 24 - 93.75 |
| Mem Usage (MB-%)| 5.8 - 25.51 | 2.1 - 100.00 | 40.4 - 11.66 |14.2 - 99.99 |

## [783. Minimum Distance between bst nodes.][783] 

Same as problem [530. Minimum absolute difference in bst][530], see there.

## [788. Rotated Digits][788]

I'll probably need to write this up in a separate `.md` file. Until then,
see the source code for the Python case where I prototyped and added
most comments.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 94.16 | 20 - 99.86 |
| Mem Usage (MB-%)| 5.7 - 45.71 | 2 - 66.67 | 38 - 100.00 | 14.1 - 90.83 |

## [804. Unique Morse Code Words.][804]

Build the morse code words and add them to a set. After adding 
all words just return the length of the, now, unique set of 
morse code words.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 86.43 | 24 - 99.14|
| Mem usage (mb-%)| 6.1 - 13.33 | 2 - 100.00 | 39.4 - 6.79 | 14.1 - 100.00 |

## [806. Number of lines to write string.][806]

Build a mapping from lowercase english characters to their width in the `widths`
array. Then, gradually find the lines needed.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 90.28 | 20 - 99.40 |
| Mem usage (mb-%)| 5.8 - 44.44 | 2 - 66.67 | 39.4 - 12.50 | 14.2 - 48.64 |

## [807. Max increase to keep city skyline.][807]

Max ammount that we can grow is `min(max_of_row, max_of_col)`. We can just find
these values and compute the maximum increase.

Pretty sure complexity is around `O(N*M)`, inner loop computing maximum for column only 
runs once per column, this means that we have a significant lower term in our
complexity equation.  

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 93.02 | 0 - 100.00 | 80 - 91.76 | 64 - 96.36 |
| Mem usage (mb-%)| 6 - 97.67 | 2.1 - 86.67 | 39.1 - 92.86 | 14.3 - 61.22 |

## [811. Subdomain visit count.][811]

Hold domains/subdomains in a Counter and count values after 
splitting domain up.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 71.43 | 4 - 100.00 | 92 - 93.28 | 44 - 95.94|
| Mem usage (mb-%)| 9.6 - 28.57 | 2.2 - 25.00 | 43.4 - 70.71 | 14.4 - 26.05 |

## [812. Largest Triangle Area.][812]

Initially I tried to see if we can skip taking all combinations by trying to find
two points that are maximally appart and using those as the two initial points.
Unfortunately, this isn't correct.

After this I tried using Heron's formula to find the area based on the length of the
sides of the trianges (found using Euclidean distance). While working, this wasn't
very efficient.

Thankfully, after some digging around was able to find the Shoelace formula which made
my life easier because I only uses the three points of the triangle to calculate the
area.

Still, algorithm is dominated by the fact that we have to go through all combinations
(and I can't think of a way to reduce the iteration space).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 87.50 | 0 - 100.00 | 80 - 93.33 | 96 - 94.12 |
| Mem usage (mb-%)| 5.8 - 100.00 | 2 - 100.00 | 39 - 60.00 | 14.3 - 48.90 |

## [821. Shortest Distance to a Character.][821]

By keeping around the positions the character is found and the previous position
found, we can easily build the ranges after taking care of some special
cases.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 76 - 99.41 | 28 - 98.30 |
| Mem usage (mb-%)| 6 - 100.00 | 2 - 100.00 | 41 - 28.99 | 14.1 - 97.67 |

## [824. Goat Latin.][824]

Not much to break down here. Just do what the problem states.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 94.85 | 24 - 93.52 |
| Mem usage (mb-%)| 5.9 - 84.21 | 2 - 87.50 | 38.8 - 59.56 | 13.9 - 97.34 |

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

## [859. Buddy strings.][859]

See comments in python file (`859.py`) for a better description. `O(N)` execution.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 100.00 | 24 - 98.49 |
| Mem usage (mb-%)| 5.7 - 56.92 | 2.2 - 81.82 | 41.2 - 35.74 | 14.5 - 71.61 | 

## [867. Transpose Matrix.][867]

Straight-forward transpose.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 24 - 97.44 | 0 - 100.00 | 80 - 97.45 | 68 - 96.25 |
| Mem usage (mb-%)| 10.1 - 20.51 | 2.2 - 50.00 | 40.7 - 79.27 | 14.9 - 44.26 |

## [868. Binary Gap.][868]

Go through each bit of `n` (via `n >>= 1`) and count the distance between
two ones. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 97.12 | 20 - 98.78 |
| Mem usage (mb-%)| 5.6 - 46.88 | 2 - 100.00 | 38.8 - 50.00 | 14.2 - 57.69 |

## [872. Leaf similar trees.][872]

For Python: recursion delegating to sub-generators. Helpful.
For the rest: function that receives stack and returns leaves as we encounter
them.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 97.33 | 20 - 99.00 |
| Mem usage (mb-%)| 6.3 - 90.20 | 2 - 66.67 | 40.3 - 73.66 | 14.3 - 17.11 |

## [876. Middle of the Linked List][876]

Traverse the list while keeping a reference to the middle element.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 89.27 | 20 - 98.87 |
| Mem usage (mb-%)| 5.8 - 68.20 | 2 - 80.00 | 38.2 - 89.15 | 14 - 73.76 |

## [883. Projection Area of 3d Shapes][883]

Length of rows is the same.

View from Z axis is simply a count of all non-zero values.

View from X axis is the max of each row/cell. 

View from Y axis is the max of each column.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 100.00 | 0 - 100.00 | 68 - 100.00 | 60 - 97.64 |
| Mem usage (mb-%)| 6 - 100.00 | 2 - 50.00 | 39 - 58.82 | 14.1 - 77.88 |

## [884. Uncommon words from two sentences.][884]

Create two sets for each String, a set of seen words and a set of words
unique in each String.

Then we take the difference of the unique words in string `A` and the
seen words in `B` (to only keep unique words not in the other string). We
do the same thing for the unique words of `B`.

Then we can take their union.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 96.65 | 24 - 94.61|
| Mem usage (mb-%)| 7.3 - 16.67 | 2.1 - 66.67 | 39.1 - 33.97 | 14.1 - 88.96 |

## [888. Fair Candy Swap.][888]

Brute force approach is going through each pair and checking. 

A sligtly better option is to filter values based on if they bring us in the right
range (which can be found by adding the sums and dividing by two).

The best approach in the end is to use a set for one of the arrays. Then, knowing what
the difference between the two sums is in the beginning, we can go through the elements
of one array and find what the value should be in order to fill the difference between
the initial sums. If the value found is inside the set created for the other array, we've
found our element (which is guaranteed to exist).

**NOTE: C timings indicate either that uthash is slow or that a better option exists
that I haven't seen yet.**

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 88 - 48.16 | 8 - 100.00 | 100 - 97.93 | 332 - 99.56 |
| Mem usage (mb-%)| 26.6 - 11.11 | 2.5 - 100.00 | 48.1 - 28.28 | 16.6 - 41.79 |

## [896. Monotonic Array.][896]

Note that equal elements can't be ignored.

Find first non-equal pair in array, this initializes a flag that indicates the
direction the rest of the elements should be in in order for the array to be
monotonic. As soon as a pair isn't in the right direction, return `false`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 56 - 94.29 | 4 - 100.00 | 88 - 93.66 | 448 - 91.01 |
| Mem usage (mb-%)| 9.4 - 100.00 | 2.4 - 92.31 | 45 - 61.09 | 20.5 - 53.08 |

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

## [908. Smallest Range I.][908]

Find min and max of the array. IF `max - K - min` falls in the range `[-K, K]` we
can use any value of that range to reduce the difference to `0`. If it doesn't,
then, if `max - K - min` is positive, subtract `K` from it (to minimize the
difference) or, if negative, add `K` to it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 88.89 | 0 - 100.00 | 72 - 96.74 | 96 - 100.00 |
| Mem Usage (MB-%)| 6.5 - 100.00 | 2 - 100.00 | 39.8 - 85.87 | 15.2 - 97.14 |

## [917. Reverse only letters.][917]

Code was written very quickly. Uses a set of acceptable characters and only switches when
we are on a valid pair of characters (in ascii letter range).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 94.95 | 24 - 95.12 |
| Mem Usage (MB-%)| 5.9 - 26.32 | 2 - 50.00 | 38.9 - 51.51 | 14.4 - 12.88 |

## [922. Sort Array By Parity II][922]

Preallocate resulting array. Then go through input array and using two
variables to denote the positions of the odds and evens, fill the 
array.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 64 - 93.81 | 8 - 100.00 | 88 - 100.00 | 196 - 92.39 |
| Mem Usage (MB-%)| 13.5 - 51.55 | 2.1 - 77.78 | 44.4 - 74.18 | 16.8 - 15.40 |

## [929. Unique Email Address.][929]

Either step through the characters directly (see `C` and `Python` and `Rust` files)
or use string facilities that do that for you (see `Python` and `Javascript`).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 98.31 | 0 - 100.00 | 88 - 91.97 | 44 - 91.99 |
| Mem Usage (MB-%)| 8.1 - 10.17 | 2.1 - 93.33 | 44 - 41.89 | 14.4 - 7.90 |

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

## [937. Reorder Data in log files.][937]

Separate into two arrays, one containing the logs that only have digits after the
identifier and one with the rest (containing letters).

The digits array doesn't need any processing.
The letters array is sorted based on the string after the identifier and, if they
compare equal, the identifier is used as a tie-braker (see C version for clear
illustration of this).

Splitting the arrays is `O(N)` while sorting the letters is `O(logM)` where `M`
is the total number of rows in the logs array that are letter based. Auxiliary
memory is `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 90.00 | 0 - 100.00 | 80 - 95.48 | 28 - 97.50 |
| Mem Usage (MB-%)| 7.6 - 36.00 | 2.1 - 44.44 | 41.2 - 83.15 | 14.3 - 87.55 |

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

## [965. Univalued Binary Tree][965]

Traverse tree and bail when we find value that doesn't match root value. Iterative
this way we can bail fast.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 93.95 | 28 - 83.02%|
| Mem Usage (MB-%)| 6 - 45.00 | 2 - 100.00 | 39 - 44.59 | 14 - 95.67|

## [976. Largest perimeter triangle.][976]

Becomes easy when you find out about the 
[triangle inequalities](https://en.wikipedia.org/wiki/Triangle_inequality) for when
a triangle with non zero (only `>` in the inequalities) can be formed.

Then, we sort our input array by size and start with maximum sides available. When the
inequality holds, we return the perimeter.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 28 - 100.00 | 4 - 100.00 | 96 - 98.61 | 172 - 98.82 |
| Mem Usage (MB-%)| 8 - 13.64 | 2.1 - 75.00 | 42.3 - 16.67 | 15.6 - 21.68 |

## [977. Squares of a Sorted Array][977]

Though a more convoluted way were we don't sort is 
possible, I don't think it's of much worth.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 100 - 96.55 | 8 - 98.46 | 116 - 84.11 | 184 - 99.84 |
| Mem Usage (MB-%)| 20.3 - 33.10 | 2.2 - 78.46 | 45.4 - 39.09 | 16.1 - 34.75 |

## [985. Sum of even numbers after queries.][985]

Main trick here is to notice that, after finding the initial total sum of all even
values in the array,  we have all information needed during each iteration to
update the sum and keep it up to date.

Whatever the case, if after updating a specific index we find that the new value is
even, we need to add it to the sum of evens. Then, if our value before updating was
even, we need to now remove it from the sum. It's like a switch of those two values.
In cases where the old/new value is odd, we can just ignore it. (since it didn't
contribute in any way to our sum). 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 148 - 100.00 | 12 - 100.00 | 112 - 99.16 | 484 - 98.95 |
| Mem Usage (MB-%)| 21.6 - 56.52 | 2.7 - 100.00 | 47.1 - 24.37 | 19 - 97.14 |

## [989. Add to array from integer.][989]

Generalized version of One Plus/Plus One problem. We start from the end of the array
and start adding the digits in `K` from the right. We need to handle two cases, as
with the case of Plus One. 

If the sum of the digit with the value in the array is
larger than nine, we add that sum `mod 10` to the array and increment `K` by one (`K`
has been reduced `/ 10` by this point).

If not (the sum is `< 9`) we just continue to the next digit in `K`.

If `K` reached `0` or we reach the start of the array, we stop. We then need to check
if `K` is zero or more values need to be added. If so, we create a temporary array
out of the digits and prepend it (reversed!) to `A`.

We then return either the new array or the original array `A`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 84 - 98.28 | 8 - 100.00 | 116 - 92.73 | 248 - 99.67 |
| Mem Usage (MB-%)| 15.1 - 100.00 | 2.2 - 100.00 | 43.3 - 86.36 | 14.9 - 93.23 |

## [999. Available Captures for Rook.][999]

Find the position of the rook and then just check it's row and column. (But from
the rooks position outwards.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 87.42 | 20  - 99.12 |
| Mem Usage (MB-%)| 5.6 - 76.47  | 2.1 - 75.00 | 37.6 - 99.34 | 14.1 - 83.77 |

## [1002. Find common characters][1002]

**TODO: See again.**

Build counts and go through values of string and find common characters.
This probably isn't the best way to go about it. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 8.33 | 4 - 45.45 | 88 - 81.43 | 36 - 97.01 |
| Mem Usage (MB-%)| 12.1 - 5.56 | 2 - 100.00 | 42.7 - 55.97 | 14 - 98.23 |

## [1008. Construct Binary Search Tree from preorder traversal.][1008]

Key insight is that left subtree is composed of values smaller than the parent 
value  and right of values larger than parent value.

During each recursive call, we pass bounds to the function indicating the values that
should be considered for left/right subtrees. Initially, these denote the full array.
Then we scan the array and find the maximum value that is smaller than our parent value
, this is the bound for the values of the left subtree. The rest denote the values
for the right subtree.

With a base case of the bounds matching, we can recursively build our tree.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 99.36 | 32 - 92.64 |
| Mem Usage (MB-%)| 8.1 - 60.78 | 2.1 - 66.67 | 40.3 - 19.23 | 14.3 - 46.43 |

## [1009. Complement of a base-10 integer.][1009]

[Same as problem.][476]

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

## [1025. Divisor Game][1025]

Apparently, optimal move is dividing by one. Return answer based on if N
is odd or even.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 87.19 | 24 - 92.61 |
| Mem Usage (MB-%)| 5.4 - 98.95 | 2 - 92.00 | 38.4 - 57.93 | 14.1 - 78.14 |

## [1030. Matrix Cells in Distance Order.][1030]

The main gist is that we create a bunch of distances in ascending order, this can
be done by taking two ranges that are based on the following comparisons:

```python
limR = max(R-r0, r0) + 1
limC = max(C-c0, c0) + 1
```

and then combining them. By taking those ranges and not a combination of the
full range from `[0-R)` and `[0-C)` we eliminate many iterations that we
*know* will fall outside of the acceptable bounds. (I.e if `R` is `50` and
`r0` is `25` it doesn't make any sense to check for distance values `> 25`.) 

Then we loop through them and try and apply them to the 
initial point. If we fall in acceptable ranges `[0, R)` and `[0, C)` we can
keep it. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 104 - 100.00 | 12 - 100.00 | 140 - 83.33 | 144 - 98.49 |
| Mem Usage (MB-%)| 23 - 12.50 | 2.7 - 75.00 | 47.5 - 40.00 | 16.2 - 41.04 |

## [1038. Binary Search Tree to greater sum tree.][1038]

This is a depth first inorder traversal. We do need to go right though. Care is
needed when traversing the left subtree; the accumulated value needs to be equal
to the value accumulated after visiting `left` and equal to the parent value if
the left subtree doesn't exist.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 92.61 | 24 - 96.32 |
| Mem Usage (MB-%)| 5.9 - 100.00 | 2 - 100.00 | 39.2 - 17.24 | 14.1 - 87.18 |

## [1046. Last stone weight.][1046]

This is the job for a heap that helps us retain sorted order after each pop/push.
`Python`, `JS` and `Rust` for which a heap or Priority Queue is available use the
heap approach.

For `C`, for which I will not write a heap now, uses the poor-mans solution of keeping
the invariant (sort-order) by continuously calling `qsort` after each loop.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 83.61 | 20 - 99.17 |
| Mem Usage (MB-%)| 5.5 - 100.00 | 2 - 83.33 | 39.2 - 75.82 | 14.2 - 29.54 |

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

## [1078. Occurences after Bigram.][1078]

Split the string and go through the words comparing. Use a while loop to skip over
chunks as needed. Similarly in `C` but with a significant ammount of boilerplate.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 98.41 | 20 - 98.86 |
| Mem Usage (MB-%)| 5.8 - 100.00 | 2 - 100.00 | 38.4 - 69.84 | 14.3 - 23.63 |

## [1103. Distribute candies to people.][1103]

Finally realized how n increases! The main trick here is to realize that
we can find the sum directly after `k` times filling the array. 

For each `i` slot of our array, we increase each and every single time we
reach the end by `n`. After `k` steps, in the slot `i` for our result
array we will have:

```python
value_for_i * k + (n + 2n + 3n + 4n + ... + kn) ==
value_for_i * k + (1 + 2 + 3 + ... + k) * i     ==
value_for_i * k + (k * ((k + 1) / 2)) * i
```

where `value_for_i` is `1, 2, 3, 4` depending on our index.

Using this (along with a small function to increase `k` until we reach close to
`candies`) we can find the next sum of the array values that is larger than
candies and stop. We then take the previous sum and fill in what's left.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 100.00 | 32 - 91.00 |
| Mem Usage (MB-%)| 5.9 - 79.17 | 2 - 83.33 | 38.3 - 88.75 | 14.1 - 97.00 |

## [1108. Defanging an IP Address][1108]

Instead of calling a replace function continuously, its 
better to just go through the string and build a new string 
with '.' replaced by '[.]'. 

At least, that's my naive first stab at it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100 | 0 - 100| 72 - 79.62|32 - 45.31|
| Mem Usage (MB-%)|5.8 - 14.33|0 - 100|38.6 - 8.88|14.1 - 99.95|

## [1122. Relative sort array.][1122]

Create a dictionary holding the order in which elements should be
sorted. For elements not contained in the second array, we
use their value + 1000 to place in correct ascending order
(most dictionaries allow indexing that doesn't contain a key
to return a default value.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 88.20 | 0 - 100.00 | 72 - 97.44 |28 - 97.20|
| Mem Usage (MB-%)| 6.2 - 51.22 | 2 - 81.25 | 38.5 - 90.28 | 14.3 - 58.12|

## [1137. N-th tribonacci number.][1137]

Not at all different from the normal fibonacci case. Iterative implementations,
we just keep track of three values during each iteration.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 97.31 | 24 - 93.78 |
| Mem Usage (MB-%)| 5.3 - 100.00 | 2 - 88.89 | 38.3 - 79.62 | 14.1 - 69.63 |

## [1160. Find Words That can be Formed by Characters.][1160]

**TODO: See again.**

Similar to problem [Find common characters][1002]. I, again, can't seem to see 
what is better than building a Counter. Maybe a reg-exp solution? Not sure, I'll
might need to check the Discussions if I can't think of anything else.

*Maybe*, seeing results for Javascript now, I was overreacting previously. 

**Pending**: `C` version (Which I'm suspecting will re-affirm initial 
suspicion).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| | 8 - 100.00 | 92 - 97.14 | 92 - 87.95 |
| Mem Usage (MB-%)| | 2.1 - 100.00 | 46.1 - 78.91 | 14.7 - 11.99 |

## [1170. Compare strings by frequency of the smallest character.][1170] 

The basic trick we can use is a cache holding, for every string in `queries` seen
so far, the ammount of strings that have a value for `f` larger than the query.

When we find another query with the same frequency we can then check the cache without
needing to go through the `words` array to count the words again.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 92.31 | 0 - 100.00 | 96 - 91.96 | 64 - 92.86 |
| Mem Usage (MB-%)| 7.7 - 46.15 | 2.5 - 33.33 | 46.2 - 25.00 | 14.9 - 10.41 |

## [1184. Distance between Bus Stops.][1184] 

This can be solved by finding the sums until the start, destination and end. The
reasoning behind this is harder without a piece of paper to draw it on, unfortunately
but I'll try.

The first difference we want to consider is that when going from start to dest in
the direction of dest. That is, if `start < dest`, we go right, if not, we go left.
This, hopefully clearly, is `|sum(start) - sum(dest)|`, we only want the intermediate
elements.

The second difference we want to find is the one going away from dest (initially, at
least). That is, if `start < dest` we go left, if not, we go right.
In this case, we have:

 -  if `start < dest`, the difference is `sum(end) + sum(start) - sum(dest)`
(we count everything from start until zero, and then we count from end until dest).

 - if `start > dest`, it is flipped: `sum(end) - sum(start) + sum(dest)` using the
   same reasoning as before.

It might now be clear that the second difference is `sum(end) - difference_one` where
difference one is the first difference.

Runtime complexity is necessarily `O(N)` since we need to build the sum until the end.
Space complexity is `O(1).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 96.00 | 40 - 94.38 |
| Mem Usage (MB-%)| 6.2 - 97.06 | 2.1 - 100.00 | 38.6 - 76.00 | 14.8 - 98.70 |

## [1185. Day of the week.][1185] 

These all use Pythons `datetime.date.weekday` algorithm for finding
the day name.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 89.82 | 24 - 93.06 |
| Mem Usage (MB-%)| 5.5 - 92.86 | 1.9 - 50.00 | 38.3 - 93.81 | 14.2 - 41.01 |

## [1189. Maximum number of balloons.][1189] 

Create a counter out of the characters in the string and then continously
reduce count of characters composing 'balloon' until we can't anymore (or
we find that a character doesn't exist in the counter).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 96.63 | 28 - 91.08 |
| Mem Usage (MB-%)| 5.9 - 27.12 | 2.1 - 75.00 | 40.6 - 44.17 | 14.4 - 13.09 |

## [1200. Minimum Absolute Difference.][1200] 

Sort the array and then go through it and add the minimum distances to our
result (minimum difference might change while iterating, in which case we
dump all previous contents of result array and start fresh.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 84 - 100.00 | 16 - 80.00 | 160 - 88.54 | 296 - 99.61 |
| Mem Usage (MB-%)| 16.3 - 88.24 | 3.1 - 100.00 | 48.7 - 100.00 | 28.1 - 33.97|

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

## [1237. Find positive integer solution for equation.][1237]

Use the fact that the function is increasing to bail early in second 
loop.

Note: Though this is wrong, output values only range in [1, 100] range. This 
basically allows us to skip many iterations by only going through that 
range. This is wrong and I should feel wrong.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 98.17 | 28 - 97.04 |
| Mem Usage (MB-%)| 6 - 96.15 | 2 - 100.00 | 38.8 - 71.34 | 14 - 83.57|

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

## [1260. Shift 2d grid.][1260]

By taking the value of `k mod cols` we can easily find how many rows/columns
we need to skip and bail early on certain cases.

With Python and Rust, we can just utilize a deque's `rotate` method after
flattening the array.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 60 - 100.00 | 8 - 100.00 | 104 - 84.38 | 144 - 97.29 |
| Mem Usage (MB-%)| 14.3 - 89.19 | 2.3 - 33.33 | 46.1 - 10.42 | 14.4 - 81.01 |

## [1266. Minimum Time Visiting All Points][1266]

Move as much as you can diagonally and then move horizontically or 
vertically according to the case. `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 98.64 | 0 - 100.00 | 76 - 89.95 | 52 - 96.32 |
| Mem Usage (MB-%)| 6.4 - 13.61 | 2.1 - 100.00 | 40 - 5.60 | 14.1 - 100.00|

## [1275. Find winner on a tic tac toe game.][1275]

Mostly straighforward, fill a board up with the value and check if we have a
winner.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 95.18 | 28 - 90.26 |
| Mem Usage (MB-%)| 5.6 - 75.00 | 2 - 100.00 | 38.6 - 84.94 | 14.2 - 90.41 |

## [1281. Subtract the Product and Sum of Digits of an Integer][1281] 

Continuously reduce `n` by `// 10` and add/multiply its modulo 
`10` (the rightmost digit).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00  | 0 - 100.00 | 72 - 86.84 | 20 - 98.44 |
| Mem Usage (MB-%)| 5.7 - 14.29 | 2 - 100.00 | 38.5 - 20.85 | 14.1 - 99.96 |

## [1282. Group the people given the group size they belong to.][1282] 

Use a map to hold the groups as we build them. Once a group is filled up,
add it to the result and reset the group in the map.

Don't forget to add any pending groups after iterating through `groupSizes`.

Runtime complexity is `O(N)` where `N` is the size of `groupSizes`, space 
complexity is, I believe, similarly `O(N)`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 24 - 100.00 | 0 - 100.00 | 84 - 100.00 | 72 - 88.83 |
| Mem Usage (MB-%)| 9.7 - 80.00 | 2.1 - 72.00 | 43.9 - 84.29 | 14.2 - 98.32 |

## [1287. Element appearing more than 25% in sorted array.][1287]

Calculate the threshold 25% corresponds to and go through the array counting lengths
of equal items. If at any point during our counting we exceed the threshold, we return
immediately.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 100.00 | 0 - 100.00 | 76 - 92.64 | 68 - 99.84 |
| Mem Usage (MB-%)| 6.4 - 65.31 | 2.1 - 100.00 | 39.5 - 82.68 | 15.42 - 35.05 |

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

## [1302. Deepest leaves sum.][1302]

Traverse tree keeping track of current depth, max depth and the sum. If we encounter
a leaf we check its depth. 

If it's larger than the current depth, reset the sum to the
leaf value and keep track of new maximum depth. Else, add leaf value to sum.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 97.01 | 8 - 100.00 | 96 - 97.42 | 84 - 94.32 |
| Mem Usage (MB-%)| 15.8 - 83.58 | 3.1 - 100.00 | 48.7 - 71.94 | 17.8 - 70.79 |

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
| Runtime (ms-%)| 32 - 81.07 | 4 - 100.00 | 92 - 85.55 | 64 - 89.35|
| Mem Usage (MB-%)| 10.4 | 2.1 - 100.00 | 42.3 - 5.85 | 14.5 - 13.10|

## [1315. Sum of nodes with even valued grandparent.][1315]

Traverse the tree normally, hold around the value of the parent of the node
currently traversing on and if that node's children exist and the parent value
is even, add them to the sum. Recurse.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 16 - 93.48 | 4 - 100.00 | 96 - 99.00 | 92 - 94.27 |
| Mem Usage (MB-%)| 15.7 - 97.83 | 3 - 100.00 | 48.8 - 62.50 | 17.7 - 93.81 |

## [1317. Convert integer to the sum of the two non-zero integers.][1317]

Start from the largest, smallest pair possible `(n-1, 1)` and either increase the 
smallest if their sum is smaller than `n` or decrease largest if sum larger than `n`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 92.63 | 24 - 94.60 |
| Mem Usage (MB-%)| 5.5 - 50.00 | 2 - 100.00 | 38.4 - 96.84 | 14.2 - 66.61 |

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

## [1329. Sort the matrix diagonally.][1329]

The trickiest part is finding how to nicely traverse the diagonals of the matrix.
After doing that, we can collect each diagonal in a separate vector, sort it and
then place it back into the matrix.

I've implemented diagonal traversing via while loops. Starting from the leftmost
bottom position, we decrease the row index and (after the row index reaches zero)
icrease the column index. The inner while loops simply traverse the diagonal (each
index is increased by one until we reach the end for either one).

Can't really guess much on the complexity. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 91.92 | 0 - 100.00 | 84 - 99.46 | 76 - 96.70 |
| Mem Usage (MB-%)| 8.5 - 90.91 | 2.2 - 90.38 | 41 - 92.90 | 14.6 - 52.14 |

## [1332. Remove palindromic subsequences.][1332]

**Big** note to self: *Pay attention to the description*. It asks for
**subsequences**, not **substrings**.

Number of removals can be found quickly since we have subsequences:
 - Empty string => 0 ops.
 - A full palindrome => 1 op.
 - Else: create set, it's size will be number of ops. (i.e first op remove all a's
   and on second op remove all b's.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 96.10 | 20 - 98.28 |
| Mem Usage (MB-%)| 5.5 - 100.00 | 2 - 100.00 | 39.8 - 6.49 | 14 - 95.81 |

## [1337. The k-weakest rows in a matrix][1337]

Sum each row and enumerate it, sort and then grab `k` first.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 100.00 | 0 - 100.00 | 76 - 95.42 | 96 - 98.53 |
| Mem Usage (MB-%)| 6.8 - 55.56 | 2.1 - 50.00 | 40 - 81.67 | 14.5 - 57.69 |

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

## [1356. Sort integers by the number of 1 bits][1356]

Sort initially to get them in correct order. Then sort by count. The second sort 
*must* be stable. In `C` this is done by creating a new array holding required 
information while in `Javascript` we use `lodash`. `Rust` and `Python` offer 
stable sorts.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 89.87 | 0 - 100.00 | 96 - 82.93 | 56 - 97.11 |
| Mem Usage (MB-%)| 8.3 - 16.46 | 2 - 92.59 | 42.3 - 40.85 | 14.1 - 92.41 |

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

## [1379. Find a corresponding node of a binary tree in a clone of that tree.][1379]

Just traverse the cloned tree looking for a node with a value equal to the value of
the target node.

Note on Follow up: For this case, we can simply build a path in the original tree
while looking for target and then follow that path in cloned to find its reference.

Note: C and Rust versions aren't available.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| N/A | N/A | 296 - 94.16 | 592 - 97.39 |
| Mem Usage (MB-%)| N/A | N/A | 59.4 - 70.94 | 23.9 - 96.23 |

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

## [1385. Find the distance between two arrays.][1385]

Go through fist array and for each value make top and bottom bounds for 
values of second array to satisfy in order for `| arr1[i] - arr2[j] <= d |`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 85.71 | 0 - 100.00 | 88 - 87.00 | 76 - 89.36 |
| Mem Usage (MB-%)| 6.1 - 64.29 | 2.1 - 100.00 | 39.2 - 99.00 | 14.1 - 98.84 |

## [1389. Create target array in the given order.][1389]

O(N^2) is actually best option here, no secret fancy solutions. Continuously
insert in target position.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 91.95 | 28 - 91.36 |
| Mem Usage (MB-%)| 5.9 - 94.44 | 2.1 - 27.78 | 40.2 - 9.52 | 14 - 88.59 |

## [1394. Find lucky integer in Array.][1394]

Build a counter and return the largest pair for which `key == value`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 97.56 | 0 - 100.00 | 68 - 100.00 | 48 - 96.34 |
| Mem Usage (MB-%)| 6.4 - 31.71 | 2 - 33.33 | 40 - 50.62 | 14.1 - 97.03 |

## [1399. Count largest group.][1399]

Build a Counter, sort it and find the length of the group with the largest
values.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 55.56 | 4 - 100.00 | 84 - 93.48 | 80 - 90.56 |
| Mem Usage (MB-%)| 6 - 11.11 | 2 - 100.00 | 40.9 - 55.43 | 14.1 - 86.40 |

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

## [1408 String matching in an Arrat,][1408]

Sort array from smallest string to largest. Go through it comparing smaller with
larger strings. Bail when you find a match.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 76 - 91.22 | 28 - 97.24 |
| Mem Usage (MB-%)| 6 - 100.00 | 2 - 100.00 | 38.2 - 99.62 | 14.2 - 67.69 |

## [1409. Queries on a permutation with key.][1409]

Don't think there's much of a trick here, we go along with what the problem describes,
finding the index and then swapping the position of the value queried. 

Runtime complexity should be O(nm) where n is the size of the queries. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 8 - 73.33 | 0 - 100.00 | 76 - 99.25 | 48 - 93.41 |
| Mem Usage (MB-%)| 6.1 - 98.33 | 2 - 81.82 | 40.1 - 67.91 | 14.4 - 84.89 |

## [1413. Minimum Value to get positive step by step sum.][1413]

Start with an initial minimum guess of `1` and go through the values of the
array. When we fall under `1` after summing values, we adjust the minimum value
in order to not be under `1`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 82.35 | 24 - 96.60 |
| Mem Usage (MB-%)| 5.8 - 100.00 | 2 - 100.00 | 37.9 - 97.39 | 14 - 96.50|

## [1417. Reformat the string.][1417]

Build a list of characters and numbers. If their lengths don't differ by a maximum
of `1`, we cannot reformat the string as needed. If they do, we just interleave
them (taking care on which we interleave first/second etc).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 98.72 | 28 - 100.00 |
| Mem Usage (MB-%)| 6.1 - 42.31 | 2.1 - 60.00 | 42.5 - 89.10 | 14.1 - 86.07 |

## [1422. Maximum Score After splitting a string.][1422]

Start from position 1 and count all ones to the right. Add one to the count if
position `0` has the character `'0'`. 

Go through the strings with the count as the current max. If a `'1'` is seen, we
subtract one from the count, if `'0'` is seen, we add one (this is because left
hand string counts zeroes and right hand string counts ones. 

After each iteration we check if the new count is larger than the max, if so, keep 
it. After iterating through the string, we will have kept the largest value for max.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 97.73 | 28 - 92.27 |
| Mem Usage (MB-%)| 5.6 - 94.74 | 2 - 100.00 | 38.7 - 86.36 | 14 - 91.17 |

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

## [1437. Check if all 1s are at least k places away.][1437]

Does an `O(N)` scan of the array. Looks for ones and counts the difference between consecutive ones,
pretty straightforward.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 60 - 88.73 | 8 - 66.67 | 84 - 91.49 | 516 - 100.00 |
| Mem Usage (MB-%)| 11.1 - 80.23 | 2.5 - 100.00 | 46.5 - 73.05 | 16.7 - 96.80 |

## [1441. Build an Array with stack operations][1441]

Go through values of the target and build the operations. We build the 
sequence of "Push" and "Pop"s for missing elements by finding the difference
of the current value of the target with its previous value.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 92.27 | 24 - 96.01 |
| Mem Usage (MB-%)| 6.2 - 70.00 | 2 - 100.00 | 38.5 - 82.73 | 14.1 - 84.41 |

## [1446. Consecutive Characters,][1446]

Go through characters and count.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 96.99 | 24 - 99.90 |
| Mem Usage (MB-%)| 5.8 - 98.72 | 2 - 98.78 | 39.3 - 64.05 | 14.3 - 12.21 |

## [1450. Number of Students Doing Homework at a Given Time][1450]

Go through first vector (start times) and for every start time 
that is smaller equal to the queryTime, check the second vector 
(end times) to see if we fall in range.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 86.58 | 28 - 97.73 |
| Mem Usage (MB-%)| 5.8 - 80.17 | 2.2 - 100.00 | 38.3 - 29.39 | 14.2 - 100.00|

## [1455. Check if a word occurs as a prefix of any word in a sentence.][1455]

Straight-forward approach. Split and use string functions for `Rust`, `Python`
and `Javascript`. Compare characters in `C`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 95.51 | 20 - 98.95 |
| Mem Usage (MB-%)| 5.5 - 100.00 | 2 - 100.00 | 38.4 - 42.31 | 14.1 - 41.63|

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

## [1476. Subrectangle Queries.][1476]

Can't see a non-O(N\*M) way to implement `update_subrectangle`, so, we brute force
it there. `get_value` is an easy `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 32 - 100.00 | 8 - 100.00 | 100 - 97.37 | 156 - 86.78 |
| Mem Usage (MB-%)| 10.2 - 85.71 | 3.1 - 93.75 | 45.2 - 11.18 | 15.8 - 99.72 |

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

## [1491. Average Salary excluding the min and max][1491]

Sort and then just sum and divide.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 89.32 | 24 - 94.65 |
| Mem Usage (MB-%)| 5.8 - 70.69 | 1.9 - 75.00 | 38.3 - 83.59 | 14.1 - 80.75  |

## [1496. Path Crossing.][1496]

Hold previous points visited in a set, after moving to a new point, check if it is
contained in the set.

`C` case: Quite frankly, not up for create a uthash structure with a compound key
today.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| N/A | 0 - 100.00 | 72 - 94.74 | 20 - 98.76 |
| Mem Usage (MB-%)| N/A | 2 - 100.00 | 38.5 - 74.34 | 14.4 - 60.40 |

## [1502. Can make arithmetic progression from sequence.][1502]

Sort the array and find the step by subtracting first two 
elements. Go through the array and check that step is 
present through-out.

Worse-case `O(NlogN)` due to sorting.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 89.04 | 0 - 100.00 | 76 - 88.50 | 32 - 95.03 |
| Mem Usage (MB-%)| 6.1 - 76.71 | 1.9 - 100.00 | 38.7 - 86.58 | 14.1 - 89.94 |

## [1507. Reformat date.][1507]

Split, and re-build. The main issue is taking care the starting `'0'` character needs
to be added on days `< 9` and months `< 9`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 91.22 | 24 - 94.80 |
| Mem Usage (MB-%)| 5.5 - 88.89 | 2 - 50.00 | 38.5 - 72.97 | 14.2 - 61.80 |

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

## [1518. Water Bottles.][1518]

Continuously reduce `num_bottles` by dividing it by `num_exchange`, the quotentis added to the total number of drinks we can consume and `num_bottles` is
reassigned to `quotent + remainder` and the same steps are taken again until
the quotent becomes zero.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 89.06 | 24 - 93.26 |
| Mem Usage (MB-%)| 5.4 - 100.00 | 1.9 - 95.24 | 38.7 - 16.67 | 13.9 - 99.70 |

## [1523. Count Odd numbers in an interval range.][1523]

Can find odds by dividing the range by 2 and then adding one if at least one
of the bounds was odd. (Note: yes, you got this to work, but why +1?).

Space/time complexity is `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 95.72 | 24 - 94.69|
| Mem Usage (MB-%)| 5.3 - 100.00 | 2 - 75.00 | 38.3 - 70.59 | 14.2 - 42.51 |

## [1528. Shuffle String][1528]

Create a new array and fill it in, basically. 
`O(N)` time *and* `O(N)` space. I'm sure there should be a 
way for inplace swaps.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 88.85 | 0 - 100.00 | 76 - 97.38 | 56 - 65.00|
| Mem Usage (MB-%)| 6.2 - 100.00 | 2 - 100.00 | 40.3 - 10.15 |14.1 - 99.95|

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

## [1539. Kth Missing Positive Number.][1539]

Go through array with a counter initialized to 1. If we encounter a value that
is equal to our counter (which denotes the strictly increasing sequence), we just
increment the counter, if we encounter a value larger than the counter, we adjust
`k` to account for the total gap between our counter and the value, and set our
counter to denote the next value after the value just encountered.

Complexity is `O(N)`, we perform constant operations for each element of the array.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 90.52 | 0 - 100.00 | 72 - 96.39 | 36 - 99.78 |
| Mem Usage (MB-%)| 6.1 - 97.71 | 2 - 96.67 | 38.1 - 99.78 | 14.3 - 69.55 |

## [1544. Make the string great.][1544]

We go through the string checking pairs. If a pair is bad (found by checking the
difference of their code point) we skip it, if not, we keep the first element
of the pair.

When we encounter a bad pair we need to take care to remove any bad pairs that
are created by the next character in the string and the last element we kept.
We therefore check if a bad pair exists between those two characters and, if not,
we simply break, if yes, we skip the character in the skip and remove the last
kept character. We continue this operation until the pair isn't bad.

Space and time complexity is O(N). Even while removing bad pairs, we skip characters
in the string.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 84 - 93.68 | 28 - 97.16 |
| Mem Usage (MB-%)| 5.8 - 44.44 | 2 - 83.33 | 41 - 38.42 | 14.1 - 77.79 |

## [1550. Three Consecutive odds.][1550]

Not many options here, go through array and count odds. Bail when you find them.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 97.43 | 40 - 89.59 |
| Mem Usage (MB-%)| 5.9 - 60.71 | 1.9 - 100.00 | 38.7 - 49.52 | 14.3 - 65.73 |

## [1556. Thousand Separator.][1556]

Make an array to hold result and a string out of the number (or, in `C`'s case,
simply a string). Then go through it backwards and insert separator
`'.'` as indicated by a counter that keeps track of numbers added.

`C` version is probably the more interesting.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 92.14 | 20 - 99.24 |
| Mem Usage (MB-%)| 5.5 - 87.50 | 2 - 88.89 | 38.5 - 71.43 | 14.1 - 86.04 |

## [1560. Most visited sector in a circular track.][1560]

The idea here is that we don't need to count everything. There may be many cycles
through the track which don't give us any information about which of the sections
was the most visited.

Instead, we need to look at the beginning and the end of the array to see where
we start and end.

If we start at 1 or end at `N`, all sections have been visited the same number
of times.

If start `!= 1` we start from an odd section. We keep track of these odd sections
(until `N` or until the array is exhausted) since they contribute `+1` to the
sections.

If end `!=N`, we end at an odd section, similarly to start, we keep track of
all sections from `1` until the end since they also contribute `+1` to the 
number of sections.

Joining these two together, we can find our final result.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 80 - 97.12 | 36 - 96.11 |
| Mem Usage (MB-%)| 6.2 - 100.00 | 2.1 - 100.00 | 40.9 - 27.88 | 14.1 - 94.91 |

## [1572. Matrix Diagonal Sum][1572]

Go through the array and concurrently sum both diagonals. Remove 
the middle element (to handle double counting) if the matrix has 
an odd length. `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 12 - 100.00 | 0 - 100.00 | 68 - 97.94 | 96 - 99.21 |
| Mem Usage (MB-%)| 6.6 | 2.1 - 100.00 | 40.6 - 25.18 | 14.2 - 100.00 |

## [1582. Special Positions in a Binary Matrix.][1582]

Use a set to hold already occupied previously seen columns. Then iterate
through the rows looking for candidates.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 20 - 100.00 | 0 - 100.00 | 68 - 100.00 | 148 - 97.80 |
| Mem Usage (MB-%)| 7.5 - 5.26 | 2.1 - 83.33 | 40.4 - 91.67 | 14.4 - 92.64 |

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

## [1598. Crawler Log Folder][1598]

Pretty straight-forward implementation of problem statement.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 90.48 | 0 - 100.00 | 76 - 91.88 | 40 - 90.93 |
| Mem Usage (MB-%)| 6.4 - 85.71 | 2.1 - 90.48 | 39 - 60.00 | 14.2 - 92.01 |

## [1603. Design Parking System][1603]

Mostly an OOP problem really.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 56 - 89.80 | 16 - 100.00 | 148 - 81.63 | 136 - 75.59 |
| Mem Usage (MB-%)| 20.8 - 100.00 | 2.4 - 45.00 | 46 - 26.12 | 14.6 - 74.11 |

## [1608. Special Array with X elements greater than or equal to X.][1608]

For each candidate special number (`1..array.length() + 1`) go through
the elements of the array and see if we have a matching number of elements
`>=` to it.

We can limit the iterations/comparisons made by breaking early when:

 - matches are `>` than the special number.
 - the remaining elements in the array aren't enough to reach the special number.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 97.50 | 36 - 74.54 |
| Mem Usage (MB-%)| 5.8 - 88.24 | 2 - 85.71 | 38.8 - 53.33 | 14 - 97.45 |

## [1614. Maximum Nesting Depth of the Parentheses][1614]

Traverse string while keeping count of depth. Runtime `O(n)` and 
space `O(1)`. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 96.16 | 24 - 95.18 |
| Mem Usage (MB-%)| 5.7 - 85.33 | 2.2 - 100.00 | 39.2 - 76.73 | 14.1 - 100.00 |

## [1619. Mean of Array after removing some elements.][1619]

Sort, slice and return mean.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 76 - 97.64 | 48 - 97.10 |
| Mem Usage (MB-%)| 6.1 - 91.67 | 2.1 - 85.19 | 40.3 - 29.06 | 14.1 - 95.31 |

## [1624. Largest substring between two equal characters.][1624]

Create a map holding min and max value for a given character in `s`. Then, go
through the map values and find the max distance.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 91.62 | 24 - 95.74 |
| Mem Usage (MB-%)| 6 - 10.36 | 2 - 100.00 | 39.5 - 22.16 | 14.3 - 10.05 |

## [1629. Slowest Key.][1629]

Find and keep all indices that have max `releaseTimes[i] - releaseTimes[i-1]` in a list.
Then go through that array and find the max character to return.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 92.16 | 0 - 100.00 | 76 - 92.58 | 48 - 96.71 |
| Mem Usage (MB-%)| 6.2 - 96.08 | 2.1 - 72.22 | 39.9 - 54.42 | 14.6 - 22.01 |

## [1636. Sort Array by Increasing Frequency.][1636]

Need to build counts and then perform a two-way sort. First we sort by 
value (stability isn't a concern) and then by frequency. 

Stability when sorting by frequency is a concern because we want to reverse 
the order of elements with the same frequency. To do this we need to
add a tie-braker (the position after the first sort) to use when sorting
again by position. 

Since the second sort results in the array being reversed, we need to add
elements from the end towards the front.

**TODO: JS sort happens to be implemented as stable (this isn't guaranteed
though, need to use same tie-braking mechanism as C there.**

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 84 - 98.23 | 40 - 98.75 |
| Mem Usage (MB-%)| 7.3 - 28.00 | 2 - 71.43 | 41.8 - 23.89 | 13.9 - 97.38 |

## [1637. Widest vertical area between two points containing no points.][1637]

We don't need the `y` axis to find greatest vertical distance, we need the `x` axis
in sorted order. We can then find the max difference between two adjacent points.

Note: Though it doesn't help much (at least not in any besides Python), we can also
notice that we need distinct `x` values. We can use a set to filter duplicate x values
while building the array holding them.

This approach is only used in Python, in others, it didn't result in any benefit.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 200 - 92.00 | 24 - 90.00 | 172 - 98.66 | 800 - 95.57 |
| Mem Usage (MB-%)| 28.6 - 64.00 | 9.6 - 96.00 | 62.6 - 32.89 | 55.3 - 19.34 |

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

## [1646. Get maximum in generated array.][1646]

Initially thought there was a trick in order to immediately find the value in the
array for a given `n`. According to the results, I doubt that now. 

Build the array and while building hold onto the max seen.

Space/Time complexity is `O(n)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 93.76 | 24 - 96.72 |
| Mem Usage (MB-%)| 5.9 - 11.17 | 2 - 95.00 | 38.9 - 10.99 | 14 - 99.22 |

## [1652. Defuse the bomb.][1652]

Use modular arithmetic (dividing by array lenght) to add correct elements.
In Python, use `deque` to rotate around instead.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 97.14 | 0 - 100.00 | 72 - 98.31 | 36 - 84.77 |
| Mem Usage (MB-%)| 6.1 - 85.71 | 2 - 100.00 | 38.6 - 84.46 | 14.1 - 89.93 |

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

## [1672. Richest customer wealth.][1672]

Max of the sum of the entries.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0- 100.00 | 72 - 92.65 | 48 - 95.26 |
| Mem Usage (MB-%)| 6.1 - 94.74 | 2 - 66.67 | 38.4 - 83.19 | 14.1 - 86.41 |

## [1678. Goal Parser Interpretation.][1678]

Go through the string via index which we increase based on the chunk we've seen.
For C, we can alter the input string instead of creating a new one.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 100.00 | 24 - 98.37 |
| Mem Usage (MB-%)| 5.8 - 70.00 | 2 - 100.00 | 38.5 - 26.43 | 14.1 - 72.89 |

## [1684. Count the number of consistent strings.][1684]

Create a set of the allowed characters and go through array checking if each
character of each word is inside the set.

Feel (mainly due to `C` timings) that there must be something I'm not taking
advantage of here.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 48 - 69.33 | 12 - 97.06 | 108 - 93.83 | 224 - 85.91 |
| Mem Usage (MB-%)| 12.3 - 36.00 | 2.7 - 17.65 | 47.8 - 80.74 | 16 - 95.99 |

## [1688. Count of matches in tournament.][1688]

Add the divmod of `n` by `2` continuously until `n` reaches `1` (last match). 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 85.89 | 16 - 99.96 |
| Mem Usage (MB-%)| 5.5 - 78.38 | 2 - 91.18 | 38.5 - 76.57 | 14.2 - 45.53 |

## [1689. Partition into minimum number of deci-binary numbers.][1689]

Idea is simple after you view digits as points in a vector (at least,
that's how I visualized it). 
    
We can continuously reduce by one each position until it reaches zero,
no matter what the number is, at each step every single one of its positions
will be reduced by one. As an example with `n = "93240032"`:
  
We can now create a deci-binary number that has a 1 for each position in n > 0
and a zero if the position in n is 0:

```    
   "93240032"
 - "11110011"  <-- deci-binary
 = "82130021"
```
        
This process can continue untill all the digits of the number are equal to zero.
This leads to the minimal set of numbers since it is the minimal set of ones to
reach the max digit (we can only increase by one, there's no faster way to reach
a given digit.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 4 - 100.00 | 0 - 100.00 | 88 - 91.16 | 44 - 96.88 |
| Mem Usage (MB-%)| 7.8 - 83.33 | 2.1 - 59.46 | 42.8 - 95.98 | 14.6 - 97.73 |

## [1694. Reformat phone numbers.][1694]

For `Python` and `Rust`: First remove all `'-'` and `' '` characters from the
string and then iterate through chunks which we save to a result array. Then
we return the array joined on `'-'`.

For `C` and `JavaScript`: Go through character by character carefully collecting
numbers and placing the `'-'` character where needed, see comments in source
files.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 91.67 | 28 - 93.41 |
| Mem Usage (MB-%)| 5.7 - 83.33 | 2 - 100.00 | 40.1 - 8.33 | 14.2 - 94.48 |

## [1700. Number of students unable to eat lunch.][1700]

Use a (de)Queue to efficiently pop from the left and rotate. With it, the
implementation is straight-forward.

For `C`: When I (finally) build a little Queue object.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| N/A | 0 - 100.00 | 80 - 100.00 | 28 - 100.00 |
| Mem Usage (MB-%)| N/A | 2.3 - 100.00 | 40 - 100.00 | 14.2 - 100.00 |

## [1704. Determine if string halves are alike.][1704]

Build a count of vowels until the midpoint of the string. Then go through the string
from the midpoint until the end and reduce the count. If at any point it becomes
negative, we're done, else, return result of `count == 0`.

A set is mostly used to hold the vowels, except for `C` in which we keep them in an
array and iterate through it.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 68 - 99.53 | 24 - 99.54 |
| Mem Usage (MB-%)| 6 - 41.38 | 2 - 100.00 | 38.9 - 81.04 | 14.1 - 89.35 |

## [1710. Maximum Units on a Truck.][1710]

Greedy solution, we continuously select boxes with maximum units until no more boxes
can fit inside the truck.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 28 - 100.00 | 4 - 100.00 | 96 - 100.00 | 144 - 100.00 |
| Mem Usage (MB-%)| 7.7 - 100.00 | 2.2 - 100.00 | 42.1 - 100.00 | 14.9 - 100.00 |

## [1716. Calculate Money in Leetcode Bank.][1716]

Can go through `n` in weeks and then add left-over days. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 96.12 | 24 - 98.92 |
| Mem Usage (MB-%)| 5.5 - 84.44 | 2 - 100.00 | 38.3 - 61.79 | 14.2 - 71.27 |

## [1720. Decode xored array.][1720]

Based on xor-swap algorithm. Can find the original value used to get the xor'ed
values simply by xor-ing the new values.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 100 - 100.00 | 8 - 100.00 | 112 - 94.12 | 216 - 98.72 |
| Mem Usage (MB-%)| 20.7 - 62.50 | 2.2 - 100.00 | 45 - 65.55 | 15.7 - 98.32 |

## [1725. Number of Rectangles that can form the largest square.][1725]

Note that the largest square has a side that is equal to the maximum between the minimum
of the pairs inside the array.

To find the count, we hold a max value and count value initialized to zero. For each
pair inside the array, if the minimum of the pair is equal to max, we just increase
the count (signifying that we've found another square with `side == max`).

If the minimum of the pair is larger than the current max we've currently counted,
we need to reset our counter to 1 (to count the current square with side `> max`) 
and set `max` to the new maximum. 

At the end, we have the count of the squares with sides equal to the maximum value
possible.

Runtime is `O(N)` since we perform constant operations for each iteration through the
array. Space complexity is `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 36 - 100.00 | 4 - 100.00 | 92 - 100.00 | 172 - 100.00 |
| Mem Usage (MB-%)| 8 - 100.00 | 2.2 - 100.00 | 41.5 - 100.00 | 14.8 - 100.00 |

## [1732. Find the highest altitude.][1732]

Initialize max and height to zero. Go through gains and add to height, if height is
larger than max, set max to height.

Return max.

Runtime O(N), space O(1).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 64 - 100.00 | 28 - 100.00 |
| Mem Usage (MB-%)| 6 - 100.00 | 2.1 - 100.00 | 38.6 - 100.00 | 14.1 - 100.00 |

## [1742. Maximum Number of Balls in a box][1742]

Go through range counting indices. Best trick is to not compute the indices for
all numbers. Rather take advantage of fact that for a given number, we can compute
the base index of its multiple of ten and then add to that the next nine values
from [0-9].

For example, given ranges `[39, 73]`, we can skip computing indices for all numbers
and instead compute them for `[30, 40, 50, 60, 70]`, i.e multiples of ten.
The remaining numbers can be added by adding the 
range from `[0, 9]` to that base number, special cases apply for the initial multiple
of ten and the final one (because we have remainders). Coarsely, what we compute is:

```python
# 3 is quotent 30 // 10
sum_digits(3) -> 3
# 9 is the remainder of 39 % 10.
add_to_counter_with_base(3, 9, 10)
# 4 is quotent of 40 // 10
sum_digits(4) -> 4
# add full range from 0-9.
add_to_counter_with_base(4, 0, 10)
# 5 is quotent of 50 // 10
# add full range from 0-9
add_to_counter_with_base(5, 0, 10)
# similarly for 60
# seven is quotent of 70 // 10.
sum_digits(7) -> 7
# 3 is remainder of 73 % 10
add_to_counter_with_base(7, 0, 3)
```

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 92 - 99.58 | 156 - 99.80 |
| Mem Usage (MB-%)| 5.6 - 58.82 | 2 - 59.09 | 38.6 - 90.72 | 14.4 - 33.47 |

## [1748. Sum of unique elements][1748]

Rust, Javascript, Python all use sets in order to keep track of seen numbers and
unique numbers. All could use `C`s alternative of using a bit-array in order to
keep track of these and reduce memory requirements. All in all, all run in `O(N)`
and while `C`s memory complexity should also be `O(N)` it definitely is a much
smaller one.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 84 - 100.00 | 32 - 100.00 |
| Mem Usage (MB-%)| 5.8 - 100 | 2.1 - 100.00 | 39.1 - 100.00 | 14.3 - 100.00 |

## [1752. Check if array is sorted and rotated.][1752]

Keep track of starting value in nums.

Iterate through `nums` checking if the invariant (`nums[i-1] < nums[i]`) holds. If we
reach the end, we have a sorted array with no rotations.

If we don't reach the end (i.e `nums[i-1] > nums[i]`), we've reached a possible point
where the array was rotated. In order for the array pre-rotation to be valid two
things need to hold:

 - same invariant (i.e `nums[i-1] < nums[i]`)
 - all values must be `<= start`.

If the first condition doesn't hold, the pre-rotated array wasn't sorted in non-decreasing
order.
If the second condition doesn't hold, the pre-rotated array wasn't sorted since `start`
is smaller than an element that is found to its left. 

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 100.00 | 24 - 100.00 |
| Mem Usage (MB-%)| 6.1 - 100.00 | 2.1 - 100.00 | 38.4 - 100.00 | 14 - 100.00 |

## [1768. Merge Strings Alternatively.][1768]

Zip strings and build until length of smallest. Then push what's left from the largest
to the result.

O(N) where N is size of largest string.

| Stats/Lang  | C  | Rust  | JS  | Py | 
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 60 - 99.88 | 24 - 95.91 |
| Mem Usage (MB-%)| 5.7 - 100.00 | 2.1 - 60.42 | 39.2 - 20.05 | 14.1 - 81.02 |

## [1773. Count items matching a rule.][1773]

Find index which `ruleKey` corresponds to and then count items matching the `ruleValue`. This results in `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 60 - 100.00 | 12 - 100.00 | 84 - 100.00 | 240 - 100.00 |
| Mem Usage (MB-%)| 13.6 - 100.00 | 4.4 - 100.00 | 42.4 - 100.00 | 20.7 - 50.00 |

## [1779. Find nearest point that has the same x or y coordinate.][1779]

`O(N)`, the main insight (i guess) is the fact that you don't really need to calculate one part of the manhattan distance
since you know it will be zero (`xi == x <=> xi - x == 0`, similarly for `yi, y`).

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 140 - 98.46 | 16 - 97.73 | 104 - 94.58 | 688 - 97.23 |
| Mem Usage (MB-%)| 16.1 - 61.54 | 2.8 - 100.00 | 46.3 - 88.14 | 19.5 - 13.48 |

## [1790. Check if one string swap can make strings equal.][1790]

Check each of the characters in both string to verify that they differ in less than 2 positions (`O(N)`); if
there's more than two mismatches in position, we'd need more than two swaps.

After doing that we need to check that the possible switch involves the same characters. This could probably be done
by keeping track of the indices of the mismatch but I've done it by using a set equality between strings (`O(N)`).

Overall, runtime complexity is `O(N)` while space complexity is `O(1)` (because we only deal with 26 different characters
as input, the size of the sets is always bound by that.)

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 93.86 | 24 - 94.90 |
| Mem Usage (MB-%)| 5.4 - 93.26 | 2.1 - 55.17 | 40.2 - 20.55 | 14.3 - 20.60 |

## [1800. Maximum Ascending Subarray sum.][1800]

Keep track of current sum and the max sum we've found so far. When we detect the end of a sequence, we just update the
max sum if the current sum is larger. Care is needed to handle last element in the list of numbers. Overall, `O(N)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 90.78 | 24 - 99.12 |
| Mem Usage (MB-%)| 5.8 - 75.00 | 2 - 96.15 | 38.5 - 55.32 | 14.2 - 75.50 |

## [1812. Truncate sentence.][1812]

Observe that if we map cols from `[a-h]` to `[1-8]` we have a nice property: cells for which
the parity is the same are black while those for which parity is different are white. Using this,
solution is `O(1)`.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 95.14 | 24 - 96.62 |
| Mem Usage (MB-%)| 5.4 - 75.00 | 1.9 - 96.55 | 38.4 - 78.42 | 14.1 - 90.58 |

## [1816. Truncate sentence.][1816]

Simple `O(N)`, enumerate through chars counting spaces, when k reaches zero, return the index for that
iteration. Return string splitted/truncated on that index.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 72 - 94.14 | 20 - 99.16 |
| Mem Usage (MB-%)| 5.9 - 73.68 | 2 - 67.50 | 39.1 - 6.25 | 14 - 99.43 |

## [1822. Sing of the product of the array.][1822]

No need to do the actual multiplications. Simply toggle a variable the amount of times a negative number is seen. If
zero is encountered, zero is unconditionally returned. `O(N)` since we examine all values.

| Stats/Lang  | C  | Rust  | JS  | Py |
|:-----------:|:--:|:-----:|:---:|:--:|
| Runtime (ms-%)| 0 - 100.00 | 0 - 100.00 | 76 - 92.86 | 56 - 93.29 |
| Mem Usage (MB-%)| 6.3 - 35.90 | 2.1 - 53.33 | 39.8 - 47.25 | 14.4 - 70.94 | 

[1]: https://leetcode.com/problems/two-sum/
[7]: https://leetcode.com/problems/reverse-integer/
[9]: https://leetcode.com/problems/remove-element/
[13]: https://leetcode.com/problems/roman-to-integer/
[21]: https://leetcode.com/problems/merge-two-sorted-lists
[35]: https://leetcode.com/problems/search-insert-position/
[64]: https://leetcode.com/problems/summary-ranges
[66]: https://leetcode.com/problems/plus-one/
[88]: https://leetcode.com/problems/merge-sorted-array/
[100]: https://leetcode.com/problems/same-tree/
[102]: https://leetcode.com/problems/binary-tree-level-order-traversal/
[104]: https://leetcode.com/problems/maximum-depth-of-binary-tree/
[107]: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
[108]: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
[111]: https://leetcode.com/problems/minimum-depth-of-binary-tree/
[118]: https://leetcode.com/problems/pascals-triangle/
[119]: https://leetcode.com/problems/pascals-triangle-ii/
[122]: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
[136]: https://leetcode.com/problems/single-number
[155]: https://leetcode.com/problems/min-stack/
[167]: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
[171]: https://leetcode.com/problems/excel-sheet-column-number/
[190]: https://leetcode.com/problems/reverse-bits/
[191]: https://leetcode.com/problems/number-of-1-bits
[206]: https://leetcode.com/problems/reverse-linked-list/
[217]: https://leetcode.com/problems/contains-duplicate/
[225]: https://leetcode.com/problems/implement-stack-using-queues/
[226]: https://leetcode.com/problems/invert-binary-tree/
[231]: https://leetcode.com/problems/power-of-two/
[232]: https://leetcode.com/problems/implement-queue-using-stacks
[237]: https://leetcode.com/problems/delete-node-in-a-linked-list
[242]: https://leetcode.com/problems/valid-anagram/ 
[257]: https://leetcode.com/problems/binary-tree-paths/
[258]: https://leetcode.com/problems/add-digits
[268]: https://leetcode.com/problems/missing-number/
[283]: https://leetcode.com/problems/move-zeroes
[292]: https://leetcode.com/problems/nim-game/
[326]: https://leetcode.com/problems/power-of-three/
[342]: https://leetcode.com/problems/power-of-four/
[344]: https://leetcode.com/problems/reverse-string/
[347]: https://leetcode.com/problems/top-k-frequent-elements/
[349]: https://leetcode.com/problems/intersection-of-two-arrays/
[374]: https://leetcode.com/problems/guess-number-higher-or-lower
[383]: https://leetcode.com/problems/ransom-note/
[384]: https://leetcode.com/problems/shuffle-an-array
[387]: https://leetcode.com/problems/first-unique-character-in-a-string/
[389]: https://leetcode.com/problems/find-the-difference/
[405]: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
[412]: https://leetcode.com/problems/fizz-buzz/
[429]: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
[448]: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
[461]: https://leetcode.com/problems/hamming-distance/
[476]: https://leetcode.com/problems/number-complement/
[485]: https://leetcode.com/problems/max-consecutive-ones/
[496]: https://leetcode.com/problems/next-greater-element-
[500]: https://leetcode.com/problems/keyboard-row
[509]: https://leetcode.com/problems/fibonacci-number/
[520]: https://leetcode.com/problems/detect-capital/
[521]: https://leetcode.com/problems/longest-uncommon-subsequence-i/
[530]: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
[535]: https://leetcode.com/problems/encode-and-decode-tinyurl/
[538]: https://leetcode.com/problems/convert-bst-to-greater-tree
[566]: https://leetcode.com/problems/reshape-the-matrix/
[575]: https://leetcode.com/problems/distribute-candies
[589]: https://leetcode.com/problems/n-ary-tree-preorder-traversal
[559]: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
[561]: https://leetcode.com/problems/array-partition-i/
[590]: https://leetcode.com/problems/n-ary-tree-postorder-traversal
[606]: https://leetcode.com/problems/construct-string-from-binary-tree/
[617]: https://leetcode.com/problems/merge-two-binary-trees/
[637]: https://leetcode.com/problems/average-of-levels-in-binary-tree/
[643]: https://leetcode.com/problems/maximum-average-subarray-i/
[653]: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
[654]: https://leetcode.com/problems/maximum-binary-tree/
[657]: https://leetcode.com/problems/robot-return-to-origin/
[669]: https://leetcode.com/problems/trim-a-binary-search-tree/
[682]: https://leetcode.com/problems/baseball-game/
[690]: https://leetcode.com/problems/employee-importance
[693]: https://leetcode.com/problems/binary-number-with-alternating-bits/
[696]: https://leetcode.com/problems/count-binary-substrings/
[697]: https://leetcode.com/problems/degree-of-an-array/
[700]: https://leetcode.com/problems/search-in-a-binary-search-tree/
[704]: https://leetcode.com/problems/binary-search/
[705]: https://leetcode.com/problems/design-hashset
[709]: https://leetcode.com/problems/to-lower-case/
[728]: https://leetcode.com/problems/self-dividing-numbers
[748]: https://leetcode.com/problems/shortest-completing-word/
[766]: https://leetcode.com/problems/toeplitz-matrix/
[771]: https://leetcode.com/problems/jewels-and-stones/ 
[783]: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
[788]: https://leetcode.com/problems/rotated-digits
[804]: https://leetcode.com/problems/unique-morse-code-words/
[806]: https://leetcode.com/problems/number-of-lines-to-write-string/
[807]: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
[811]: https://leetcode.com/problems/subdomain-visit-count/
[812]: https://leetcode.com/problems/largest-triangle-area/
[821]: https://leetcode.com/problems/shortest-distance-to-a-character/
[824]: https://leetcode.com/problems/goat-latin/
[832]: https://leetcode.com/problems/flipping-an-image/
[852]: https://leetcode.com/problems/peak-index-in-a-mountain-array/
[859]: https://leetcode.com/problems/buddy-strings/
[867]: https://leetcode.com/problems/transpose-matrix/
[868]: https://leetcode.com/problems/binary-gap/
[872]: https://leetcode.com/problems/leaf-similar-trees/
[876]: https://leetcode.com/problems/middle-of-the-linked-list/
[883]: https://leetcode.com/problems/projection-area-of-3d-shapes/
[884]: https://leetcode.com/problems/uncommon-words-from-two-sentences/
[888]: https://leetcode.com/problems/fair-candy-swap/
[896]: https://leetcode.com/problems/monotonic-array
[897]: https://leetcode.com/problems/increasing-order-search-tree/
[905]: https://leetcode.com/problems/sort-array-by-parity/
[908]: https://leetcode.com/problems/smallest-range-i/
[917]: https://leetcode.com/problems/reverse-only-letters/
[922]: https://leetcode.com/problems/sort-array-by-parity-ii/
[929]: https://leetcode.com/problems/unique-email-addresses/
[933]: https://leetcode.com/problems/number-of-recent-calls
[937]: https://leetcode.com/problems/reorder-data-in-log-files/
[938]: https://leetcode.com/problems/range-sum-of-bst/
[942]: https://leetcode.com/problems/di-string-match/
[944]: https://leetcode.com/problems/delete-columns-to-make-sorted
[961]: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
[965]: https://leetcode.com/problems/univalued-binary-tree/
[976]: https://leetcode.com/problems/largest-perimeter-triangle/
[977]: https://leetcode.com/problems/squares-of-a-sorted-array/
[985]: https://leetcode.com/problems/sum-of-even-numbers-after-queries
[989]: https://leetcode.com/problems/add-to-array-form-of-integer/
[999]: https://leetcode.com/problems/available-captures-for-rook
[1002]: https://leetcode.com/problems/find-common-characters/
[1008]: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
[1009]: https://leetcode.com/problems/complement-of-base-10-integer/ 
[1021]: https://leetcode.com/problems/remove-outermost-parentheses
[1022]: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers
[1025]: https://leetcode.com/problems/divisor-game/
[1030]: https://leetcode.com/problems/matrix-cells-in-distance-order/
[1038]: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree
[1046]: https://leetcode.com/problems/last-stone-weight/
[1047]: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
[1051]: https://leetcode.com/problems/height-checker
[1078]: https://leetcode.com/problems/occurrences-after-bigram
[1103]: https://leetcode.com/problems/distribute-candies-to-people/
[1108]: https://leetcode.com/problems/defanging-an-ip-address/
[1122]: https://leetcode.com/problems/relative-sort-array/
[1137]: https://leetcode.com/problems/n-th-tribonacci-number/
[1160]: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
[1170]: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
[1184]: https://leetcode.com/problems/distance-between-bus-stops/
[1185]: https://leetcode.com/problems/day-of-the-week/
[1189]: https://leetcode.com/problems/maximum-number-of-balloons/
[1200]: https://leetcode.com/problems/minimum-absolute-difference/
[1207]: https://leetcode.com/problems/unique-number-of-occurrences/
[1217]: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
[1237]: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
[1252]: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
[1260]: https://leetcode.com/problems/shift-2d-grid/
[1266]: https://leetcode.com/problems/minimum-time-visiting-all-points/
[1275]: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
[1281]: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
[1282]: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
[1287]: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
[1290]: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
[1295]: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
[1299]: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
[1302]: https://leetcode.com/problems/deepest-leaves-sum/
[1304]: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
[1309]: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
[1313]: https://leetcode.com/problems/decompress-run-length-encoded-list/
[1315]: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
[1317]: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
[1323]: https://leetcode.com/problems/maximum-69-number/
[1329]: https://leetcode.com/problems/sort-the-matrix-diagonally/
[1332]: https://leetcode.com/problems/remove-palindromic-subsequences/
[1337]: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
[1342]: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
[1351]: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
[1356]: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
[1365]: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
[1370]: https://leetcode.com/problems/increasing-decreasing-string/
[1374]: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
[1379]: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
[1380]: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
[1385]: https://leetcode.com/problems/find-the-distance-value-between-two-arrays
[1389]: https://leetcode.com/problems/create-target-array-in-the-given-order/
[1394]: https://leetcode.com/problems/find-lucky-integer-in-an-array/
[1399]: https://leetcode.com/problems/count-largest-group/
[1403]: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
[1408]: https://leetcode.com/problems/string-matching-in-an-array/
[1409]: https://leetcode.com/problems/queries-on-a-permutation-with-key/
[1413]: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum
[1417]: https://leetcode.com/problems/reformat-the-string/
[1422]: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
[1431]: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
[1436]: https://leetcode.com/problems/destination-city/
[1441]: https://leetcode.com/problems/build-an-array-with-stack-operations/
[1446]: https://leetcode.com/problems/consecutive-characters
[1450]: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
[1455]: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
[1460]: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
[1464]: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
[1470]: https://leetcode.com/problems/shuffle-the-array/
[1475]: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
[1476]: https://leetcode.com/problems/subrectangle-queries/
[1480]: https://leetcode.com/problems/running-sum-of-1d-array/
[1486]: https://leetcode.com/problems/xor-operation-in-an-array/
[1491]: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
[1496]: https://leetcode.com/problems/path-crossing/
[1502]: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
[1507]: https://leetcode.com/problems/reformat-date/
[1512]: https://leetcode.com/problems/number-of-good-pairs/
[1518]: https://leetcode.com/problems/water-bottles/
[1523]: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
[1528]: https://leetcode.com/problems/shuffle-string/
[1534]: https://leetcode.com/problems/count-good-triplets 
[1539]: https://leetcode.com/problems/kth-missing-positive-number/
[1544]: https://leetcode.com/problems/make-the-string-great
[1550]: https://leetcode.com/problems/three-consecutive-odds
[1556]: https://leetcode.com/problems/thousand-separator/
[1560]: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
[1572]: https://leetcode.com/problems/matrix-diagonal-sum/
[1582]: https://leetcode.com/problems/special-positions-in-a-binary-matrix
[1588]: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
[1598]: https://leetcode.com/problems/crawler-log-folder/
[1603]: https://leetcode.com/problems/design-parking-system/
[1608]: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
[1614]: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses
[1619]: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
[1624]: https://leetcode.com/problems/largest-substring-between-two-equal-characters
[1629]: https://leetcode.com/problems/slowest-key/
[1636]: https://leetcode.com/problems/sort-array-by-increasing-frequency/
[1637]: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
[1640]: https://leetcode.com/problems/check-array-formation-through-concatenation
[1646]: https://leetcode.com/problems/get-maximum-in-generated-array/
[1652]: https://leetcode.com/problems/defuse-the-bomb/
[1656]: https://leetcode.com/problems/design-an-ordered-stream/
[1662]: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent
[1672]: https://leetcode.com/problems/richest-customer-wealth
[1678]: https://leetcode.com/problems/goal-parser-interpretation/
[1684]: https://leetcode.com/problems/count-the-number-of-consistent-strings/
[1688]: https://leetcode.com/problems/count-of-matches-in-tournament/
[1694]: https://leetcode.com/problems/reformat-phone-number
[1689]: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/ 
[1700]: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
[1704]: https://leetcode.com/problems/determine-if-string-halves-are-alike/
[1710]: https://leetcode.com/problems/maximum-units-on-a-truck/
[1716]: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
[1720]: https://leetcode.com/problems/decode-xored-array/
[1725]: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
[1732]: https://leetcode.com/problems/find-the-highest-altitude
[1742]: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
[1748]: https://leetcode.com/problems/sum-of-unique-elements/ 
[1752]: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
[1768]: https://leetcode.com/problems/merge-strings-alternately/
[1773]: https://leetcode.com/problems/count-items-matching-a-rule
[1779]: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
[1790]: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
[1800]: https://leetcode.com/problems/maximum-ascending-subarray-sum
[1812]: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
[1816]: https://leetcode.com/problems/truncate-sentence/
[1822]: https://leetcode.com/problems/sign-of-the-product-of-an-array