#ifndef JAIL_H_INCLUDE
#define JAIL_H_INCLUDE
#include <string>       // for use of strings 
#include <cctype>
#include <vector>       // for lex vector
#include <iostream>
#include <algorithm> 
#include "Lexan.h"


class Jail{
public:
Jail() = delete;
Jail(const Jail&) = default;
Jail &operator= (const Jail&) = default;
~Jail () = default;

Jail(const std::string&);
long run(long = 0, long = 0, long = 0, long = 0, long  = 0, long = 0, long = 0, long = 0, long = 0, long = 0) const;
private:
Lexan lexObj;


};
#endif /* JAIL_H_INCLUDE */
