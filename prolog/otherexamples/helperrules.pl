% =============================================================================
% Helper predicates for positive-number counting, student pass/fail checks,
% and username validation.
% =============================================================================

%% positive(+N)
%  Succeeds if N is a number strictly greater than zero.
positive(N) :-
    N > 0.

%% count_positive(+List, -Count)
%  Count is the number of strictly positive elements in List.
%  Works with both empty and non-empty lists.
count_positive([], 0).
count_positive([H|T], Count) :-
    positive(H),
    count_positive(T, Rest),
    Count is Rest + 1.
count_positive([H|T], Count) :-
    \+ positive(H),
    count_positive(T, Count).

%% passed(+Student)
%  Succeeds when the student meets all pass criteria:
%    - score >= 70
%    - assignments completed >= 8
%    - no academic hold
%  Expects the following facts to be defined for each Student:
%    score(Student, Score).
%    assignments(Student, A).
%    academic_hold(Student).   % present only when the student has a hold
passed(Student) :-
    score(Student, Score), Score >= 70,
    assignments(Student, A), A >= 8,
    \+ academic_hold(Student).

%% passing_students(+Students, -Passed)
%  Passed is the sub-list of Students that satisfy passed/1,
%  preserving the original order.
passing_students([], []).
passing_students([S|Rest], [S|Passed]) :-
    passed(S),
    passing_students(Rest, Passed).
passing_students([S|Rest], Passed) :-
    \+ passed(S),
    passing_students(Rest, Passed).

%% valid_username(+Name)
%  Succeeds when Name (a list of character codes) is a valid username:
%    - length between 3 and 16 (inclusive)
%    - contains only alphanumeric characters
%    - does not start with a digit
valid_username(Name) :-
    length(Name, Len),
    Len >= 3, Len =< 16,
    alphanumeric_list(Name),
    Name = [First|_],
    \+ is_digit_code(First).

%% alphanumeric_list(+List)
%  Succeeds if every element of List is an alphanumeric character code.
alphanumeric_list([]).
alphanumeric_list([C|Cs]) :-
    alphanumeric_code(C),
    alphanumeric_list(Cs).

%% alphanumeric_code(+C)
%  Succeeds if C is the character code of a letter or digit.
alphanumeric_code(C) :- (C >= 65, C =< 90).   % A-Z
alphanumeric_code(C) :- (C >= 97, C =< 122).  % a-z
alphanumeric_code(C) :- (C >= 48, C =< 57).   % 0-9

%% is_digit_code(+C)
%  Succeeds if C is the character code of a digit.
is_digit_code(C) :-
    C >= 48, C =< 57.

%% filter_valid_usernames(+Names, -Valid)
%  Valid is the sub-list of Names that satisfy valid_username/1,
%  preserving the original order.
filter_valid_usernames([], []).
filter_valid_usernames([N|Rest], [N|Valid]) :-
    valid_username(N),
    filter_valid_usernames(Rest, Valid).
filter_valid_usernames([N|Rest], Valid) :-
    \+ valid_username(N),
    filter_valid_usernames(Rest, Valid).
% =============================================================================
% Sample data for the student-related predicates
% =============================================================================

score(alice, 85).
score(bob, 62).
score(carol, 78).
score(dave, 91).

assignments(alice, 10).
assignments(bob, 9).
assignments(carol, 7).
assignments(dave, 12).

% no academic_hold(alice).
academic_hold(dave).

% =============================================================================
% Test cases (portable version - no format/2)
% =============================================================================

%% run_tests
%  Executes a battery of tests and prints the results.
%  Succeeds only if every test passes.
run_tests :-
    nl, write('=== Running tests ==='), nl, nl,

    % --- positive/1 ---
    test('positive(5)',           positive(5)),
    test('\\+ positive(0)',       \+ positive(0)),
    test('\\+ positive(-3)',      \+ positive(-3)),

    % --- count_positive/2 ---
    test('count_positive([], 0)',                 count_positive([], 0)),
    test('count_positive([1,2,3], 3)',            count_positive([1,2,3], 3)),
    test('count_positive([-1,0,5,12,-3], 2)',     count_positive([-1,0,5,12,-3], 2)),
    test('count_positive([0,-5,-10], 0)',         count_positive([0,-5,-10], 0)),

    % --- passed/1 ---
    test('passed(alice)',         passed(alice)),
    test('\\+ passed(bob)',       \+ passed(bob)),
    test('\\+ passed(carol)',     \+ passed(carol)),
    test('\\+ passed(dave)',      \+ passed(dave)),

    % --- passing_students/2 ---
    test('passing_students([alice,bob,carol,dave], [alice])',
         passing_students([alice,bob,carol,dave], [alice])),
    test('passing_students([], [])',
         passing_students([], [])),

    % --- valid_username/1 ---
    test('valid_username("alice")',          valid_username("alice")),
    test('valid_username("Bob123")',         valid_username("Bob123")),
    test('\\+ valid_username("1start")',     \+ valid_username("1start")),
    test('\\+ valid_username("ab")',         \+ valid_username("ab")),
    test('\\+ valid_username("thisIsWayTooLongUsername")',
         \+ valid_username("thisIsWayTooLongUsername")),
    test('\\+ valid_username("valid_user")', \+ valid_username("valid_user")),

    % --- filter_valid_usernames/2 ---
    test('filter_valid_usernames(["alice","Bob123","1start","ab","thisIsWayTooLongUsername","valid_user"], ["alice","Bob123"])',
         filter_valid_usernames(
             ["alice","Bob123","1start","ab","thisIsWayTooLongUsername","valid_user"],
             ["alice","Bob123"])),

    nl, write('=== All tests passed ==='), nl.

%% test(+Description, +Goal)
%  Runs Goal and prints a PASS/FAIL message.
%  Fails the whole run_tests/0 if Goal fails.
test(Description, Goal) :-
    call(Goal),
    write('PASS: '), write(Description), nl.
test(Description, Goal) :-
    \+ call(Goal),
    write('FAIL: '), write(Description), nl,
    fail.