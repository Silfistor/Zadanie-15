#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <PID>\n", argv[0]);
        exit(1);
    }

    pid_t target_pid = atoi(argv[1]);

    if (kill(target_pid, SIGUSR1) == 0) {
        printf("[SENDER] Сигнал SIGUSR1 отправлен на PID %d\n", target_pid);
    } else {
        perror("kill");
    }

    return 0;
}
