#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
#include <fstream>
using namespace std;


  string program_name;


 
 void nextGen(vector< vector <char>> &ch){
  
  const char ALIVE = 'O';
  const char DEAD = '.'; 
  for(int i = 0; i <  static_cast<int> (ch.size() ); i++){ // loops through rows
  for(int j = 0; j <  static_cast<int> (ch[i].size()); j++){ // loops through cols
   int count = 0;
 
 
  int boundedJ = j + 1;
  int boundedI = i +1;
  int jNeg = j - 1; 
  int  iNeg = i - 1; 
 
  if(iNeg < 0){
    iNeg =  static_cast<int> (ch.size()-1 ); 
  }
 
  if(jNeg < 0){
     jNeg =  static_cast<int> (ch[i].size()-1 );
  }
 
  if(boundedI  > static_cast<int> (ch.size()-1 )){
    boundedI = 0; 
  }
 
  if(boundedJ >  static_cast<int> (ch[i].size()-1 )){
     boundedJ = 0;
 
  }
 
  if(ch[i][jNeg] == ALIVE){
  	count ++;
  }
  
  if(ch[boundedI][boundedJ] == ALIVE){

  	count ++;
  }
  
  if(ch[i][boundedJ] == ALIVE){

  	count ++;
  }
  
  if(ch[iNeg][j] == ALIVE){
  	count ++;
  }
  
  if(ch[boundedI][j] == ALIVE){
  	count ++;
  }
  
  if(ch[iNeg][boundedJ] == ALIVE){

  	count ++;
  
  }
  
  if(ch[boundedI][jNeg] == ALIVE){
  	count ++;
    
  }
  
  if(ch[iNeg][jNeg] == ALIVE){
  	count ++;
  }
 
  if(ch[i][j]==DEAD && count == 3){
  	cout << ALIVE;
  } 
  

  
  else  if((ch[i][j] == ALIVE) && (count == 3 || count == 2)){
   	 cout<< ALIVE;
    }
  
  
  
  else{
   	cout << DEAD;
  
  }
  
     }
     cout<< '\n';
   }
 
 }
 
 
  
 int main (int argc, char *argv[]){
 
     program_name = argv[0];
     vector< vector <char>> ch;
//--------------------------------------------------- reads from file 
  if(argc == 2){
      string file; 
      ifstream myfile(argv[1]);
//--------------------------------------------------- check if file exist   
   if(!myfile){
     
    cerr<< program_name << " " << argv[1] << " " << ":Bad file or file does not exist" << '\n'; 
    return 1; 
   }
//-------------------------------------------------- gets chars and store it in vector a
  while(getline(myfile, file)){
     vector<char> a; 
     
     for(size_t k = 0; k < file.size(); k++){
//------------------------------------------------- check for invalid chars   
     if( file[k] != 'O' && file[k] != '.'){
      cerr << program_name << " " << argv[1] << " " << "Bad character" << '\n';
      return 1; 
     
     }
      a.push_back(file[k]);
        }
     
     ch.push_back(a);
     }
  }
    
//--------------------------------------------------- reads from standard input     
 else{
      string line;
      while(getline(cin ,line)){
        vector<char> b; 
        for(size_t i = 0; i < line.size(); i++){
// ------------------------------------------------- check for vaild characters
           if(line[i] != 'O' && line[i] !=  '.' ){
              cerr << program_name  << " " << "Bad character" << '\n';
                      return 1;
                 }
 //--------------------------------------------------- if is vaild charater add to vector    
            b.push_back(line[i]);
           }
            ch.push_back(b);
         }
       }
       
     for(size_t j = 0 ; j < ch.size(); j++){
//---------------------------------------------------- check for grid that is at least 2x2         
        if(ch[j].size() < 2 || ch.size() < 2){
         cerr << program_name  << " " << "Grid size is less than 2x2" << '\n';
          return 1; 
              }
//---------------------------------------------------- check for correct line length         
       for(size_t m = 0 ; m < ch.size(); m++){
      
         if(ch[j].size() != ch[m].size()){
         cerr << program_name << " " << "Line length is inconsistent" << '\n';
         return 1;
        }
       
       }
     }
      nextGen(ch);
     
           }
  
