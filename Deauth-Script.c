#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char **argv[]){
  printf("%s \n",argv[1]);
  FILE *fpipe;
  char *command = "nmcli -t -f ALL dev wifi";
  char *c = 1500;

  if (0 == (fpipe = (FILE*)popen(command, "r")))
  {
      perror("popen() failed.");
      exit(EXIT_FAILURE);
  }

  while (fread(&c, sizeof c, 1, fpipe))
  {
        printf("%c", c);
  }

    pclose(fpipe);
}
