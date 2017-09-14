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
True -- That's the definition of `&`
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

<div class="page-break"></div>

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

<div class="page-break"></div>

### Q4
#### B
No -- Consider the case where **P** is {`A v ~A`, `B v ~B`}

The set will be consistant, but the denial of each will be inconsistent

## 3.5
### Q5
#### C
By definition, there are no assignments where all members of **{P}** are true, and any members of **{Q}** are false.

By definition, there are no assignments where all members of **{Q}** are true, and **R** is false.

For **R** to not be entailed by **{P}**, there would need to be at least one truth-value assignment where all members of **{P}** are true, and **R** is false -- However, this is impossible

Therefore, if **{P}** logically entails **{Q}**, and **{Q}** logically entails **R**, **{P}** logically entails **R**

## 3.6
### Q2
#### D
By definition, for **Γ** to truth-functionally entail **P**, every truth-value assignment resulting in all values of **Γ** being true must also result in **P** being true

However, **P** can never be truth-functionally

Therefore, **Γ** cannot logically entail **P**
### Q3
#### B
By definition, for **Γ** to logically entail **P**, every truth-value assignment resulting in all values of **Γ** being true must also result in **P** being true

By definition, for **Γ** to logically entail **~P**, every truth-value assignment resulting in all values of **Γ** being true must also result in **~P** being true

The only way for both of the previous statements to be true, is if there is not truth-value assignemnt where all members of **Γ** are true

By definition, this makes the members of **Γ** truth-functionally inconsistent.
