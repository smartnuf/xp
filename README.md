# xp
eXperimental Parser -- I'll hand code a backtracking recursive descent parser to parse a variant of PEG. 

* After some research, see [The ees wiki](https://github.com/smartnuf/ees/wiki), I concluded that a backtracking RD parser was a likely candidate to be compact enough to squeese onto a small embedded system.
* The idea here is to learn about building parsers and parser generators and to get a feel for how compact a parser can be.
 * How best to build an AST.
 * How best to arrange for different tools to be built for the same grammar.
* I'd like to take the opportunity to see how we might reason about PEG grammars.
 * Can we determine whether two different PEG grammars match the same languages or not (at least for important refactorings)?
 * Can we determine when the order of alternative choices alters the grammar for a given rule?

