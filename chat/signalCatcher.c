#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
  {
    printf("received SIGINT\n");
  }
}

int main(void)
{
  
  // A long long wait so that we can easily issue a signal to this process
  
  int pid = fork();
  if(pid != 0)
  {
    if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
      printf("\ncan't catch SIGINT\n");
    }
  }
  else
  {
    while(1)
    {
      sleep(1);
    }
  }
  
}