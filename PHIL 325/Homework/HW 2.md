# Homework 2 - Addie Morrison
## 3.2
### Q1
#### J
Truth Functionally True

| D | B | ~B | B ∨ D | (B ∨ D) ⊃ D | ~B ⊃ ((B ∨ D) ⊃ D) |
|:-:|:-:|:--:|:-----:|:-----------:|:------------------:|
| F | F | T  |   F   |      T      |         T          |
| F | T | F  |   T   |      F      |         T          |
| T | F | T  |   T   |      T      |         T          |
| T | T | F  |   T   |      T      |         T          |

### Q5
#### D
True -- That's the definition of the amper operator
#### F
False -- Consider the case of `False ⊃ False`
### Q6
#### B
Frequently, but not always -- Consider the case `(A v B) & (~A v ~B)`
## 3.3
### Q1
#### H
Not Equivalent

| D | B | C | B ∨ D | ~(B ∨ D) | C ⊃ B | ~(B ∨ D) ⊃ (C ⊃ B) |
|:-:|:-:|:-:|:-----:|:--------:|:-----:|:------------------:|
| F | F | F |   F   |    T     |   T   |         T          |
| F | F | T |   F   |    T     |   F   |         F          |
| F | T | F |   T   |    F     |   T   |         T          |
| F | T | T |   T   |    F     |   T   |         T          |
| T | F | F |   T   |    F     |   T   |         T          |
| T | F | T |   T   |    F     |   F   |         T          |
| T | T | F |   T   |    F     |   T   |         T          |
| T | T | T |   T   |    F     |   T   |         T          |

| D | B | C | B & D | C ⊃ (B & D) |
|:-:|:-:|:-:|:-----:|:-----------:|
| F | F | F |   F   |      T      |
| F | F | T |   F   |      F      |
| F | T | F |   F   |      T      |
| F | T | T |   F   |      F      |
| T | F | F |   F   |      T      |
| T | F | T |   F   |      F      |
| T | T | F |   T   |      T      |
| T | T | T |   T   |      T      |

### Q3
#### F
They are truth-functionally equivalent
##### Key
- B: Blue team wins
- R: Red team wins

##### Symbolization
- `(B v R) & ~(B & R)`
- `(R ⊃ ~B) & (~B ⊃ R)`

##### Truth Tables
| B | R | B ∨ R | B & R | ~(B & R) | ~(B & R) & (B ∨ R) |
|:-:|:-:|:-----:|:-----:|:--------:|:------------------:|
| F | F |   F   |   F   |    T     |         F          |
| F | T |   T   |   F   |    T     |         T          |
| T | F |   T   |   F   |    T     |         T          |
| T | T |   T   |   T   |    F     |         F          |

| R | B | ~B | R ⊃ ~B | ~B | ~B ⊃ R | (R ⊃ ~B) & (~B ⊃ R) |
|:-:|:-:|:--:|:------:|:--:|:------:|:-------------------:|
| F | F | T  |   T    | T  |   F    |          F          |
| F | T | F  |   T    | F  |   T    |          T          |
| T | F | T  |   T    | T  |   T    |          T          |
| T | T | F  |   F    | F  |   T    |          F          |
### Q4
#### B
| P | Q | P ≡ Q | P & Q | P |
|:-:|:-:|:-----:|:-----:|:-:|
| F | F |   T   |   F   | F |
| T | T |   T   |   T   | T |

## 3.4
### Q1
#### F
They are consistant
| U | W | H | U ∨ (H & W) | W ≡ (H ∨ U) | H ∨ ~H |
|:-:|:-:|:-:|:-----------:|:-----------:|:------:|
| F | F | F |      F      |      T      |   T    |
| F | F | T |      F      |      F      |   T    |
| F | T | F |      F      |      F      |   T    |
| F | T | T |      T      |      T      |   T    |
| T | F | F |      T      |      F      |   T    |
| T | F | T |      T      |      F      |   T    |
| T | T | F |      T      |      T      |   T    |
| T | T | T |      T      |      T      |   T    |

### Q4
#### B
No -- Consider the case where **P** is {`A v ~A`, `B v ~B`}

The set will be consistant, but the denial of each will be inconsistent

## 3.5
### Q5
#### C
%%%%%%
Show that if {P} |= Q and {Q} |= R, then {P} |= R.

## 3.6
### Q2
#### D
%%%%%%
For any set Γ of sentences of SL and any truth-functionally false sentence P of SL, Γ ∪ {P} is truth-functionally inconsistent.
### Q3
#### B
%%%%%%
If Γ |= P and Γ |= ∼ P, then Γ is truth-functionally inconsistent.
