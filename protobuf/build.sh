#!/bin/sh

PROTOFILE=AMessage.proto
PLUGIN=protoc-gen-c
PROTO_OUT=./
PROTO_PATH=./

echo "Protofiles:$PROTOFILE"
echo "Plugin:$PLUGIN"
echo "Proto out:$PROTO_OUT"
echo "Proto path:$PROTO_PATH"
echo "[*] About to generate protobuf..."
protoc --plugin=$PLUGIN --proto_path=$PROTO_PATH --c_out=$PROTO_OUT $PROTOFILE

OUT=test
echo "[*] About to build binary:$OUT"
gcc ./main.c -o $OUT