#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen("mad360.txt", "r"); /* should check the result */
    char lines[100][256];
    int num_lines = 0;
    // while (fgets(lines[num_lines], sizeof(lines[num_lines]), file))
    //     num_lines++;
    while (fscanf(file,"%s",lines[num_lines]))
        num_lines++;
    printf("%d\n",num_lines);
    for (int i=0;i<num_lines;i++)
        printf("%s",lines[i]);
    
    
    
    char *parsedData[num_lines][3];
    int lineSize[num_lines];
    char *token;
    for (int i=0;i<num_lines;i++){
        token = strtok(lines[i]," ");
        int tmp = 0;
        while (token != NULL){
            parsedData[i][tmp] = token;
            //printf("%s",token);
            token = strtok(NULL, " ");
            tmp++;
        }
        lineSize[i] = tmp+1;
        //printf("%d\n",lineSize[i]);
    }






    for (int i = 0;i<num_lines;i++){
        for (int j=0;j<lineSize[i];j++){}
            //printf("%s ",parsedData[i][j]);
    }
    fclose(file);
    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
//https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c