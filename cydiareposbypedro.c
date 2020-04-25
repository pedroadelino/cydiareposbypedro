//Cydia Repos
//by Pedro Adelino
//Nara Logic 2020
//www.bypedro.eu

//Version
#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION 0.1
#define VERSION_REVISION 1
//#define VERSION STRINGIZE(VERSION_MAJOR) "." STRINGIZE(VERSION_MINOR)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>      /* needed to use pid_t, etc. */
#include <sys/wait.h>       /* needed to use wait() */  
//double app_version = VERSION;
const char *app_version = "0.2";
//int println;
int main(int argc, char **argv)
{

    //int ret;
	//println("Cydia Repos v." + app_version);
    printf("\033[1;34m"); // Blue color
    printf("Cydia Repos v%s\n", app_version);
	printf("By Pedro Adelino.\n");
    printf("www.bypedro.eu\n");
    //The following example searches for the location of the command
    //among the directories specified by the PATH environment variable.
    //ret = execlp("ls", "ls", "-l", (char *)NULL);
    
    int commandnr;
    int errors=0;
    FILE *file;

    for(commandnr=1;commandnr<=2;commandnr++){
    pid_t pid;

    pid = fork();
  
    if (pid < 0)
    {
        printf("\033[1;31m"); // Red color
        printf("A fork error has occurred. Please try again!\n");
        printf("\033[0m"); // Reset color
        exit(-1);
    }
    else 
    if (pid == 0) /* We are in the child. */
    {
        if (commandnr == 1){
            //Command1
            //printf("Command1\n");
            
            //printf("I am the child, about to call ls using execlp.\n");
            //char *command = ;

            if((file = fopen("/etc/apt/sources.list.d/cydiareposbypedro.list","r"))!=NULL)
            {
                // file exists
                fclose(file);
                //execlp("cp", "cp", "cydiareposbypedro.txt", "/etc/apt/sources.list.d/cydiareposbypedro.list" , "-v", "-i" , NULL);
                printf("\033[1;32m"); // Green color
                printf("No need to install!\n");
                printf("\033[0m"); // Reset color
            }
            else
            {
                //File not found, no memory leak since 'file' == NULL
                printf("\033[1;33m"); // Yellow color
                printf("Installing repos...\n");
                printf("\033[0m"); // Reset color
                file = fopen("/etc/apt/sources.list.d/cydiareposbypedro.list","w");
                fprintf(file, "deb http://apt.cydiakk.com/ ./\n");
                fprintf(file, "deb http://cydia.iphonecake.com/ ./\n");
                fprintf(file, "deb http://cydia.ichitaso.com/ ./\n");
                fprintf(file, "deb http://cydia.akemi.ai/ ./\n");
                fprintf(file, "deb http://cydia.angelxwind.net/ ./\n");
                fprintf(file, "deb http://cydia.oatmealdome.me/ ./\n");
                fprintf(file, "deb http://telaaedifex.com/repo/ ./\n");
                fprintf(file, "deb http://repo.hackyouriphone.org/ ./\n");
                fprintf(file, "deb http://apt.arx8x.net/ ./\n");
                fclose(file); //Save data to file
                printf("\033[1;32m"); // Green color
                printf("Repos installed.\n");
                printf("\033[0m"); // Reset color
                
            }



            
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            //printf("\033[1;31m"); // Red color
            //printf("Failed executing command 1.\n");
            //printf("\033[0m"); // Reset color
            //errors++;
            exit(127);
        }
        else
        if (commandnr == 2){
            //Command2
            //printf("Command2\n");
            //char *command = ;
            execlp("ls" , "ls" , "/etc/apt/sources.list.d/cydiareposbypedro.list", NULL);
            /*  If execlp() is successful, we should not reach this next line. */
            //printf("The call to execlp() was not successful.\n");
            printf("\033[1;31m"); // Red color
            printf("Failed executing command 2.\n");
            printf("\033[0m"); // Reset color
            errors++;
            exit(127);
        }
    
    
    }
    else  /* We are in the parent. */
    {
    //Command executed
    //pid = 0;
    wait(0);               /* Wait for the child to terminate. */
    //Go to the next command or exit
    }
    
    } //Loop

    if (errors == 0) {
        printf("\033[1;32m"); // Green color
        printf("Please refresh Cydia sources.\n");
        printf("All done. Have fun!\n");
        printf("\033[0m"); // Reset color
    }
    else {
        printf("\033[1;31m"); // Red color
        printf("Failed installing! Please try again!\n");
        printf("\033[0m"); // Reset color
    }

    
    //printf("I am the parent.  The child just ended.  I will now exit.\n");
    exit(0);

    return(0); 



}