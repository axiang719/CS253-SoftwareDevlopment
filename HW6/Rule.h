#ifndef RULE_H_INCLUDE
#define RULE_H_INCLUDE

#include <string>
#include <vector>
#include <iostream>

 class Rule {
     public:
     Rule();
     Rule(const Rule&) = default;
     Rule &operator= (const Rule&)= default;
     ~Rule() = default;

    void conway();
    void golly(const std::string &);
    std::string golly();
    bool eval(bool, bool, bool, bool, bool, bool, bool, bool, bool);
    private:
    std::string rule;
    std::vector<int> B;
    std::vector<int> S;
    char alive = 'O';
    char dead = '.';
};
#endif /* RULE_H_INCLUDE */
