package com.lections.lection12;

import java.util.concurrent.Semaphore;

public class SemaphoreExample {
    static class Counter {
        volatile int count;
        Semaphore sem = new Semaphore(1);

        public int getCount() {
            return count;
        }

        public void inc() {
            sem.acquireUninterruptibly();
            try {
                count++;
            } finally {
                sem.release();
            }

        }
    }
}
