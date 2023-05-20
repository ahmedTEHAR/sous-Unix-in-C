#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int cpt = 0;
void handler (int sig) {
cpt++ ; }
int main() {
int i;
signal(SIGCHLD, handler);
for (i = 0; i < 5; i++) {
if (fork() == 0) {
exit(0);
} }
while (wait(NULL) != -1) ;
printf("cpt = %d\n", cpt);
return 0;
}
