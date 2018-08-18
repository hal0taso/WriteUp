#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

// unsigned char *SHA1(const unsigned char *d, size_t n, unsigned char *md)
#define DATA_LEN 21
#define BRUTE_LEN 5
#define BRUTE_MAX ((unsigned long long) 1 << (BRUTE_LEN * 8))
#define HASH_LEN SHA_DIGEST_LENGTH
typedef unsigned long long ull;

void print_buf(unsigned char *buf, ull n){
  for (int i = 0; i < n; i ++){
    //printf("%02x", buf[i]);
    printf("%c", buf[i]);
  }
  printf("\n");
}

void brute(const char *proof){

  unsigned char buf[256];
  unsigned char hash[HASH_LEN];

  for (ull i = 0; i < BRUTE_MAX; i++){
    memcpy(buf, proof, DATA_LEN);
    memcpy(&buf[DATA_LEN - BRUTE_LEN], (unsigned char *) &i, BRUTE_LEN);
    SHA1(buf, DATA_LEN, hash);
    if (!memcmp(&hash[HASH_LEN - strlen("\xff\xff")], "\xff\xff", strlen("\xff\xff"))){
      print_buf(buf, DATA_LEN);
      exit(0);
    }

  }
}

int main(int argc, char **argv){
  if (argc > 1){
    brute(argv[1]);
  }
  return 0;
}
