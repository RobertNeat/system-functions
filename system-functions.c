#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//using namespace std;
int main(int argc, char** argv){
    int pid=fork();
    
    if(pid!=0 && pid>0){
    printf("System() function runs echo command.\n");
    system("echo I will sleep for a while.");
    
    execlp("sleep","sleep","10",NULL);
    printf("System() function calling echo command ended.\n");
    }

    if(pid==0){
        printf("Execlp() function calls echo command.\n");
        execlp("/bin/echo","echo","I will sleep for a while.",NULL);

        system("sleep 10");
        
        printf("Execlp() function calling echo ended.\n");
    //perror("execlp");
    exit(0);
    }
    
    return 0;
}