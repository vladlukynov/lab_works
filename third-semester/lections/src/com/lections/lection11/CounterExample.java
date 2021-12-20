package com.lections.lection11;

import com.lections.lection9.utils.Utils;

public class CounterExample {

    static class Task implements Runnable {
        volatile private boolean stop;

        public boolean isStop() {
            return stop;
        }

        @Override
        public void run() {
            long counter = 0;
            while (!isStop()) {
                counter++;
            }
            System.out.println(counter);
        }

        public void stop() {
            stop = true;
        }
    }

    public static void main(String[] args) {
        System.out.println("Start");

        Task t = new Task();
        new Thread(t).start();

        Utils.pause(3000);
        t.stop();

        System.out.println("Stop");
    }
}
