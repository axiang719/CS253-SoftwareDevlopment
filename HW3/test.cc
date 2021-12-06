#include "Lexan.h"
#include "Lexan.h"     
#include <iostream>
 
using namespace std;
 
int main() {
    const auto prog = R"(
               n  = a n += b C/=123 #d z=zz
 
        ifn≤≠≥3returN1FI)";
 
    const Lexan lex(prog);
     string a = (" a +=#hi\nb ");
    //  Lexan lex2(a);
    //  cout << lex2.size();
// try{      string l = "a+=b";
// Lexan lex2(l);

// cout<< lex2[5];
// }
// catch (const exception &e) {
//     cout << "exception: " << e.what() << '\n';
// }
    for (size_t i=0; i<lex.size(); i++)
        cout << lex[i] << '\n';
    cout << lex << '\n';
    return 0;
}
