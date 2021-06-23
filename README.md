# Push_Swap 🔄
## Introduction

This project is part of the 2nd Tier of the 42 Cursus.  

We are given 2 stacks:   
`Stack A` is filled with a random amount of ints (negative and positive) in a random order;  
`Stack B` is empty.

The goal of the project is to order the numbers in Stack A where the smallest number should be on top, using the following instructions: 
|ROTATE| Descritption|
|:---:|:---:|
| **ra**| *rotate a* - shift up all elements of `Stack A` by 1. The first element becomes the last one.|
| **rb**| *rotate b* - shift up all elements of `Stack B` by 1. The first element becomes the last one.|  
| **rr** |**ra** and **rb** at the same time.|

|PUSH| Descritption|
|:---:|:---:
| **pa**| *push a* - take the first element at the top of `B` and put it at the top of `A`. Do nothing if `B` is empty.|
| **pb**| *push b* - take the first element at the top of `A` and put it at the top of `B`. Do nothing if `A` is empty.|

|SWAP| Descritption|
|:---:|:---:|
| **sa**| *swap a* - swap the first 2 elements at the top of `Stack A`. Do nothing if there are only one or no elements).|
| **sb**| *swap b* - swap the first 2 elements at the top of `Stack B`. Do nothing if there are only one or no elements).|
| **ss**|**sa** and **sb** at the same time.|

| REVERSE ROTATE| Descritption|
|:---:|:---:|
| **rra**| *reverse rotate a* - shift down all elements of `Stack A` by 1. The last element becomes the first one.|  
| **rrb**| *reverse rotate b* - shift down all elements of `Stack B` by 1. The last element becomes the first one.|  
| **rrr**| **rra** and **rrb** at the same time.|  

## Error Handling ⚠️

If the arguments given are:

- ***not digits***; 
- ***over*** or ***under INT MAX*** or ***INT MIN***
- ***duplicate***

The program should return an `Error` message.

If *1 or fewer arguments* are given, or the arguments given are *already sorted* the program should return `nothing(zero lines)`.

## Method & Algorithms 🤔

I decided to go with `Double Linked Lists` with the idea of having less trouble going up and down the stacks.
This also helped me a lot with understanding even more about double pointers and the so called *pointer's magic*.

I also decided to divide my program into 3 different algorithms depending on the size of `Stack A`.

#### Sort Small ▫️

If the size of `Stack A` is **less than or equal to 3** the program will run this algorithm. 
The algorithm works with simple sorting instructions.

#### Sort Medium ◻️

If the size of `Stack A` is **less than or equal to 5** the program will run this algorithm.
The algorithm works by pushing the 2 smallest numbers to `Stack B` in order of smallest, sorting the remaining numbers using **Sort Small** and then emptying out `Stack B`.

Example with ARG = " 1 5 2 4 3"
```
Step 1:
 1
 5
 2
 4
 3
---  ---
 A    B
 
Step 2: pb, ra, pb
 
 4
 3    2
 5    1
---  ---
 A    B
 
Step 3: sa

 3
 4    2
 5    1
---  ---
 A    B
 
Step 4: pa, pa
 
 1
 2
 3
 4    
 5    
---  ---
 A    B
```
#### Sort Large ⬜

If the size of `Stack A` is **larger than 5** the program will run this algorithm.

The original idea was to have this part divided in two, where the first part would handle sizes of 100 numbers or less and the second part would handle sizes with over 100 numbers.  I ended up deciding to make an algorithm that would work for both these cases at the same time instead of separating them.

The way the algorithm works is by dividing `Stack A` into 4 parts using **medians**. I start by finding the first median of the stack. After that, I use the said median and find another median, this time between the first median and the max value. 

I then send all values larger than this second median to `Stack B` using some functions to "pre-sort" them when they reach the stack. After all the numbers are pushed to `Stack B`, I send them back to `Stack A` but already sorted.

After this, I do the same thing but with the value between the first median and the second median.

I repeat the process of finding the second median, this time to find a third median between the first median and the min value of `Stack A`. I then do the exact same sorting for the numbers between the first median and the third median and lastly the numbers between the third median and the min value.

The process should look exactly like this:

![Visualizer](https://github.com/J0Santos/42-push_swap/blob/master/ezgif.com-gif-maker.gif)

## Possible Improvements

* During the third part, when I **pa** all numbers from `Stack B`, I decided to make the sorting a bit messy only for the visual effect while using the visualizer, because why not? If I had not done this, I would have had fewer instructions but my grade would still be the same so I allowed myself to have some fun. 😉

* If I were to divide `Stack A` a couple more times, I believe I'd get fewer instructions. Between 6-8 total divisions would probably be the best, but this is just speculation.

* If I were to make the program recursive and figure out how many medians I had to find out instead of settling for 4 in all cases, I'm sure I could get way fewer instructions, especially when dealing with over 100 numbers.

Why don't I do this then? Because I'm already happy with what I achieved. The algorithm created by me alone and the fact that it got me a passing grade is currently sufficient for me. I'm sure I'll come back in the future to make the program better, but for now, it is how it is.

## Useful Stuff 💡

* [GitHub for the Visualizer](https://github.com/o-reo/push_swap_visualizer);
* [Guide I used for the project introduction](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a);
* [If you are feeling adventurous](https://www.geeksforgeeks.org/merge-sort-for-doubly-linked-list/);
