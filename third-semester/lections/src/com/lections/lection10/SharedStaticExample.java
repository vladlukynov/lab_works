package com.lections.lection10;

import com.lections.lection9.utils.Utils;

public class SharedStaticExample {

    static String message;

    static class Task implements Runnable {
        final private String message;
        final private int millis;

        public Task(String message, int millis) {
            this.message = message;
            this.millis = millis;
        }

        @Override
        public void run() {
            while (true) {
                SharedStaticExample.message = message;
                Utils.pause(millis);
            }
        }
    }

    public static void main(String[] args) {
        new Thread(new Task("First", 2000)).start();
        new Thread(new Task("Second", 2500)).start();
        new Thread(new Task("Third", 3000)).start();

        while (true) {
            Utils.pause(1000);
            System.out.println(message);
        }
    }
}
