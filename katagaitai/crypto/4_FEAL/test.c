
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_CHECK 10

unsigned int pa_list[NUM_CHECK][2];
unsigned int pb_list[NUM_CHECK][2];
unsigned int ca_list[NUM_CHECK][2];
unsigned int cb_list[NUM_CHECK][2];
unsigned int c_list[NUM_CHECK][2];
unsigned int diff_cl_list[NUM_CHECK];
unsigned int clcr_a_list[NUM_CHECK];
unsigned int clcr_b_list[NUM_CHECK];
unsigned int cand_c[2];
unsigned int subkey5;
unsigned int subkey4;
unsigned int subkey3;
unsigned int subkey2;
unsigned int subkey1;
unsigned int subkey0;

unsigned int byte_swap(unsigned int a){
  return (((a>>0)&0xff)<<24) | (((a>>8)&0xff)<<16) | (((a>>16)&0xff)<<8) | (((a>>24)&0xff)<<0);
}

unsigned char gBox(unsigned char a, unsigned char b, unsigned char mode){
  unsigned char x;
  x = (a + b + mode) & 0xff;
  return ((x<<3) | (x>>5)) & 0xff;
}

union FEAL {
  unsigned int  w;
  unsigned char b[4];
};

unsigned int fBox(unsigned int _src){
   unsigned char t0, y1, y0, y2, y3;
   union FEAL src, dest;
   src.w = _src;

   t0 = src.b[2] ^ src.b[3];
   y1 = gBox(src.b[0] ^ src.b[1], t0, 1);
   y0 = gBox(src.b[0], y1, 0);
   y2 = gBox(t0, y1, 0);
   y3 = gBox(src.b[3], y2, 1);
   dest.b[0] = y3;
   dest.b[1] = y2;
   dest.b[2] = y1;
   dest.b[3] = y0;
   return dest.w;
}

void encrypt(unsigned int p1, unsigned int p2){
  unsigned int left = p1 ^ subkey4;
  unsigned int right = p2 ^ subkey5;
  unsigned int R2L = left ^ right;
  unsigned int R2R = left ^ fBox(R2L ^ subkey0);
  unsigned int R3L = R2R;
  unsigned int R3R = R2L ^ fBox(R2R ^ subkey1);
  unsigned int R4L = R3R;
  unsigned int R4R = R3L ^ fBox(R3R ^ subkey2);
  unsigned int R5L = R4L ^ fBox(R4R ^ subkey3);
  unsigned int R5R = R5L ^ R4R;
  cand_c[0] = R5L;
  cand_c[1] = R5R;
}

void brute1(){
  int x;
  unsigned long subkey;

  for (subkey=0; subkey<0x100000000; subkey++){
    if (subkey % 0x1000000 == 0) fprintf(stderr, "calculating... %#010lx\n", subkey); // debug

    for (x=0; x<NUM_CHECK; x++){
       if (fBox(clcr_a_list[x] ^ subkey) ^ fBox(clcr_b_list[x] ^ subkey) ^ 0x04000000 ^ diff_cl_list[x]){
         break;
       }
    }
    if (x==NUM_CHECK){
      printf("%#010lx", subkey);
      exit(0);
    }
  }
}

void brute2(){
  int x;
  unsigned long subkey;

  for (subkey=0; subkey<0x100000000; subkey++){
    if (subkey % 0x1000000 == 0) fprintf(stderr, "calculating... %#010lx\n", subkey); // debug

    subkey0 = subkey;
    for (x=0; x<NUM_CHECK-1; x++){
       subkey4 = ca_list[x][0] ^ fBox(ca_list[x][1] ^ subkey) ^ pa_list[x][0];
       subkey5 = ca_list[x][1] ^ subkey4 ^ pa_list[x][0] ^ pa_list[x][1];

       encrypt(pa_list[x+1][0], pa_list[x+1][1]); // cand_c <- pa_list[x+1] with subkeys
       if (c_list[x+1][0] != cand_c[0] || c_list[x+1][1] != cand_c[1]){
         break;
       }
    }
    if (x==NUM_CHECK-1){
      printf("[%#010x, %#010x, %#010x, %#010x, %#010x, %#010x]", subkey0, subkey1, subkey2, subkey3, subkey4, subkey5);
      exit(0);
    }
  }
}

