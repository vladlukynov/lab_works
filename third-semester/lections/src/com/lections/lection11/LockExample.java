package com.lections.lection11;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockExample {

    static Lock lock = new ReentrantLock();

    public static void main(String[] args) {
        new Thread(() -> {
            try {
                lock.lock();
                System.out.println("Locked");
                Utils.pause(5000);
                if (args.length == 0) {
                    throw new RuntimeException();
                }
            } finally {
                lock.unlock();
            }
            System.out.println("Unlock");
        }).start();

        Utils.pause(1000);

        if (lock.tryLock()) {
            try {
                System.out.println("Hello");
            } finally {
                lock.unlock();
            }
        } else {
            System.out.println("Lock is busy");
        }

        lock.lock();
        /* code */
        System.out.println("Main lock");
        lock.unlock();
    }
}
