#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen("mad360.txt", "r"); /* should check the result */
    char lines[100][256];
    int num_lines = 0;
    while (fgets(lines[num_lines], sizeof(lines[num_lines]), file))
        num_lines++;

    char *tmp; 
    for (int i=0;i<num_lines;i++){
        tmp = strtok(lines[i]," ");
        for (int j=0;j<3;j++){
            printf("%s\n",tmp[j]);
        }
    }

    fclose(file);

    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
//