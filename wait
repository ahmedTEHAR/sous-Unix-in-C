#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main () {
    
pid_t pid, id ; 
int *status;
if ((pid=fork())==0) {
        printf ("Je suis le fils avec pid %d\n" , getpid ());
        sleep(10);
        exit(3);
}
else if ( pid > 0) {
        printf ("Je suis le pere avec pid %d\n" , getpid ());
        printf (" J’ attends que mon fils se termine\n" );
    While((id=waitpid(pid,&status,WNOHANG))==0)
        printf(" mon fils n’ a pas encore terminé son exécution");
        if(WIFEXITED(status)) printf("fils %d terminé par exit(%d)\n",id,WEXITSTATUS(status)) ;
}
else {
    printf ("Erreur dans la creation du fils\n" );
    exit (2);
}
return 0;
}

