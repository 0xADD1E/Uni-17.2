# Homework 1 - Addie Morrison
## 1.2
### Q1
#### D
No

#### F
Yes

#### H
Yes

## 1.3
### Q2
### D

Assume **{P}** is a logically inconsistent set of sentences, and **Q** is an arbitary statement

Thus, it is is impossible for all elements of **{P}** to be true simulaniously

Thus, it will be impossible for all of **{P}**'s elements to be true, while having **Q** be false

Thus, **{P}** logically entails **Q**

Therefore **{P}** ⊃ **Q** is logically valid

Additionally, it is is impossible for all elements of **{P}** to be true simulaniously

Therefore, it is impossible for any argument with premises **{P}** to be logically sound


<div class="page-break"></div>


## 2.1
### Q1
Which of the following are sentences of SL and which are not? For those that are not, explain why they are not

#### D
No -- `~` isn't a binary connective

#### F
No -- bolded letters aren't defined in that context

#### H
No -- Missing parentheses to denote logical precidence

### 4
#### F
##### Left of ~
Yes -- `~~A`

##### Right of A
No -- It's a unary operator

## 2.3
### Q4
#### H

| Symbol | Statement                           |
|:-------|:------------------------------------|
| R      | Claude Raines was in the movie      |
| G      | Sydney Greenstreet was in the movie |
| L      | Peter Lorre was in the movie        |
| C      | The movie was Casablanca            |
```
((R & G) & L) ⊃ C
```

### Q5
#### B
If Phil likes either Joseph Cotton or Orson Wells he will like The Third Man, if he sees it. If he likes either Peter O’Toole or Katharine Hepburn he’ll like The Lion in Winter, if he sees it. He doesn’t like either Joseph Cotton or Orson Wells, but he does like Katharine Hepburn. So if he sees The Lion in Winter he will like it.

| Symbol | Statement                     |
|:-------|:------------------------------|
| C      | Phil likes Joseph Cotton      |
| W      | Phil likes Orson Wells        |
| H      | Phil sees The Third Man       |
| I      | Phil likes The Third Man      |
| P      | Phil likes Peter O'Toole      |
| K      | Phil likes Katharine Hepburn  |
| S      | Phil sees The Lion in Winter  |
| L      | Phil likes The Lion in Winter |
```
((C v W) & H) ⊃ I
((P v K) & S) ⊃ L
~C
~W
K
-----------------
S ⊃ L
```
#### D

| Symbol | Statement                                   |
|:-------|:--------------------------------------------|
| A      | Betty will see The Lion in Winter           |
| B      | Betty will see Whitness for the Prosecution |
| C      | Marion will see Casablanca                  |
| D      | Marion will see Charade                     |
| E      | Eric will see Whitness for the Prosecution  |
| F      | Eric will see Casablanca                    |
| G      | Phil will see The Lion in Winter            |

```
A v B
C & D
B ⊃ ~E
C ⊃ F
~B
A ≡ G
---------
G
```

## 2.4
### Q1
#### B

| Symbol | Statement                            |
|:-------|:-------------------------------------|
| R      | Rocky knows when the concert starts  |
| G      | George knows when the concert starts |
```
R v G
```

#### H

| Symbol | Statement                                         |
|:-------|:--------------------------------------------------|
| S      | John believes that our manuscript has been stolen |
| L      | Howard believes that our manuscript has been lost |
```
S & L
```

#### J
It is possible that the Twins will win tonight and possible that the Red Sox will
win tonight, but it is not likely that they will both win tonight.
| Symbol | Statement                                    |
|:-------|:---------------------------------------------|
| A      | The Twins will possibly win tonight          |
| B      | The Red Sox will possibly win tonight        |
| C      | It is likely that they will both win tonight |
```
(A & B) & ~C
```

### Q2
#### B

| Symbol | Statement                                                 |
|:-------|:----------------------------------------------------------|
| G      | This piece of metal is gold                               |
| N      | This piece of metal has atomic number 79                  |
| B      | Nordvik believes this piece of metal is gold              |
| C      | Nordvik believes this piece of metal has atomic number 79 |
```
G ⊃ N
B
-----
C
```
