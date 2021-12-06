#include "Rule.h"
using namespace std;
 Rule::Rule(){
  conway();
 }
void Rule::conway(){
  golly("B3/S23");
  
}

void Rule::golly(const string &a ){

      S.clear();
      B.clear();
     
  
       if(a[0] != 'B'){
           throw runtime_error( "first character after the argument flag must be a captital B ");
            
         }
     for(size_t i = 0; i < a.size() ; i++ ){
    
      if(a[i] == '/'){
      
      if(a[i+1] != 'S'){

        throw runtime_error( "the charater after the / must be a captital S");
        
      }
      
       for(size_t k = 1; k < i; k++){
       
        if(isdigit(a[k])){
          
         B.push_back(a[k] - '0');
         }
        else{
          throw runtime_error( "needs to be a digits after B");
          
        }
      }
       
     
      for(size_t j = i+2; j < a.size(); j++){
         
          if(isdigit(a[j])){
          
         S.push_back(a[j]-'0');
        }
        else{
           throw runtime_error("needs to be a digits after the S");
           
        }
      }
    rule = a;
}
     }
     
}

string Rule::golly(){
  return rule;
}

bool Rule::eval(bool nw, bool n, bool ne, bool w, bool me, bool e, bool sw, bool s, bool se ){
 int counter = 0;
 
 if(nw == true){
     counter++;
 }
  if(n == true){
     counter++;
 }
  if(ne == true){
     counter++;
 }
  if(w == true){
     counter++;
 }
  if(e == true){
     counter++;
 }
  if(sw == true){
     counter++;
 }
  if(s == true){
     counter++;
 }
  if(se == true){
     counter++;
 }
 
 if(me == false ){
   
  for(size_t alpha = 0; alpha < B.size(); alpha++){
          if(B[alpha] == counter){
           
              return true;
              
    }
 }

   return false;
 
  }
 
   else{
    
    for(size_t kill = 0; kill < S.size();kill++){
       
      
    if(S[kill] == counter){
         
        return true;
       
      }
      
     }
    
      return false; 
 
 
    }
   
       }
     
 
