package com.lections.lection10;

import com.lections.lection9.utils.Utils;

public class IsInterrupted {
    public static void main(String[] args) {
        Thread t = new Thread(() -> {
            long counter = 0;
            while (true) {
                counter++;
            }
        });

        t.start();

        Utils.pause(1000);
        System.out.println(t.isInterrupted());

        t.interrupt();
        System.out.println(t.isInterrupted());
        System.out.println(t.isInterrupted());
    }
}
