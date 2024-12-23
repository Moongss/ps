#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
  char *s = "ABCDEFGHIJ1234567890";
  char *s2 = "Hello, World!";
  char *s3 = "Appended Text";

  int fd;

  fd = open("in.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  write(fd, s, strlen(s));


  lseek(fd, 5, SEEK_SET);
  write(fd, s2, strlen(s2));

  lseek(fd, 0, SEEK_END);
  write(fd, s3, strlen(s3));


  close(fd);

  fd = open("in.txt", O_RDONLY);
  char buf[100];

  while (read(fd, buf, sizeof(buf)) > 0) {
  }
  buf[strlen(buf)] = '\0';
  printf("%s\n", buf);
}