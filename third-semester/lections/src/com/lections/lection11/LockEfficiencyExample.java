package com.lections.lection11;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockEfficiencyExample {

    static class Task implements Runnable {
        private boolean stop;
        final private Lock lock = new ReentrantLock();

        public boolean isStop() {
            lock.lock();
            try {
                return stop;
            } finally {
                lock.unlock();
            }
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
            lock.lock();
            try {
                stop = true;
            } finally {
                lock.unlock();
            }
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
