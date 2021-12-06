#include "Jail.h"
using namespace std;

Jail::Jail(const string &input) : lexObj(Lexan(input)){}

long Jail::run(long a, long b, long c, long d, long e, long f, long g, long h, long i, long j) const
{
  

    vector<long> number = {a, b, c, d, e, f, g, h, i, j, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t counter = 0;
    bool skipFi = false;
                                                                                   
    while (lexObj.size() > counter)
    {
           
  
      
      
        char letterCheck = lexObj[counter][0];
//------------------------------------------------------------------------- looks for "if" in the fucking Lexan object
        if (lexObj[counter] == "if")
        {
            
             if(lexObj[counter + 1] == "print" || lexObj[counter + 1] == "return"){
                 string error_message = "invaild if: " + lexObj[counter+1];
                 throw runtime_error(error_message);
             }
              
               if((lexObj[counter + 2] != "=") && (lexObj[counter + 2] != "≠") && (lexObj[counter + 2] != "<") &&  (lexObj[counter + 2] != ">") && (lexObj[counter + 2] != "≤") && (lexObj[counter + 2] != " ≥") ){
                string error_message = "invaild input in if : " + lexObj[counter+2];
                throw runtime_error(error_message);
             }
             
            
            long right = 0;
            long left = 0;
            if (isalpha(lexObj[counter + 1][0]))   // checks the next index of lexObj is a letter 
            {
                left = number[lexObj[counter + 1][0] - 'a'];   // formula to check left index  
            }
            else
            {

                stringstream stringToDigit(lexObj[counter + 1]);   

                stringToDigit >> left;  
            }
            if (isalpha(lexObj[counter + 3][0]))
            {
                right = number[lexObj[counter + 3][0] - 'a'];
            }
            else
            {

                stringstream stringToDigit(lexObj[counter + 3]);

                stringToDigit >> right;
            }
                 
            if (lexObj[counter + 2] == "=")
            {      
                skipFi = !(left  == right);
            }
            if (lexObj[counter + 2] == "≠")
            {
                skipFi = !(left != right);
            }
            if (lexObj[counter + 2] == "<")
            {
                skipFi = !(left < right);
            }
            if (lexObj[counter + 2] == ">")
            {
                skipFi = !(left < right);
            }
            if (lexObj[counter + 2] == "≤")
            {   
                skipFi = !(left <= right);
            }
            if (lexObj[counter + 2] == " ≥")
            {
                skipFi = !(left >= right);
            }
           
            counter += 4;
            
        }
//---------------------------------------------------------------- increasing counter based on cases, also to check if skipFi boolean is activated
        else if (lexObj[counter] == "fi")
        {
            counter++;
            skipFi = false;
        }
        else if (skipFi == true)
        {
            if(lexObj[counter] == "if"){
                counter += 4;
            }
            else if(lexObj[counter]== "fi"){
                counter ++;
            }
            else if(lexObj[counter] == "print" || lexObj[counter] == "return"){
                counter +=2;
            }
            else{
                counter += 3; 
            }
            continue;
        }

        else if (lexObj[counter] == "return" || lexObj[counter] == "print")
        {
            if(lexObj[counter+1] == "if"){
                string error_message = "invalid input " + lexObj[counter]+ " " + lexObj[counter+1];
                throw runtime_error(error_message);
            }
            if (lexObj[counter] == "print")
            {
                if (isalpha(lexObj[counter + 1][0]))
                {
                    int indexPrint = lexObj[counter + 1][0] - 'a';
                    cout << number[indexPrint] << '\n';
                }

                else
                {
                    cout << lexObj[counter + 1];
                }
            }

            if (lexObj[counter] == "return")
            {

                if (isalpha(lexObj[counter + 1][0]))
                {
                    int indexReturn = lexObj[counter + 1][0] - 'a';
                    return number[indexReturn];
                }
                else if (isdigit(lexObj[counter + 1][0]))
                {
                    long convert = stol(lexObj[counter + 1]);
                    return convert;
                }
            }

            counter += 2;
        }

        else if (isalpha(letterCheck))
        {
          
            long digit = 0;
            int index = letterCheck - 'a';
    
            if (isalpha(lexObj[counter + 2][0]))
            {
                digit = number[lexObj[counter + 2][0] - 'a'];
            }
            else
            {

                stringstream stringToDigit(lexObj[counter + 2]);

                stringToDigit >> digit;
            }

            if (lexObj[counter + 1] == "=")
            {
            -
                number[index] = digit;
            }
            if (lexObj[counter + 1] == "+=")
            {
                number[index] += digit;
            }
            if (lexObj[counter + 1] == "-=")
            {
                number[index] -= digit;
            }
            if (lexObj[counter + 1] == "*=")
            {
                number[index] *= digit;
            }
            if (lexObj[counter + 1] == "/=")
            { 
                if(digit != 0){
                number[index] /= digit;
                }
                else{
                    throw runtime_error("cannot divide by 0");
                }
            }


            counter += 3;
        }
      
    }
    return 0;
}
