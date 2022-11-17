#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>
#include <time.h>

void     INThandler(int);

int  main(void)
{
     signal(SIGINT, INThandler);
     clock_t begin;
     double time_spent;
     unsigned int i;
     put("Press 'Ctrl+C' to retrieve the flag!!!");
     begin = clock();
     for (i=0;1;i++)
         {
    
         time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
         if (time_spent>=5.0)
             break;
         }
     return 0;
}

void  INThandler(int sig)
{
     signal(sig, SIG_IGN);
     setuid(0);
     system("/bin/cat /root/Flag.txt");
     exit(0);

}
