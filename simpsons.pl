%% File: simpsons.pl
%% Name: Kyle Byassee
%% Description: Simpson's family tree

%%%%%%%

%Facts:

male(bart_simpson).
male(homer_simpson).
male(abraham_simpson).
male(orville_simpson).

male(clancy_bouvier).

female(lisa_simpson).
female(maggy_simpson).
female(marge_simpson).
female(selma_bouvier).
female(patty_bouvier).
female(jackie_bouvier).

female(mona_simpson).
female(yuma_simpson).

parent(homer_simpson, bart_simpson).
parent(homer_simpson, lisa_simpson).
parent(homer_simpson, maggy_simpson).
parent(marge_simpson, bart_simpson).
parent(marge_simpson, lisa_simpson).
parent(marge_simpson, maggy_simpson).

parent(abraham_simpson, homer_simpson).
parent(mona_simpson, homer_simpson).

parent(orville_simpson, abraham_simpson).
parent(yuma_simpson, abraham_simpson).

parent(clancy_bouvier, marge_simpson).
parent(clancy_bouvier, selma_bouvier).
parent(clancy_bouvier, patty_bouvier).
parent(jackie_bouvier, marge_simpson).
parent(jackie_bouvier, selma_bouvier).
parent(jackie_bouvier, patty_bouvier).

%%%%%%%

%Rules:

father(Father, Child) :-
    parent(Father, Child),
    male(Father).

mother(Mother, Child) :-
    parent(Mother, Child),
    female(Mother).

married(Father, Mother) :-
    % repeated results
    parent(Father, Child),
    parent(Mother, Child),
    dif(Father, Mother).

son(Child, Parent) :-
    parent(Parent, Child),
    male(Child).

daughter(Child, Parent) :-
    parent(Parent, Child),
    female(Child).

sibling(Sibling, Child) :-
    % repeated results
    parent(Parent, Sibling),
    parent(Parent, Child),
    dif(Sibling, Child).

brother(Brother, Sibling) :-
    % repeated results
    parent(Parent, Brother),
    parent(Parent, Sibling),
    male(Brother),
    dif(Brother, Sibling).

sister(Sister, Sibling) :-
    % repeated results
    parent(Parent, Sister),
    parent(Parent, Sibling),
    female(Sister),
    dif(Sister, Sibling).

uncle(Uncle, Child) :-
    parent(Parent, Uncle),
    parent(Parent, Sibling),
    parent(Sibling, Child),
    male(Uncle).

aunt(Aunt, Child) :-
    parent(Parent, Aunt),
    parent(Parent, Sibling),
    parent(Sibling, Child),
    female(Aunt).

