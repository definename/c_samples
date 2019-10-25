#!/bin/sh

TEST_BINARY=test
GENERATED_HEADERS=*.pb-c.h
GENERATED_SOURCES=*.pb-c.c

echo "[*] About to remove binary:$TEST_BINARY"
rm ./$TEST_BINARY
echo "[*] About to remove protobuf generated headers:$GENERATED_HEADERS"
rm ./$GENERATED_HEADERS
echo "[*] About to remove protobuf generated headers:$GENERATED_SOURCES"
rm ./$GENERATED_SOURCES
