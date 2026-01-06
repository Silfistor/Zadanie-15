#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t set;
    int sig;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("[EVENT-LOOP] PID: %d — ожидаю SIGUSR1 через sigwait()\n", getpid());

    while (1) {
        sigwait(&set, &sig);
        printf("[EVENT-LOOP] Получен сигнал: %d (SIGUSR1)\n", sig);
    }

    return 0;
}
