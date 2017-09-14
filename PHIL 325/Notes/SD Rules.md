# Rules of `SD`
## Conjunction Elimination
specifies that if a conjunction occurs on an earlier line of a derivation then we may enter on a subsequent line either the left conjunct or the right conjunct of the conjunction.
```
A & B
A      <-
```

## Conjunction Introduction
specifies that if P and Q occur on earlier lines of a derivation then we may enter P & Q on a subsequent line. Here the rule template should not be taken as specifying the order in which P and Q must be derived before P & Q can be entered.
```
A
B
A & B  <-
```

## Disjunction Introduction
specifies that if a sentence P occurs on an earlier line of a derivation then we may enter on a subsequent line either P ∨ Q or Q ∨ P, where Q is any sentence of SL.
```
A
A v B  <-
```

## Conditional Elimination
specifies that if P ⊃ Q and P occur on earlier lines of a derivation, in either order, then we may enter Q on a subsequent line.
```
P ⊃ Q
P
Q      <-
```

## Biconditional Elimination
specifies that if a sentence of the form P = Q and one of its immediate components (P or Q) occur on earlier lines of a derivation, in either order, then we may enter on a subsequent line the other immediate component.
```
P = Q
Q
P      <-
```

## Negation Introduction
specifies that if we can derive a sentence and its negation, Q and ~Q, within the scope of an auxiliary assumption P, then we may end the subderivation and enter ~P on the following line. Here and with the remaining subderivation rules the template should not be taken as specifying the order in which sentences must be derived within the subderivation.

## Negation Elimination
specifies that if we can derive a sentence and its negation, Q and ~ Q, within the scope of an auxiliary assumption ~ P, then we may end the subderivation and enter P on a subsequent line.

## Disjunction Elimination
specifies that if P ∨ Q occurs on an earlier line of a derivation and subsequent to it there are two subderivations, one of R from P and the other of R from Q, then R may be entered on a subsequent line.
```
Basically you just prove that something can be derived from both halves of a disjunction, and that thing is true
```

## Biconditional Introduction
specifies that if the derivation contains two subderivations, one of Q from P and one of P from Q, then P = Q may be entered on a subsequent line.


## Conditional Introduction
specifies that if you begin with the a subderivation with premise P results in Q, P ⊃ Q can be entered on a subsequent line
