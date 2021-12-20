package com.lections.lection10;

import com.lections.lection9.utils.Utils;
import jdk.jshell.execution.Util;

public class InterruptExample {
    static class SleepingTask implements Runnable {
        @Override
        public void run() {
            try {
                Thread.sleep(10000);
            } catch (InterruptedException error) {
                System.err.println("We were interrupted");
            }
        }
    }

    static class WorkingTask implements Runnable {
        @Override
        public void run() {
            long counter = 0;
            while (!Thread.interrupted()) {
                counter++;
            }
            System.out.println("We were interrupted with " + counter);
        }
    }

    public static void main(String[] args) {
        System.out.println("Started");
        Thread t = new Thread(new SleepingTask());
        t.start();

        Utils.pause(3000);
        t.interrupt();

        Thread wt = new Thread(new WorkingTask());
        wt.start();
        Utils.pause(3000);
        wt.interrupt();
    }
}
