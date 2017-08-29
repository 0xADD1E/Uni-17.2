## 1.2
### Q1
Do the following sentances have a truth value?

#### D
No

#### F
Yes

#### H
Yes

## 1.3
### Q2
### D
With an inconsistent set of premises, you can draw any conclusion you like (making it logically valid), but the premises can never be all true due to the inconsistancy, making it impossible to be sound

## 2.1
### Q1
Which of the following are sentences of SL and which are not? For those that are not, explain why they are not

#### D
Informally, yes (no outer parentheses)

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

## 2.3 p. 55
### Q4
#### H
If Claude Raines (`R`) was in the movie and Sydney Greenstreet (`G`) was in the movie, and Peter Lorre (`L`) was in the movie, then the movie was Casablanca (`C`).

`((R & G) & L) ⊃ C`
### Q5
Construct a truth-functional paraphrase of each of the following arguments, then provide a symbolization key and use it to symbolize your paraphrase of the argument in SL.
#### B

If Phil likes Peter O'Toole, or he likes Katharine Hepburn, and he sees The Lion in Winter, then he will like it.
He does like Katharine Hepburn.
Therefore, if he sees The Lion in Winter, he will like it

---

| Symbol | Statement                     |
|:-------|:------------------------------|
| P      | Phil likes Peter O'Toole      |
| K      | Phil likes Katharine Hepburn  |
| S      | Phil sees The Lion in Winter  |
| L      | Phil likes The Lion in Winter |

---

```
((P v K) & S) ⊃ L
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

## 2.4E (p. 68)
### Q1
Paraphrase and symbolize each of the following sentences that can reasonaAy be paraphrased as a truth-functional compound. If a sentence cannot be so paraphrased, explain why this is so. Provide a symbolization key when it is not obvious what sentence your sentence letters are symbolizing.
#### B
Either Rocky or George knows what time the concert starts.
```
R v G
```
#### H
John believes that our manuscript has been stolen, and Howard believes that it has been lost.
```
S & L
```

#### J
It is possible that the Twins will win tonight and possible that the Red Sox will win tonight, but it is not likely that they will both win tonight.

Not possible (at least to express anything other than truth values) -- We don't have a way of discussing likelihood

### Q2
Construct truth-functional paraphrases of the premises and conclusions of the following arguments, provide symbolization keys, and symbolize your paraphrases in SL.
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
