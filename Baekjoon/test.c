#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int glob = 7;

int main() {
    int var;
    pid_t pid;
    char buf[] = "ready to fork\n";

    var = write(STDOUT_FILENO, buf, sizeof(buf));

    pid = fork();
    if (pid == 0) {
        var++;
    } else {
        sleep(2);
    }    
        glob++; 
    printf("pid = %d, glob : %d , var : %d\n", pid, glob, var);
}