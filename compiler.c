#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen("mad360.txt", "r"); /* should check the result */
    char lines[100][256];
    int num_lines = 0;
    while (fgets(lines[num_lines], sizeof(lines[num_lines]), file))
        num_lines++;
    
    
    char *parsedData[num_lines+2][3];
    char *token;
    for (int i=0;i<num_lines;i++){
        token = strtok(lines[i]," ");
        int tmp = 0;
        while (token != NULL){
            parsedData[i][tmp] = token;
            token = strtok(NULL, " ");
            tmp++;
        }
    }
    for (int i = 0;i<num_lines;i++){
        printf("%s",parsedData[i][0]);
        printf("%s",parsedData[i][1]);
        printf("%s",parsedData[i][2]);
        printf("\n");
    }

    fclose(file);

    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
//https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c