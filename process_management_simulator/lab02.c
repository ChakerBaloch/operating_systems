#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pids[10]; // store pids of child processes
    int i;

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork(); // create a new child process
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Each child runs a different command via exec
            switch(i) {
                case 0:
                    execlp("echo", "echo", "Hello Chaker",NULL);
                    break;
                case 1:
                    execlp("ls", "ls", "-l",NULL);
                    break;
                case 2:
                    execlp("date", "date", NULL);
                    break;
                case 3:
                    execlp("uname", "uname", "-a", NULL);
                    break;
                case 4:
                    execlp("whoami", "whoami", NULL);
                    break;
                case 5:
                    execlp("pwd", "pwd", NULL);
                    break;
                case 6:
                    execlp("id", "id", NULL);
                    break;
                case 7:
                    execlp("uptime", "uptime", NULL);
                    break;
                case 8:
                    execlp("cal", "cal", NULL);
                    break;
                case 9:
                    execlp("echo", "echo", "Child process 9: Goodbye!", NULL);
                    break;
                default:
                    exit(1); // should never hit this
            }
            perror("exec failed"); // only if exec fails
            exit(1);
        } else {
            pids[i] = pid; // store child pid in parent
        }
    }

    // Parent waits for each child and reports status
    for (int i = 0; i < 10; i++) {
        int status;
        pid_t pid = waitpid(pids[i], &status, 0); // wait for specific child

        // report how the child process ended
        if (WIFEXITED(status)) {
            printf("Parent: Child %d (PID %d) exited with status %d\n", i, pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Parent: Child %d (PID %d) was terminated by signal %d\n", i, pid, WTERMSIG(status));
        }
    }

    printf("Parent: All child processes completed.\n");
    return 0;
}
