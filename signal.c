#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>

/* Part 1 - Step 1 and 2: Do your tricks here
 * Your goal must be to change the stack frame of caller (main function)
 * such that you get to the line after "r2 = *( (int *) 0 )"
 */
void segment_fault_handler(int signum) {

    printf("handling segmentation fault!\n");

    /* Step 2: Handle segfault and change the stack*/
    printf("Got SIGSEGV at address: 0x%lx\n",(long) si->si_addr);
    printf("Implements the handler only\n");
    int flag=1;
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]) {

    int r2 = 0;

    /* Step 1: Registering signal handler */

    struct sigaction action;
    memset(&action, '\0', sizeof(action));
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = segment_fault_handler;

     if (sigaction(SIGSEGV, &action, NULL) == -1)
        handle_error("sigaction");


    r2 = *( (int *) 0 ); // This will generate segmentation fault

    r2 = r2 + 1 * 100;
    printf("result after handling seg fault %d!\n", r2);

    return 0;
}
