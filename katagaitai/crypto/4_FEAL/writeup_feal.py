#!/usr/bin/env python2.7
# -*- coding:utf-8 -*-

# Thsi is writeup by katagaitai

import hashlib, socket, os, subprocess  
HOST, PORT = '127.0.0.1', 8888  
NUM_CHECK = 10  
  
def sock(remoteip, remoteport):  
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
    s.connect((remoteip, remoteport))  
    return s, s.makefile('rw', bufsize=0)  
  
def read_until(f, delim='\n'):  
    data = ''  
    while not data.endswith(delim):  
        data += f.read(1)  
    return data  
  
############################################################################################  
def gBox(a,b,mode):  
    x = (a+b+mode) & 0xff  
    return ((x<<3)|(x>>5))&0xff  
  
def fBox(plain):  
    t0 = (plain[2] ^ plain[3])  
    y1 = gBox(plain[0] ^ plain[1], t0, 1)  
    y0 = gBox(plain[0], y1, 0)  
    y2 = gBox(t0, y1, 0)  
    y3 = gBox(plain[3], y2, 1)  
    return [y3, y2, y1, y0]  
  
def convert_list(input):  
    return [(input&0xff), ((input>>8) & 0xff), ((input>>16) & 0xff), ((input>>24) & 0xff) ]  
  
def list_xor(*LIST):  
    return map(lambda x: reduce(lambda a,b: a^b, x), zip(*LIST))  
  
def decrypt(plain,subkeys):  
    cipherLeft = plain[0:4]  
    cipherRight = plain[4:]  
    R4R = list_xor(cipherLeft,cipherRight)  
    R4L = list_xor(cipherLeft, fBox(list_xor(R4R, subkeys[3])))  
    R3R = R4L  
    R3L = list_xor(R4R , fBox(list_xor(R3R, subkeys[2])))  
    R2R = R3L  
    R2L = list_xor(R3R, fBox(list_xor(R2R, subkeys[1])))  
    left = list_xor(R2R, fBox(list_xor(R2L, subkeys[0])))  
    right = list_xor(left, R2L)  
    pleft = list_xor(left, subkeys[4])  
    pright = list_xor(right, subkeys[5])  
    return pleft+pright  
  
############################################################################################  
def chal(f):  
    read_until(f,"21 bytes, starting with ")  
    prefix = f.read(16)  
    i = 0  
    while True:  
      cand = prefix + ("%010x"%i).decode("hex")  
      if hashlib.sha1(cand).hexdigest().endswith("ffff"):  
        break  
      i += 1  
    f.write(cand)  
  
def get_keycipher(f):  
    read_until(f,"Please decrypt: ")  
    keycipher = f.read(32)  
    read_until(f, "\n")  
    return keycipher.decode("hex")  
  
def get_ciphertext(f, a):  
    assert len(a) % 8 == 0  
    f.write(''.join(map(chr, a)))  
    C = f.read(16)  
    read_until(f, "\n")  
    return C  
  
def get_plaintext(diff_list):  
    a = map(ord, os.urandom(8))  
    b = list_xor(a, diff_list)  
    return a, b  
  
def wrapper(cmd):  
  print cmd  
  p = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE)  
  return p.communicate()[0]  
  
############################################################################################  
os.system("gcc -O3 test.c")  
  
s, f = sock(HOST, PORT)  
chal(f)  
key_cipher = get_keycipher(f)  
print "[+] key_cipher=%s" % key_cipher.encode("hex")  
  
print "[+] recovering subkey3..."  
diff_list, args = [0x80,0x80,0x00,0x00,0x80,0x80,0x00,0x00], ["3"]  
for x in xrange(NUM_CHECK):  
    a, b = get_plaintext(diff_list)  
    args += [''.join(map(chr, a)).encode("hex")]  
    args += [''.join(map(chr, b)).encode("hex")]  
    args += [get_ciphertext(f, a)]  
    args += [get_ciphertext(f, b)]  
subkey3 = wrapper(["./a.out"] + args)  
print "[+] subkey3 is %s" % `subkey3`  
  
print "[+] recovering subkey2..."  
diff_list, args = [0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00], ["2", subkey3]  
for x in xrange(NUM_CHECK):  
    a, b = get_plaintext(diff_list)  
    args += [''.join(map(chr, a)).encode("hex")]  
    args += [''.join(map(chr, b)).encode("hex")]  
    args += [get_ciphertext(f, a)]  
    args += [get_ciphertext(f, b)]  
subkey2 = wrapper(["./a.out"] + args)  
print "[+] subkey2 is %s" % `subkey2`  
  
print "[+] recovering subkey1..."  
diff_list, args = [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04], ["1", subkey3, subkey2]  
for x in xrange(NUM_CHECK):  
    a, b = get_plaintext(diff_list)  
    args += [''.join(map(chr, a)).encode("hex")]  
    args += [''.join(map(chr, b)).encode("hex")]  
    args += [get_ciphertext(f, a)]  
    args += [get_ciphertext(f, b)]  
subkey1 = wrapper(["./a.out"] + args)  
print "[+] subkey1 is %s" % `subkey1`  
  
print "[+] recovering all subkeys..."  
diff_list, args = [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00], ["0", subkey3, subkey2, subkey1]  
for x in xrange(NUM_CHECK):  
    a, b = get_plaintext(diff_list)  
    args += [''.join(map(chr, a)).encode("hex")]  
    args += [''.join(map(chr, b)).encode("hex")]  
    args += [get_ciphertext(f, a)]  
    args += [get_ciphertext(f, b)]  
subkeys = wrapper(["./a.out"] + args)  
print "[+] subkeys is %s" % `subkeys`  
  
subkeys = eval(subkeys)  
subkeys = [convert_list(sk) for sk in subkeys]  
kp1 = ''.join(map(chr, decrypt(map(ord, key_cipher[0:8]), subkeys)))  
kp2 = ''.join(map(chr, decrypt(map(ord, key_cipher[8:16]), subkeys)))  
print "[*] OK, all subkeys were recovered. plaintext is %s" % `kp1 + kp2`
