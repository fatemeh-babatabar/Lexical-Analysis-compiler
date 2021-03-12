# tokenizers

The program reads a file containing the programming code in the Tslang language and prints its tokens .

example :

   input :
   
       num main(){
           num a ;
           num b ;
           a = b + 9 ;
           return 0 ;
       }
    
   output :
       
       num
       main
       (
       )
       {
       num
       a
       ;
       num 
       b
       ;
       a
       =
       b
       +
       9
       return 
       0
       ;
       }
