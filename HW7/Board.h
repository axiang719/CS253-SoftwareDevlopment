#ifndef BOARD_H_INCLUDE
#define BOARD_H_INCLUDE
#include "Rule.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
 class Board {
     public:
     Board() = delete;
     Board(const Board&) = default;
     Board &operator= (const Board&)= default;
     ~Board() = default;
     Board &operator++();
     
     Board(const std::string&, const Rule, char , char );
     Board(const std::string&, char , char, const Rule );
     Board(const std::string&, char, char);
     Board(const std::string&, const Rule );
     Board(const std::string&);
     std::vector<std::vector<char>> board;
    private:
    std::string filename;
    Rule rule;
    char alive = 'O';
    char dead = '.';

  

};
std::ostream &operator << (std::ostream &, const Board&);
#endif /* BOARD_H_INCLUDE */
