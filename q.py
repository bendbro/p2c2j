import ctypes
java = ctypes.cdll.LoadLibrary('/Library/Java/JavaVirtualMachines/jdk1.7.0_80.jdk/Contents/MacOS/libjli.dylib')
lib = ctypes.cdll.LoadLibrary('./q.dylib')
libd = ctypes.cdll.LoadLibrary('./qd.dylib')

lib.init();
lib.coutTest('This string was made in python and displayed natively!')
print("The next two lines verify the JNI works in linking libraries")
lib.doJavaPrintLine();
libd.doJavaPrintLineQD();
print("The next three lines verify that global variables work as expected.")
print(lib.globalTest());
print(lib.globalTest());
print(lib.globalTest());
