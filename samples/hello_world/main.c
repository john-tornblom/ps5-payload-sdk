#include <stdio.h>
#include <string.h>


typedef struct notify_request {
  char useless1[45];
  char message[3075];
} notify_request_t;


int sceKernelSendNotificationRequest(int, notify_request_t*, size_t, int);


int
main() {
  notify_request_t req;

  bzero(&req, sizeof req);
  strncpy(req.message, "Hello, world!", sizeof req.message);

  return sceKernelSendNotificationRequest(0, &req, sizeof req, 0);
}

