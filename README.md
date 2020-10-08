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


[1480]: https://leetcode.com/problems/running-sum-of-1d-array/
[1431]: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
[1470]: https://leetcode.com/problems/shuffle-the-array/
