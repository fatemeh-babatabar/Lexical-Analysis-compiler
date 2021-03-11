#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;
///file
ifstream myfile;

/// is_identifier_char
bool is_identifier_char(char ch){
    int asci = (int)ch;
    if( (ch == '_') || (asci>=65 && asci<=90) || (asci>=97 && asci<=122) ){
        return true;
    }else{
        return false;
    }
}

char getcharr(){
    char c1;
    c1=myfile.get();
    return c1;
}

void ungetcharr(){
    myfile.unget();
}
///nextToken
string NextToken(){
    char c;
    if(myfile.good()){
       c=getcharr();
    }
    
    while( (c==' ' || c=='\n' || c=='\r') && myfile.good()){
        c=getcharr();
    }
    
    /// comments
    if(c=='#'){
        string g;
        getline(myfile,g);
        if(myfile.good()){
            c=getcharr();
        }else{
            return "";
        }
    }
    ////////////////

    ///// comments /////////////////
    /*if(c=='/'){
      if(myfile.good()){  

        c=getcharr();

        if(c!='/' && c!='*'){

            ungetcharr();
            ungetcharr();
            c=getcharr();

        }else if(c=='/'){

            string g;
            getline(myfile,g);
            if(myfile.good()){
                c=getcharr();
            }else{
                return "";
            }

        }else if(c=='*'){
    
            if(myfile.good()){
                c=getcharr();
            }else{
                return "";
            }
            

            while(c!='*' && myfile.good()){    
                 c=getcharr();
            }  
            bool k=false;
            while(!k){
                if(c=='*'){
                    if(myfile.good()){
                        c=getcharr();
                    }
                    if(c=='/'){
                        k=true;
                        return "";   
                    }
                }else{
                    if(myfile.good()){
                        c=getcharr();
                    }else{
                        return "";
                    }
                }
            }
        }
        
      }
    }*/
    //////////////////////////////////////////////////////
    
    if(c==';'){
        return ";";
    }else if(c==','){
        return ",";
    }else if(c=='('){
        return "(";
    }else if(c==')'){
        return ")";
    }else if(c=='{'){
        return "{";
    }else if(c=='}'){
        return "}";
    }else if(c=='['){
        return "[";
    }else if(c==']'){
        return "]";
    }else if(c=='|'){
        if(myfile.good()){
            c=getcharr();
            if(c=='|'){
                return "||";
            }
        }    
        return "";
    }else if(c=='&'){
        if(myfile.good()){
            c=getcharr();
            if(c=='&'){
                return "&&";
            }
        }
        return "";
    }else if(c=='!'){
        if(myfile.good()){
            c=getcharr();
            if(c=='='){
                return "!=";
            }
        }    
        ungetcharr();
        return "!";
    }else if(c=='<'){
        if(myfile.good()){
            c=getcharr();
            if(c=='='){
                return "<=";
            }
        }
        ungetcharr();
        return "<";
    }
    else if(c=='>'){
        if(myfile.good()){
            c=getcharr();
            if(c=='='){
                return ">=";
            }
        }    
        ungetcharr();
        return ">";
    }else if(c=='='){
        if(myfile.good()){
            c=getcharr();
            if(c=='='){
                return "==";
            }
        }    
        ungetcharr();
        return "=";    
    }else if(c=='+'){
        return "+";    
    }else if(c=='-'){
        return "-";
    }else if(c=='*'){
        return "*";
    }else if(c=='/'){
        return "/";
    }else if(c=='%'){
        return "%";
    }else if(isdigit(c) && myfile.good()){        
        
        string tok="";
        tok += c;
        if(myfile.good()){    
            c=getcharr();
            while( (isdigit(c) || is_identifier_char(c) ) && myfile.good()){
                 tok += c;
                c=getcharr();
            }
            if(c=='.'){
                tok += c;
                if(myfile.good()){
                    c=getcharr();
                    while((isdigit(c) || is_identifier_char(c)) && myfile.good()){
                        tok += c;
                        c=getcharr();
                    }
                    ungetcharr();
                }    
            }else{
                 ungetcharr();
            }
        }
        return tok;
    }else if(is_identifier_char(c) && myfile.good()){
         
         string tok="";
         tok+=c;
         if(myfile.good()){ 
             c=getcharr();
             while((is_identifier_char(c)  ||  isdigit(c)) && myfile.good()){
                 tok+=c;
                 c=getcharr();
             } 
             ungetcharr();
         } 
         return tok;
    }

   return "";
}

void MFile(){
    
    string o;
    myfile.open("file.txt")   ;
       
    if(myfile.good()){
        o=NextToken();
        if(o!="" && o!=" " && o!="\n" && o!="\r"){
          cout << o ;
        }
    }   
    while(myfile.good()){
        o = NextToken();
        if(o!="" && o!=" " && o!="\n" && o!="\r"){
          cout <<"\n"<< o ;
        }
        
    }
     
    myfile.close();
}

int main(){

    MFile();

    return 0;
}