void parse(char **argv){
  int i;
  unsigned long t;
  for (i=0; i<NUM_CHECK; i++){
    t = strtoul(argv[i*4], 0, 16);
    pa_list[i][0] = byte_swap((t>>32)&0xffffffff);
    pa_list[i][1] = byte_swap(t&0xffffffff);
    t = strtoul(argv[i*4+1], 0, 16);
    pb_list[i][0] = byte_swap((t>>32)&0xffffffff);
    pb_list[i][1] = byte_swap(t&0xffffffff);
    t = strtoul(argv[i*4+2], 0, 16);
    ca_list[i][0] = byte_swap((t>>32)&0xffffffff);
    ca_list[i][1] = byte_swap(t&0xffffffff);
    t = strtoul(argv[i*4+3], 0, 16);
    cb_list[i][0] = byte_swap((t>>32)&0xffffffff);
    cb_list[i][1] = byte_swap(t&0xffffffff);
  }
}

void recover_4th_round(int i, unsigned int subkey){
  unsigned int cl, cr;
  cl = ca_list[i][0] ^ ca_list[i][1];
  cr = ca_list[i][0] ^ fBox(cl ^ subkey);
  ca_list[i][0] = cl;
  ca_list[i][1] = cr;

  cl = cb_list[i][0] ^ cb_list[i][1];
  cr = cb_list[i][0] ^ fBox(cl ^ subkey);
  cb_list[i][0] = cl;
  cb_list[i][1] = cr;
}

void recover_round(int i, unsigned int subkey){
  unsigned int cl, cr;
  cl = ca_list[i][1];
  cr = ca_list[i][0] ^ fBox(cl ^ subkey);
  ca_list[i][0] = cl;
  ca_list[i][1] = cr;

  cl = cb_list[i][1];
  cr = cb_list[i][0] ^ fBox(cl ^ subkey);
  cb_list[i][0] = cl;
  cb_list[i][1] = cr;
}

int main(int argc, char *argv[]){
  int mode = atoi(argv[1]);
  int i;

  switch (mode){
    case 3:
      parse(&argv[2]);
      for (i=0; i<NUM_CHECK; i++){
        diff_cl_list[i] = ca_list[i][0] ^ cb_list[i][0];
        clcr_a_list[i] = ca_list[i][0] ^ ca_list[i][1];
        clcr_b_list[i] = cb_list[i][0] ^ cb_list[i][1];
      }
      brute1();

    case 2:
      subkey3 = strtoul(argv[2], 0, 16);
      parse(&argv[3]);

      for (i=0; i<NUM_CHECK; i++){
        recover_4th_round(i, subkey3);
        diff_cl_list[i] = ca_list[i][0] ^ cb_list[i][0];
        clcr_a_list[i] = ca_list[i][1];
        clcr_b_list[i] = cb_list[i][1];
      }
      brute1();

    case 1:
      subkey3 = strtoul(argv[2], 0, 16);
      subkey2 = strtoul(argv[3], 0, 16);
      parse(&argv[4]);

      for (i=0; i<NUM_CHECK; i++){
        recover_4th_round(i, subkey3);
        recover_round(i, subkey2);
        diff_cl_list[i] = ca_list[i][0] ^ cb_list[i][0];
        clcr_a_list[i] = ca_list[i][1];
        clcr_b_list[i] = cb_list[i][1];
      }
      brute1();

    case 0:
      subkey3 = strtoul(argv[2], 0, 16);
      subkey2 = strtoul(argv[3], 0, 16);
      subkey1 = strtoul(argv[4], 0, 16);
      parse(&argv[5]);

      for (i=0; i<NUM_CHECK; i++){
        c_list[i][0] = ca_list[i][0];
        c_list[i][1] = ca_list[i][1];
        recover_4th_round(i, subkey3);
        recover_round(i, subkey2);
        recover_round(i, subkey1);
      }
      brute2();

    default:
      exit(0);
  }
}
/*
writeup_feal.c
Ryoichi TERAMURA 
(ryo1.teramura@gmail.com)Displaying writeup_feal.c.
*/
