#include<stdio.h>

int main () {
   FILE *fp;
   char str[] = "a\0a";

   fp = fopen( "file.txt" , "w" );
   fwrite(str , 1 , 3 , fp );

   fclose(fp);
  
   return(0);
}