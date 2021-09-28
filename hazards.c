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

    char *Rd;
    char *Rs1;
    char *Rs2; 
    char *Rd_p;
    char *Rs1_p;
    char *Rs2_p; 
    if (parsedData[0][0][0] == 'B')
        printf("Control Hazard at line %d\n",0);
    for (int i=1;i<num_lines;i++){
        if (lineSize[i] >= 3 && lineSize[i-1] >= 3){
            Rd = parsedData[i][1];
            Rd_p = parsedData[i-1][1];
            Rs1 = parsedData[i][2];
            Rs1_p = parsedData[i][2];

            if ( strcmp(Rd,Rd_p) == 0)
                printf("WAW hazard at line %d\n",i);
            if (parsedData[i][0][0] == 'B')
                printf("Control Hazard at line %d\n",i);
        }   
    }




    fclose(file);
    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
//https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c
//https://stackoverflow.com/questions/1726302/remove-spaces-from-a-string-in-c