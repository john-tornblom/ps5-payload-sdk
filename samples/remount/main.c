#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/_iovec.h>


/**
 * Build an iovec structure for nmount().
 **/
static void
build_iovec(struct iovec **iov, int *iovlen, const char *name, const char *v) {
  int i;

  if(*iovlen < 0) {
    return;
  }

  i = *iovlen;
  *iov = realloc(*iov, sizeof(**iov) * (i + 2));
  if(*iov == 0) {
    *iovlen = -1;
    perror("realloc");
    return;
  }

  (*iov)[i].iov_base = strdup(name);
  (*iov)[i].iov_len = strlen(name) + 1;
  i++;

  (*iov)[i].iov_base = v ? strdup(v) : 0;
  (*iov)[i].iov_len = v ? strlen(v) + 1 : 0;
  i++;

  *iovlen = i;
}


/**
 * Remount a given path with write permissions.
 * TODO: plug memory leak?
 **/
static int
remount(const char *dev, const char *path) {
  struct iovec* iov = 0;
  int iovlen = 0;

  build_iovec(&iov, &iovlen, "fstype", "exfatfs");
  build_iovec(&iov, &iovlen, "fspath", path);
  build_iovec(&iov, &iovlen, "from", dev);
  build_iovec(&iov, &iovlen, "large", "yes");
  build_iovec(&iov, &iovlen, "timezone", "static");
  build_iovec(&iov, &iovlen, "async", 0);
  build_iovec(&iov, &iovlen, "ignoreacl", 0);

  return nmount(iov, iovlen, MNT_UPDATE);
}


/**
 * Remount /system and /system_ex with write permissions.
 **/
int
main(void) {
  if(remount("/dev/ssd0.system", "/system")) {
    perror("remount /system");
    return EXIT_FAILURE;
  }

  if(remount("/dev/ssd0.system_ex", "/system_ex")) {
    perror("remount /system_ex");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
