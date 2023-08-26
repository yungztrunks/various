# [no-duplicates](https://open.kattis.com/problems/nodup)

## problem

there is a game in which you try not to repeat a word while your opponent tries to see if you have repeated one.

>* "the rain in spain" has no repeats.
>* "in the rain and the snow" repeats the.
>* "the rain in spain in the plain" repeats the and in.

write a program to test a phrase.

### input

input is a line containing words separated by single spaces, where a word consists of one or more uppercase letters. a line contains no more than 80 characters.

### output

the output is "yes" if no word is repeated, and "no" if one or more words repeat.

### examples

_input_
```text
the rain in spain
```
_output_
`yes`

---
_input_
```text
in the rain and the snow
```
_output_
`no`

---
_input_
```text
the rain in spain in the plain
```
_output_
`no`