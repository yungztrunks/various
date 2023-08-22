# [mumble-rap](https://open.kattis.com/problems/mumblerap)

```text
one of the worst questions I have ever seen omg... WHO the fuck made this shit?
the problem itself is ok to solve...
- yungztr
```

## problem

Willó listens to several different music genres and usually talks to both his friends about his favorite artists. One day, Willó asked her parents if they were willing to pay for a ticket to a music festival. The parents agreed to it at first, but his mother became quite hesitant when she realized that it was not just any music festival, but a mumble rap music festival

---

Willó’s mother asked Willó how he could have an interest in such an incomprehensible music genre, as she found it difficult to identify numbers from words that the artist is mumbling. According to Willó’s mother, mumble rap is known to be a genre where the artist always raps about how much money they own in a mumbling fashion. But Willó wanted to show love for mumble rap and prove his mother wrong, so he came up with the following plan: Willó wants to write a program that can identify the largest number in a string of characters that an artist has mumbled.

---

### input

The first line consists of an integer `1<=N<=10^6` the number of characters in the string.
The second line consists of N characters in a string without spaces, where each character is either a letter from **“a”-“z”,“A”-“Z”**, a symbol **(“.,;:?!”)**, or a digit between *0* and *9*, including *0* and *9*.

---

### output

Print an integer 0<=A<=10^9 - The largest integer mentioned in the string. It is guaranteed that there is always a number in the string.

---

### examples

_input_
```text
29
ihave40dollarsinmybankaccount
```
_output_
`40`

---
_input_
```text
33
yesterdayihad1001,BUTnowihave9999
```
_output_
`9999`

---
_input_
```text
19
13twenty209sixty123
```
_output_
`209`