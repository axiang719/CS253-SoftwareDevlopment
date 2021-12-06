#ifndef LEXAN_H_INCLUDE
#define LEXAN_H_INCLUDE
#include <string>       // for use of strings 
#include <vector>       // for lex vector
#include <iostream>
#include <sstream>     // for use of stringstream
#include <cctype>      // to be able to use tolower, isspace, isdigit, etc.
#include <algorithm>   // for transform

class Lexan{

public:

Lexan() =  delete;                                    // deleting default ctor
Lexan(const Lexan&) = default;                        // copy ctor
Lexan &operator= (const Lexan &) = default;           // assignment operator
~Lexan()= default;                                   // dtor

Lexan(const std::string&);                          // declaring ctor with const string ref. parameters
[[nodiscard]] size_t size() const ;                 // const size() method with nodiscard attribute
[[nodiscard]] bool empty() const;                    // const empty() method with nodiscard attribute
void clear();                                       // clear method
std::string operator[](const size_t) const;         // const [size_t n] method

private:

std::vector <std::string> lex;                      // declared a string vector to hold tokes of type string 
//---------------------------------------------------- use of HW1 functions 
void skip_White_Comments( std::string & ) const;
bool start_with(const std:: string &, const std::string &) const;
};

std::ostream &operator << (std::ostream &, const Lexan&);
#endif /* LEXAN_H_INCLUDE */
