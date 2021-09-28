#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen("mad360.txt", "r"); /* should check the result */
    if (file == NULL){
        printf("uh oh\n");
    }
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);

    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c