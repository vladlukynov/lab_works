package com.lections.lection9;

public class ThreadExamples {
    public static void main(String[] args) {
        System.out.println(Thread.currentThread());

        new Thread() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread());
            }
        }.start();

        new Thread(() -> System.out.println(Thread.currentThread())).start();

        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread());
            }
        }).start();
    }
}
