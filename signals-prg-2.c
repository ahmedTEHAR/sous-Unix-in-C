#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
int cpt = 0;
void handler (int sig) {
cpt++ ; }
int main() {
bool boolean = true;
int i;
signal(SIGCHLD, handler);
for (i = 0; i < 5; i++) {
if (fork() == 0) {
    printf("je suis le Fils de pid :%d\n", getpid());
exit(0);
}
else {
    if (boolean )
    printf("je suis le père %d \n",getpid());
    boolean=false;
    
} }
while (wait(NULL) != -1) ; // pour quoi ca 
printf("cpt = %d\n", cpt); // pour l'affichage 
return 0;
}