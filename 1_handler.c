#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
const char* signal_name(int sig) {
    switch (sig) {
        case SIGUSR1: return "SIGUSR1";
        case SIGUSR2: return "SIGUSR2";
        case SIGTERM: return "SIGTERM";
        case SIGINT:  return "SIGINT";
        case SIGHUP:  return "SIGHUP";
        default:     return "UNKNOWN SIGNAL";
    }
}

void sigusr1_handler(int sig) {
    printf("[HANDLER] Получен сигнал: %s (%d)\n", signal_name(sig), sig);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("[HANDLER] PID: %d — жду SIGUSR1...\n", getpid());

    while (1) {
        pause(); 
    }

    return 0;
}
