# xp
eXperimental Parser -- I'll hand code a backtracking recursive descent parser to parse a variant of PEG. 

* After some research, see [the ees wiki](https://github.com/smartnuf/ees/wiki), I concluded that a backtracking RD parser was a likely candidate to be compact enough to squeese onto a small embedded system.
* The idea here is to learn about building parsers and parser generators.
  * To get a feel for how compact a parser can be.
  * How best to build an AST.
  * How to manage error reporting.
  * How best to arrange for different tools to be built for the same grammar.
* I'd also like to take the opportunity to see how we might reason about PEG grammars.
  * How do we determine if a PEG is ill-formed?
  * Can we suggest how to fix an ill-formed PEG?
  * Can we determine whether two different PEG grammars match the same languages or not (at least for important refactorings)?
  * Can we determine when the order of alternative choices alters the grammar for a given rule?
  * Can we generate test vectors to excersise the parser with good test coverage, and to give examples of the Language defined?
 
* A recursive decent backtracking parser I've built here (really only a recogniser at this point, as it emits no syntax tree, f.e.) for an extended PEG like grammar (for Waxeye) has a 2,500 byte footprint. Which is quite respectable.
