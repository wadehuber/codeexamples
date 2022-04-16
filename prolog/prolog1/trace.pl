imperative(c).
imperative(pascal).
objectoriented(cplusplus).
objectoriented(java).
objectoriented(csharp).
objectoriented(python).
functional(scheme).
functional(haskell).
functional(cplusplus).
functional(python).
declarative(prolog).
declarative(sql).

official_language(c).
official_language(java).
official_language(cplusplus).

project_language(X) :- official_language(X), objectoriented(X), functional(X).
