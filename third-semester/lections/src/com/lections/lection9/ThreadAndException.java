package com.lections.lection9;

import com.lections.lection9.utils.Utils;

public class ThreadAndException {
    public static void main(String[] args) {
        System.out.println("Start");

        new Thread(() -> {
            while (true) {
                System.out.println(Thread.currentThread().getName());
                Utils.pause(1000);
                throw new RuntimeException();
            }
        }).start();

        /* Thread.currentThread().setUncaughtExceptionHandler((t, e) -> System.out.println("Bad exception caught!")); */
        Thread.setDefaultUncaughtExceptionHandler((t, e) -> System.out.println("Bad exception caught!"));

        if (args.length == 0) {
            throw new RuntimeException();
        }

        System.out.println("Finish");
    }
}
