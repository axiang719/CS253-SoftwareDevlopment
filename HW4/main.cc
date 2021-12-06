#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
#include <fstream>
#include <unistd.h>

using namespace std;


  string program_name;


 
  vector<vector<char>> nextGen(vector< vector <char>> &ch, vector<int> &b, vector<int> &s, char &ALIVE, char &DEAD ){
     vector<vector<char>> newch = ch;

  for(int i = 0; i <  static_cast<int> (ch.size() ); i++){ // loops through rows
  for(int j = 0; j <  static_cast<int> (ch[i].size()); j++){ // loops through cols
    
   int count = 0;
 
 
  int boundedJ = j + 1;
  int boundedI = i +1;
  int jNeg = j - 1; 
  int iNeg = i - 1; 
 
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



  if(ch[i][j]==DEAD ){
    bool found = false;
  for(size_t a = 0; a < b.size(); a++){
          if(b[a] == count){
              found = true;
              newch[i][j] = ALIVE;
              cout<< ALIVE;
              break;
            }
 }
 if(!found){
   cout << DEAD;
 }
  } 
   else{
    bool found2 = false;
    for(size_t k = 0; k < s.size();k++){
    
    if(s[k] == count){
        found2 = true;
        cout<< ALIVE;
        break;
      }
     }
     if(!found2){
        newch[i][j] = DEAD;
   cout << DEAD;
 }
    }
       }
     cout<< '\n';
           }
          return  newch;
                 }
 
 
  
int main (int argc, char *argv[]){
      char ALIVE = 'O';
      char DEAD = '.'; 
      bool c = false;
      vector<int> s = {2,3};
     vector<int> b = {3};

     
     program_name = argv[0];
     vector< vector <char>> ch;
     char opt;
  while((opt = getopt(argc, argv, "+g:+l:+d:+i")) != -1){

   switch (opt)
    {
    case 'g':
    {
      s.clear();
      b.clear();
      
      string d = optarg;
       if(d[0] != 'B'){
           cerr << "first character after the argument flag must be a captital B "<< '\n';
            return 1;
         }
     for(size_t i = 0; i < d.size() ; i++ ){
    
      if(d[i] == '/'){
      
      if(d[i+1] != 'S'){
        cerr << "the charater after the / must be a captital S" << '\n';
        return 1;
      }
      
       for(size_t k = 1; k < i; k++){
       
        if(isdigit(d[k])){
          
         b.push_back(d[k] - '0');
         }
        else{
          cerr<< "needs to be a digits after B" << '\n';
           return 1;
        }
      }
       
     
      for(size_t j = i+2; j < d.size(); j++){
         
          if(isdigit(d[j])){
          
         s.push_back(d[j]-'0');
        }
        else{
           cerr<< "needs to be a digits after the S" << '\n';
           return 1;
        }
      }
      break;
       }
  
    
 
      
    }
 
    break;
    
    }    
        
     case 'l':
    {
        string a = optarg;
     
        ALIVE = a[0]; 
        break;
    }
    case 'd':
    {
        string d = optarg;
       
        DEAD = d[0];
        
       
        break;
    }
    case 'i':
    {
          c = true;
        break;
    }
    default:{
       
          return 1;
        break;
    }
    }
  }
    
  
  
  

//--------------------------------------------------- reads from file 
  if(argc == optind +1){
      string file; 
      ifstream myfile(argv[optind]);
//--------------------------------------------------- check if file exist   
   if(!myfile){
     
    cerr<< program_name << " " << argv[optind] << " " << ":Bad file or file does not exist" << '\n'; 
    return 1; 
   }
//-------------------------------------------------- gets chars and store it in vector a
  while(getline(myfile, file)){
     vector<char> a; 
     
     for(size_t k = 0; k < file.size(); k++){
//------------------------------------------------- check for invalid chars   
     if( file[k] != ALIVE && file[k] != DEAD){
      cerr << program_name << " " <<argv[optind] << " " << "Bad character" << '\n';
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
        vector<char> cha; 
        for(size_t i = 0; i < line.size(); i++){
// ------------------------------------------------- check for vaild characters
           if(line[i] != ALIVE && line[i] !=  DEAD ){
              cerr << program_name  << " " << "Bad character" << '\n';
                      return 1;
                 }
 //--------------------------------------------------- if is vaild charater add to vector    
            cha.push_back(line[i]);
           }
            ch.push_back(cha);
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
//----------------------------------------------------- checking to make sure that the numbers are in ascending oder for B  
    for(size_t alpha = 0; alpha < b.size()-1; alpha++){
       if(b[alpha] > b[alpha +1] || b[alpha] == b[alpha +1]){
        cerr << " B numbers must be strictly scending order or / is missing" << '\n';
        return 1;
      }
     
    }  
//---------------------------------------------------- checking to make sure that the numbers are in acending oder for S 
      for(size_t beta = 0; beta < s.size()-1; beta++){
       if(s[beta] > s[beta +1] || s[beta] == s[beta+1]){
        cerr << " S numbers must be strictly scending order" << '\n';
        return 1;
      }
     
    } 
    
      do{
        ch = nextGen(ch,b,s, ALIVE, DEAD);
       if(c== true){
          cout<<'\n';  
       }
      }
      while(c);
       
     
           }

  
