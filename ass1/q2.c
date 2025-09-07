//Parent waits for child using wait()

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
    } else {
        wait(NULL);  // Parent waits for child
        printf("Parent: Child finished, now parent runs.\n");
    }
    return 0;
}
