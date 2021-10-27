#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>




int rand_int() {
  int open_file = open("/dev/urandom", O_RDONLY);
  if (open_file == -1) {
    printf("do not enter!!! warning!!! error code %s\n", strerror(errno));
    return 0;
  }

  unsigned int ret;
  int read_call = read(open_file, &ret, sizeof(ret));
  if (read_call == -1) {
    printf("do not enter!!! warning!!! error code %s\n", strerror(errno));
    return 0;
  }
  else {
    return ret;
  }
}




int main() {
  printf("Generating random numbers:\n");

  int i;
  int size = 10;
  unsigned int arr[size];

  for (i = 0; i < size; i++) {
    arr[i] = rand_int();
    if (arr[i] == 0) {
      printf("do not enter!!! warning!!! failure!!!");
      return 0;
    }
    printf("\trandom %d: %u\n", i, arr[i]);
  }


  printf("\nWriting numbers to file...\n\n");

  int txt = open("ten_random_ints.txt", O_CREAT | O_WRONLY, 0644);
  if (txt == -1) {
    printf("do not enter!!! warning!!! error code %s\n", strerror(errno));
    return 0;
  }
  int write_call = write(txt, arr, sizeof(arr));
  if (write_call == -1) {
    printf("do not enter!!! warning!!! error code %s\n", strerror(errno));
    return 0;
  }


  printf("Reading numbers from file...\n\n");
  txt = open("ten_random_ints.txt", O_RDONLY);
  if (txt == -1) {
    printf("do not enter!!! warning!!! error code %s\n", strerror(errno));
    return 0;
  }
  unsigned int arr_copy[size];
  int read_call = read(txt, arr_copy, sizeof(arr_copy));
  if (read_call == -1) {
    printf("do not enter!!! warning!!! error code %s\n", strerror(errno));
    return 0;
  }


  printf("Verification that written values were the same:\n");
  for (i = 0; i < size; i++) {
    printf("\trandom %d: %u\n", i, arr_copy[i]);
  }

  return 0;
}
