
#include "Lexan.h"

using namespace std;

Lexan::Lexan(const string &input)
{
  istringstream f(input);
  string line;

  while (getline(f, line))
  {                                                                             //loop to put the input string into line
    static const string tokens[] = {"+=", "-=", "*=", "/=", "=", "≠", "≤", "≥", // array of valid tokens
                                    "<", ">", "if", "fi", "print", "return",
                                    "a", "b", "c", "d", "e", "f", "g", "h", "i",
                                    "j", "k", "l", "m", "n", "o", "p", "q", "r",
                                    "s", "t", "u", "v", "w", "x", "y", "z"};
    while (!line.empty())
    {

      skip_White_Comments(line); // passed to skip_White_Commments fuction

      size_t len = 0; // no chars matched yet

      while (isdigit(line[len]))
      { // scan a number
        if (len > 15)
        { // checks to make sure digit length is less than 15. If more than 15, complain
          throw runtime_error("digit length is greater than 15");
        }
        len++;
      }

      if (!len)                   // number not found
        for (string tok : tokens) // look through tokens
          if (start_with(line, tok))
          {                   // a match
            len = tok.size(); // only length matters
            break;
          }

      if (line == "")
      { // if string contains a blank token, continue
   
    
        continue;
      }
  
    
      if (!len)
      { // if token is bad complain
      string badToken;
      char index = line[len];
      badToken.push_back(index);
      string error_message = "Invaild token: " + badToken;
      throw runtime_error(error_message);
      }
   

      string sym;
      sym.assign(line, 0, len);                                  // token is len bytes long
      line.erase(0, len);                                        // Remove token from input
      transform(sym.begin(), sym.end(), sym.begin(), ::tolower); // transform chars to string so it can be added to lex vector
      lex.push_back(sym);                                        // add element to vector from  sym
    }
  }
}

//------------------------------------------------------------ does target case-idependently start with prefix?
bool Lexan::start_with(const string &target, const string &prefix) const
{
  for (size_t i = 0; i < prefix.size(); i++)
    if (tolower(target[i]) != tolower(prefix[i]))
      return false;
  return true;
}

//----------------------------------------------------------- function to skip white spaces and comments
void Lexan::skip_White_Comments(string &input) const
{
  while (!input.empty())
  {
    if (isspace(input[0]))
      input.erase(0, 1);
    else if (input[0] == '#')
      input.clear();

    else
      break;
  }
}

//-------------------------------------------------- returns size
size_t Lexan::size() const
{
  return lex.size();
}

//-------------------------------------------------- see if it is empty
bool Lexan::empty() const
{
  return lex.empty();
}

//-------------------------------------------------- clears things
void Lexan::clear()
{
  lex.clear();
}

//-------------------------------------------------- function for checking if it is in range, if so return the nth index of lex vector
string Lexan::operator[](const size_t n) const
{
  if (n > lex.size() - 1)
  { // checking if n is greater than the size of the vector
    string error_message = "size given " + to_string(n) + " size of vector " + to_string(lex.size()) + " :out of bounds"s;
    throw out_of_range(error_message);
  }
  return lex[n];
}

//------------------------------------------------- function to loop through ostream and prining out tokens with comma
ostream &operator<<(ostream &b, const Lexan &l)
{
  for (size_t i = 0; i < l.size(); i++)
  {
    if (i == l.size() - 1)
    {
      b << l[i];
    }
    else
    {
      b << l[i] << ",";
    }
  }
  return b;
}
