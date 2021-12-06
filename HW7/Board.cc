#include "Board.h"

using namespace std;

Board::Board(const string &f, Rule r, char l, char d) : filename(f),rule(r), alive(l), dead(d) {
  
      
      string file; 
      ifstream myfile(f);
 
//--------------------------------------------------- check if file exist   
   if(!myfile){
    string s;
    
    string error_message = "Bad file";
    throw runtime_error(error_message);
   }
//-------------------------------------------------- gets chars and store it in vector a
  while(getline(myfile, file)){
     vector<char> a; 
     
     for(size_t k = 0; k < file.size(); k++){
//------------------------------------------------- check for invalid chars   
     if( file[k] != l && file[k] != d){
  
          
         string error_message = "Bad token:"s + "\'" + file[k]+ "\'\n" + "bad token found in file: "s +"\"" +filename +  "\"";
   throw runtime_error(error_message);
     
     }
      a.push_back(file[k]);
        }
     
     board.push_back(a);
     }
         for(size_t j = 0 ; j < board.size(); j++){
//---------------------------------------------------- check for grid that is at least 2x2         
        if(board[j].size() < 2 || board.size() < 2){
           string error_message = "Error: grid must be at least 2x2\n "s + "error occured in file: "s + "\"" +filename + "\"";
           throw runtime_error(error_message);
              }
//---------------------------------------------------- check for correct line length         
       for(size_t m = 0 ; m < board.size(); m++){
      
         if(board[j].size() != board[m].size()){
          string error_message = "Error: line length is inconsistent\n"s + "error occured in file: "s + "\"" +filename + "\"";
          throw runtime_error(error_message);
        }
       
       }
     }
 
}

Board::Board(const string &f, char l, char d, Rule r) : Board(f, r, l, d) {}

Board::Board(const string &f, char l, char d) : Board(f, Rule (), l, d){}

Board::Board(const string &f, Rule r) : Board (f, r, 'O', '.'){}

Board::Board(const string &f) : Board(f, Rule (), 'O', '.'){}
 
 Board & Board::operator++(){
  vector<vector<char>> board2 = board;
  for(int i = 0; i <  static_cast<int> (board2.size() ); i++){ // loops through rows
  for(int j = 0; j <  static_cast<int> (board2[i].size()); j++){ // loops through cols
  bool nw = false;
  bool n = false;
  bool ne = false;
  bool w = false;
  bool me = false;
  bool e = false;
  bool sw = false;
  bool s = false;
  bool se = false;
  
  
 
 
  int boundedJ = j + 1; // right
  int boundedI = i +1; //down
  int jNeg = j - 1;    // left
  int iNeg = i - 1;    // up 
 
  if(iNeg < 0){
    iNeg =  static_cast<int> (board2.size()-1 ); 
  }
 
  if(jNeg < 0){
     jNeg =  static_cast<int> (board2[i].size()-1 );
  }
 
  if(boundedI  > static_cast<int> (board2.size()-1 )){
    boundedI = 0; 
  }
 
  if(boundedJ >  static_cast<int> (board2[i].size()-1 )){
     boundedJ = 0;
 
  }
 
  if(board2[i][jNeg] == alive){
     w = true;
  	
  }
  
  if(board2[boundedI][boundedJ] == alive){
     se = true;
  	
  }
  
  if(board2[i][boundedJ] == alive){
     e = true;
  
  }
  
  if(board2[iNeg][j] == alive){
    n = true;
  
  }
  
  if(board2[boundedI][j] == alive){
    s = true;
  	
  }
  
  if(board2[iNeg][boundedJ] == alive){
    ne = true;
  	
  
  }
  
  if(board2[boundedI][jNeg] == alive){
    sw = true;
  	
    
  }
  
  if(board2[iNeg][jNeg] == alive){
    nw = true; 
  	
  }
  if(board2[i][j] == alive){
    me = true;
  
  }


 
  bool rules = rule.eval(nw,n,ne, w, me, e, sw, s, se);

   if(rules == true){
     board[i][j] = alive;
   }
   if(rules == false){
     board[i][j] = dead;
   }
}
  }
  return *this;
 }
ostream &operator << (ostream  &stream, const Board &b){
     
  for(size_t i = 0; i < b.board.size(); i++){
  for(size_t j = 0; j < b.board[i].size(); j++){
   stream << b.board[i][j];
   }
   stream<<'\n';
  }
  return stream;
}
