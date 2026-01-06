#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("[BLOCKER] SIGINT заблокирован. Попробуй Ctrl+C.\n");
    printf("PID: %d\n", getpid());
    printf("Попробуй послать SIGUSR1 из другой программы или командой:\n");
    printf("  kill -SIGUSR1 %d\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}
