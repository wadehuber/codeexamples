% Facts
marvel(ironman).
marvel(hulk).
marvel(blackpanther).
marvel(captainmarvel).
marvel(hawkeye).
marvel(gamora).
marvel(nickfury).
marvel(loki).
marvel(thar). % typo intended
marvel(scarletwitch).
marvel(captainamerica).
marvel(shangchi).
marvel(doctorstrange).

% Rule that generates a long list
marvel_characters(CharacterList) :- findall(Character, marvel(Character), CharacterList).