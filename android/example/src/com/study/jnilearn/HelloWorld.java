package com.study.jnilearn;

public class HelloWorld {
    public static native String sayHello(String name);
    public static void main(String[] args) {
        String text = sayHello("lw");
        System.out.println(text);
    }

    static{
        System.loadLibrary("HelloWorld");
    }
    
}