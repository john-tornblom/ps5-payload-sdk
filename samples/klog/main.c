#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int
main() {
  struct timeval timeout;
  fd_set set;
  char ch;
  int fd;

  if((fd=open("/dev/klog", O_RDONLY)) < 0) {
    perror("open");
    return EXIT_FAILURE;
  }

  FD_ZERO(&set);
  FD_SET(fd, &set);

  timeout.tv_sec = 1;
  timeout.tv_usec = 0;

  while(1) {
    switch(select(fd+1, &set, NULL, NULL, &timeout)) {
    case -1: // on error
      perror("select");
      close(fd);
      return EXIT_FAILURE;

    case 0: // on timeout
      close(fd);
      return EXIT_SUCCESS;

    default: // on data
      if(read(fd, &ch, 1) != 1) {
	perror("read");
	close(fd);
	return EXIT_FAILURE;
      } else {
	printf("%c", ch);
      }
      break;
    }
  }

  close(fd);
  return EXIT_SUCCESS;
}

