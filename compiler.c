#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen("mad360.txt", "r"); /* should check the result */



    char lines[100][256];



    int i = 0;
    while (fgets(lines[i], sizeof(lines[i]), file)) {
        i++;
    }
    for (int j=0;j<i;j++){
        printf("%s\n", lines[j])
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);

    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c