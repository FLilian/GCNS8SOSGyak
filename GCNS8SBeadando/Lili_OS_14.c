


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>


int main(int argc, char *argv[])
{
    key_t key= 111; 
    int shmid;
        char *guess_mem, *userinput;
        if(( shmid = shmget(key,1024,0666|IPC_CREAT)) < 0 ){
                perror("shmget"); 
                exit(1);
        }

    int f,pid;
    

        f = open("myfifo", O_RDONLY); 
        
        read(f, &pid, sizeof(int)); 
        close(f);
        unlink("myfifo"); 
        printf("read pid: %d \n", pid);
        printf("Adja meg az üzenetet: ");
    
    size_t len = 0;
    ssize_t lineSize = 0;

    if ((guess_mem = shmat(shmid,NULL,0)) == (char *) -1){ 
                perror("shmat"); 
                exit(1);
        }
    lineSize = getline(&userinput, &len, stdin); 
    strcpy(guess_mem, userinput); 
    shmdt(guess_mem); 
    kill(pid, SIGUSR1); 
    exit(0); 
    return 0;
}
