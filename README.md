# Introduction

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
| **pa**| *push a* - take the first element at the top of `B` and put it at the top of `A`. Do nothing if b is empty.|
| **pb**| *push b* - take the first element at the top of `A` and put it at the top of `B`. Do nothing if a is empty.|

|SWAP| Descritption|
|:---:|:---:|
| **sa**| *swap a* - swap the first 2 elements at the top of `Stack A`. Do nothing if there are only one or no elements).|
| **sb**| *swap b* - swap the first 2 elements at the top of `Stack B`. Do nothing if there are only one or no elements).|
| **ss**|**sa** and **sb** at the same time.|

|> REVERSE ROTATE| Descritption|
|:---:|:---:|
| **rra**| *reverse rotate a* - shift down all elements of `Stack A` by 1. The last element becomes the first one.|  
| **rrb**| *reverse rotate b* - shift down all elements of `Stack B` by 1. The last element becomes the first one.|  
| **rrr**| **rra** and **rrb** at the same time.|  

