#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char buf[20];
    int bufLength;
    int seekInfo;
    int readInfo;
    int writeInfo;
    int fileDescription;


    fileDescription = open("GCNS8S.txt",O_RDWR);
    if(fileDescription==-1)
    {
        perror("open() hiba:");
        exit(fileDescription);
    }
    printf("File Description erteke: %d\n", fileDescription);

    seekInfo = lseek(fileDescription, 0, SEEK_SET);
    if(seekInfo==-1)
    {
        perror("A pozicionalas nem volt jo: ");
        exit(seekInfo);
    }
    printf("Az olvasas nem volt jo: ");

    readInfo = read(fileDescription, buf, 15);
    if(readInfo==-1)
    {
        perror("Az olvasas nem volt jo: ");
        exit(readInfo);
    }
    printf("A read() erteke: %d\n",readInfo);
    printf("A beolvasott ertek: %s", buf);

    strcpy(buf, "Ez egy teszt lesz");
    bufLength=strlen(buf);
    writeInfo = write(fileDescription, buf, bufLength);

    if(writeInfo == -1)
    {
        perror("Az iras nem volt jo: ");
        exit(writeInfo);
    }
    printf("A write()-ba beirt bajtok szama: %d",writeInfo);

    return 0;
}
