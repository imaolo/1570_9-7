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
        printf("Control Hazard at line %d\n",1);
    for (int i=1;i<num_lines;i++){
        if (i == 2){
            printf("%d\n",lineSize[i])
            printf("%d\n",lineSize[i-1])
        }
        if (lineSize[i] >= 3 && lineSize[i-1] >= 3){
            //check for control hazards
            if (parsedData[i][0][0] == 'B')
                printf("Line %d: Control hazard\n",i+1);

            //load register arguments
            Rs1 = parsedData[i][2];
            Rs1_p = parsedData[i-1][2];
            Rd = parsedData[i][1];
            Rd_p = parsedData[i-1][1];

            //check for WAW
            if ( strcmp(Rd,Rd_p) == 0)
                printf("Line %d: WAW hazard\n",i+1);

            //RS1 check hazards
            //check for WAR
            if (strcmp(Rs1_p,Rd) == 0)
                printf("Line %d: WAR hazard\n",i+1);
            //check for RAW
            if (strcmp(Rs1,Rd_p) == 0)
                printf("Line %d: RAW hazard\n",i+1);

            //check rs2
            if (lineSize[i] == 4 && lineSize[i-1] == 4){
                Rs2 = parsedData[i][3];
                Rs2_p = parsedData[i-1][3];
                //check for WAR
                if (strcmp(Rs2_p,Rd) == 0)
                    printf("Line %d: WAR hazard\n",i+1);
                //check for RAW
                if (strcmp(Rs2,Rd_p) == 0)
                    printf("Line %d: RAW hazard\n",i+1);
            }
            
        }   
    }

    fclose(file);
    return 0;
}



//https://stackoverflow.com/questions/9206091/going-through-a-text-file-line-by-line-in-c
//https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c
//https://stackoverflow.com/questions/1726302/remove-spaces-from-a-string-in-c





            // while(Rs1_p[0] != 'R')
            //     Rs1_p++;
            // tmp = 0;
            // while(Rs1_p[tmp] != '\0'){
            //     if (Rs1_p[tmp] == ')'){
            //         Rs1_p[tmp] = '\0';
            //         break;
            //     }
            //     tmp++;
            // }
            // while(Rs1[0] != 'R')
            //     Rs1++;
            // tmp = 0;
            // while(Rs1[tmp] != '\0'){
            //     if (Rs1[tmp] == ')'){
            //         Rs1[tmp] = '\0';
            //         break;
            //     }
            //     tmp++;
            // }