#!/usr/bin/env bash

echo "This process relies on jni.h and jni_md.h headers along with libjli.dylib
(jvm.lib on windws and libjvm.so on linux)"
echo "q.h and q.cpp become the library files that host the JVM. qd.cpp links to
q.h and relies on their globally defined JNI to make calls to the JNI. q.py
shows the correct way to use them, q.sh shows how to compile them."

clang++ -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include/darwin -o q.o -c -Wall -fPIC q.cpp
echo "made q.o"

clang++ -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include/darwin /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/MacOS/libjli.dylib -o q.dylib -dynamiclib q.o
echo "made q.dylib"

clang++ -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include/darwin -o qd.o -c -Wall -fPIC qd.cpp
echo "made qd.o"

clang++ -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/Home/include/darwin /Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/MacOS/libjli.dylib q.dylib -o qd.dylib -dynamiclib qd.o
echo "made qd.dylib"

echo "running q.py"
python q.py
