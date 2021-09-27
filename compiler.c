#include <stdio.h>

main() {
   FILE *fp;

   fp = fopen("mad360.txt", "r");
   fprint(fp);
   fclose(fp);
}