#include <stdio.h>

int main() {
   FILE *fp;

   fp = fopen("mad360.txt", "r");
   fprintf(fp);
   fclose(fp);
   return 0;
}