#include <stdio.h>
#include <string.h>

void removeSpaces(char *str1)  
{
    char *str2; 
    str2=str1;  
    while (*str2==' ') str2++;  
    if (str2!=str1) memmove(str1,str2,strlen(str2)+1);  
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
            removeSpaces(parsedData[i][tmp])
            token = strtok(NULL, " ");
            tmp++;
        }
        lineSize[i] = tmp;  
    }

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