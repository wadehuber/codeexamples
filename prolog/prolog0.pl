% Comments start with a %
% Statements end with a .
% Variables start with an upper case
% Atoms start with a lower case

% Facts
% stock(Symbol, CompanyName, Price).
stock(etp,'Energy Transfer Partners, L.P.', 15.93).
stock(jpm,'JPMorgan Chase &amp; Co.', 107.52).
stock(bab,'Alibaba Group Holding Limited', 175.15).
stock(kmi,'Kinder Morgan, Inc.', 14.75).
stock(avgo,'Broadcom Limited', 228.28).
stock(feye,'FireEye, Inc.', 16.80).
stock(sep,'Spectra Energy Partners, LP', 32.72).
stock(ddd,'3D Systems 0', 11.082).
stock(ihrt,'iHeartMedia, Inc.', 0.52).
stock(sjm,'The J. M. Smucker Company', 119.81).

% Rules
price(Symbol, Price) :- stock(Symbol, _Name, Price).
name(Symbol, Name) :- stock(Symbol, Name, _Price).
