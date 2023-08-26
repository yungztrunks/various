# [fyi](https://open.kattis.com/problems/fyi)

## problem

in the united states of america, telephone numbers within an area code consist of seven digits: the prefix number is the first three digits and the line number is the last four digits. traditionally, the prefix number has been used to provide directory information and assistance as in the following examples:

* 555-1212
* 555-9876
* 555-5000
* 555-7777

telephone company switching hardware would detect the **555** prefix and route the call to a directory information operator. nowadays, telephone switching is done digitally and somewhere along the line a computer decides where to route calls.

for this problem, write a program that determines if a supplied seven-digit telephone number should be routed to the directory information operator, that is, the prefix number is **555**.

### input

the single line of input contains a single integer **n(100 000 0 <= _n_ <=9999999)**, which is a telephone number.

### output

output a single integer, which is 1 if the number should be routed to the directory information operator, or 0 if the number should not be routed to the directory information operator.

### examples

_input_
```text
5551212
```
_output_
`1`

---
_input_
```text
5519876
```
_output_
`0`

---
_input_
```text
5055555
```
_output_
`1`

---
_input_
```text
5550000
```
_output_
`0`]