#include <stdio.h>
#include <string.h>

void removeSpaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ' || *d == '\t') {
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
    int tmp;
    for (int i=0;i<num_lines;i++){
        token = strtok(lines[i]," ");
        tmp = 0;
        while (token != NULL){
            parsedData[i][tmp] = token;
            removeSpaces(parsedData[i][tmp]);
            token = strtok(NULL, " ");
            tmp++;
        }
        lineSize[i] = tmp;  
    }




    fclose(file);
    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
//https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c
//https://stackoverflow.com/questions/1726302/remove-spaces-from-a-string-in-c