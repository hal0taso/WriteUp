#include <stdio.h>
#include <stdlib.h>

unsigned char rot3(unsigned char x){
  return ((x << 3) | (x >> 5)) & 0xff;
}


unsigned char gbox(unsigned char a, unsigned char b, unsigned char mode){
  return rot3((a + b + mode) & 0xff);
}

union FEAL{
  unsigned int w;
  unsigned char b[4];
};

unsigned int fbox(unsigned int _src){
  union FEAL src, dst;
  src.w = _src;
  unsigned char t0 = (src.b[2] ^ src.b[3]);
  unsigned char y1 = gbox(src.b[0] ^ src.b[1], t0, 1);
  unsigned char y0 = gbox(src.b[0], y1, 0);
  unsigned char y2 = gbox(t0, y1, 0);
  unsigned char y3 = gbox(src.b[3], y2, 1);

  dst.b[0] = y0;
  dst.b[1] = y1;
  dst.b[2] = y2;
  dst.b[3] = y3;

  return src.w;
}




int main(int argc, char *argv[]){
  return 0;
}
