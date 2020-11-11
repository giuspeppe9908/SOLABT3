#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char * argv[]){
    /*dichiarazione pid figli e padre e valore*/
    pid_t kids_process, my_pid, my_ppid, value;
    /*dichiarazione puntatore a FILE fp*/
    FILE * fp;
    /*apro il file che trovo in argv[0] in w*/
    fp = fopen(argv[1], "w");
    if( fp == NULL){
      printf("ERRORE nell'apertura del file!\n");
    }
    else{
         value = fork();/*altra fork()*/
         int n_kids = atoi(argv[2]);
         int n_writes = atoi(argv[3]);
         while(n_kids > 0){
            kids_process = fork();
            if(kids_process != 0)
              n_kids--;
            if(kids_process == 0){
              while(n_writes > 0){
                 my_pid = getpid();
                 my_ppid = getppid();
                 fprintf(fp, "PID padre = %d | PID figlio = %d\n", my_ppid, my_pid);
                 n_writes--;
              }
              /*terminazione processo figlio*/
              exit(EXIT_SUCCESS);
            }
         }
         fclose(fp);
         exit(EXIT_SUCCESS);
        }
    
  return 0;
}
