#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

import hashlib, socket, os

HOST = '127.0.0.1'
PORT = 6666

def sock(rhost, rport):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((rhost, rport))
    return s, s.makefile('rw', bufsize=0)

def read_until(f, delim='\n'):
    data = ''
    while not data.endswith(delim):
        data += f.read(1)
    return data


def chal(f):
    read_until(f, "21 bytes, starting with")
