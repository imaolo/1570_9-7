#include <stdio.h>
#include <string.h>

void removeSpaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int main(int argc, char* argv[])
{
    FILE* file = fopen("asm.txt", "r"); /* should check the result */
    char lines[100][256];
    int num_lines = 0;
    while (fgets(lines[num_lines], sizeof(lines[num_lines]), file))
        num_lines++;
    // printf("%d\n",num_lines);
    // for (int i=0;i<num_lines;i++)
    //     printf("%s",lines[i]);
    
    
    char *parsedData[num_lines][4];
    int lineSize[num_lines];
    char *token;
    for (int i=0;i<num_lines;i++){
        token = strtok(lines[i]," ");
        int tmp = 0;
        while (token != NULL){
            parsedData[i][tmp] = token;
            removeSpaces(parsedData[i][tmp]);
            token = strtok(NULL, " ");
            tmp++;
        }
        lineSize[i] = tmp;  
    }


    printf("=============================================\n");
    for (int i=0;i<num_lines;i++){
        for (int j=0;j<lineSize[i];j++)
            printf("%s",parsedData[i][j]);
    }






    // for (int i = 0;i<num_lines;i++){
    //     for (int j=0;j<lineSize[i];j++){}
    //         //printf("%s ",parsedData[i][j]);
    // }
    fclose(file);
    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
//https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c