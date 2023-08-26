# [eye-of-sauron](https://open.kattis.com/problems/meyeofsauron)

## problem

little elrond is obsessed with the lord of the rings series. between lectures he likes to doodle the central tower of the great fortress barad-dûr in the margins of his notebook. afterward, he always double checks his drawings to ensure they are accurate: with the eye of sauron located in the very center of the tower. if any are incorrect, he makes sure to fix them.

you are to write a program that reads a representation of his tower, and ensures that the drawing is correct, with a properly centered eye.

### input

input consists of a single string of length **n**, where **4 <= _n_ <= 100.
input strings will consist only of three types of characters: vertical bars, open parentheses, and closing parentheses. input strings contain one or more vertical bars followed by a set of matching parentheses (the “eye”), followed by one or more vertical bars. for a drawing to be “correct”, the number of vertical bars on either side of the “eye” must match. input will always contain a pair of correctly matched parentheses, with no characters between them. no other characters will appear in the string.

### output

on a single line print the word “correct” if the drawing is accurate or the word “fix” if there is an error that needs addressing.

### examples

_input_
```text
|()||
```
_output_
`fix`

---
_input_
```text
||||()||||
```
_output_
`correct`

---
_input_
```text
|()|
```
_output_
`correct`

---
_input_
```text
|||()|
```
_output_
`fix`