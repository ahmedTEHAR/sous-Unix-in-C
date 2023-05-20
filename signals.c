#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void gestion_signal (int sig) {
printf ("Signal reçu %d\n", sig);
signal (SIGINT, SIG_DFL);
}
int main() {
signal (SIGINT, gestion_signal);
while(1) {
printf("Bonjour\n");
sleep(1);
}
return 0;
}
