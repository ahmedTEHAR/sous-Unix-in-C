#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#define val ...
int compteur, nb1 = 1, nb2 = 1;
pid_t pid1, pid2;
void Hand_P (int sig) {
if (compteur == val) {
kill(pid1, SIGINT);
kill(pid2, SIGINT);
exit (0);
};
compteur++;
if (compteur % 2 == 1) kill(pid2, SIGUSR2);
else kill(pid1, SIGUSR1);
}
void Hand_F1 (int sig) {
printf("Fils1: %d\n", nb1);
nb1++;
kill(getppid(), SIGCONT);
}
void Hand_F2 (int sig) {
printf("Fils2: %d\n", nb2*nb2);
nb2++;
kill(getppid(), SIGCONT);
}
int main() {
compteur = 0;
signal (SIGCONT, Hand_P);
signal (SIGUSR1, Hand_F1);
signal (SIGUSR2, Hand_F2);
pid1 = fork();
if(pid1 == 0) {
printf("Fils1 est pret\n");
while(1);
}
pid2 = fork();
if(pid2 == 0) {
printf("Fils2 est pret\n");
while(1);
}
sleep(4);
kill(pid1, SIGUSR1);
while(1);
exit(0);
}
