//Create a child process using fork() and print PIDs

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { 
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else if (pid > 0) { 
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}

//output:
/*
Parent process: PID = 10234, Child PID = 10235
Child process: PID = 10235, Parent PID = 10234
*/
