# [last-factorial-digit](https://open.kattis.com/problems/lastfactorialdigit)

## problem

the factorial of **n**, written as **n!**, is defined as the product of all the integers from **1** to **n**. for example, **3! = 1 x 2 x 3 = 6.**

this number can be very large, so instead of computing the entire product, just compute the last digit of **n!** (when **n** is written in base 10).

### input

the first line of input contains a positive integer **1 <= _t_ <= 10**, the number of test cases. each of the next **t** lines contains a single positive integer **n**. **n** is at most 10.

### output

for each value of **n**, print the last digit on **n!**

### examples

_input_
```text
3
1
2
3
```
_output_
`11`
`2`
`6`

---
_input_
```text
2
5
2
```
_output_
`0`
`2`