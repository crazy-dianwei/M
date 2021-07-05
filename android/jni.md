- jni是java提供的java代码与c/c++代码相互沟通的机制，可互相调用
- NDK是一系列工具的集合，集成了交叉编译器，提供了相应的mk文件隔离cpu、平台、ABI差异。提供开发so、并与java应用打包成apk功能
- so反编译难度大，提高安全性
- java中定义native方法，通过javah生成对应的头文件，定义cpp源文件，实现头文件中的方法

## example
- javac src/com/study/jnilearn/HelloWorld.java -d ./bin
- javah -jni -classpath ./bin -d ./jni com.study.jnilearn.HelloWorld or javah -jni -classpath ./bin -o HelloWorld.h com.study.jnilearn.HelloWorld
- get com_study_jnilearn_HelloWorld.h or HelloWorld.h

## macos compile
- gcc -dynamiclib -o libHelloWorld.jnilib jni/HelloWorld.c -framework JavaVM -I/$JAVA_HOME/include -I/$JAVA_HOME/include/darwin
- -framework JavaVM -I：编译JNI需要用到JVM的头文件(jni.h)，第一个目录是平台无关的，第二个目录是与操作系统相关平台的头文件 


## run
- java -Djava.library.path=./ -classpath ./bin com.study.jnilearn.HelloWorld


