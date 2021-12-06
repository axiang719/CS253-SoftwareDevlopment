 #include <iostream>
 #include <cctype>
 #include <string>
 using namespace std;

 string program_name; 

bool start_with(const string &target, const string &prefix){
    for(size_t i = 0; i < prefix.size(); i++)
       if(tolower(target[i]) !=  tolower(prefix[i]))
         return false;
  return true;

}
void skip_White_Comments(string &input) {
  cout<<input << '\n';
   while(!input.empty())
     if(isspace(input[0]))
       input.erase(0,1);
     else if(input[0] == '#')
       input.clear();
     
     else
       break;
       }
 bool get_token(string &input, string &sym){
   static const string tokens[] = { "+=", "-=", "*=", "/=", "=", "!=", "<=", ">=",
         "<", ">", "if", "fi", "print", "return" , "a", "b", "c", "d", "e", 
          "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
          "s", "t", "u", "v", "w", "x", "y", "z"
   };
     skip_White_Comments(input);
     if(input.empty())
       return false;
     
     size_t len = 0;

     while(isdigit(input[len]))
           len ++;
    
  if(!len)
      for(string tok : tokens)
          if(start_with(input, tok)){
            len = tok.size();
             break;
        }
      
    

  if(!len){
   cerr << program_name << " :invalid input " << input<< "\n";
   exit(1);

  }
  sym.assign(input, 0, len);
  input.erase(0,len);
  for(char &c : sym)
       c = tolower(c);     
  return true;
  
 
}

void analyze(string &input) {
 for(string token; get_token(input, token);)
   cout << token << '\n';
   

}
void analyze(istream &in){
   for(string line; getline(in, line);)
      analyze(line);
 }


 
 int main(int, char *argv[]){
   program_name = argv[0];
   analyze(cin);
   return 0;

 }
