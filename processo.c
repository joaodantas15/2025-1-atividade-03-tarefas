// processo.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Falha no fork!\n");
        return 1;
    } else if (pid == 0) {
        printf("FILHO: Olá! Meu PID é %d.\n", getpid());
        sleep(2);
        printf("FILHO: Estou terminando.\n");
    } else {
        printf("PAI: Olá! Criei um filho com PID %d.\n", pid);
        printf("PAI: Vou esperar o filho terminar...\n");
        wait(NULL);
        printf("PAI: Meu filho terminou. Agora eu vou terminar.\n");
    }
    return 0;
}