package com.lections.lection12;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class CachedThreadPoolExample {
    static class Task implements Runnable {
        @Override
        public void run() {
            Utils.pause(3000);
        }
    }

    public static void main(String[] args) {
        ThreadPoolExecutor service = (ThreadPoolExecutor) Executors.newCachedThreadPool();

        printStats(service);
        service.execute(new Task());

        service.execute(() -> {
            while (true) {
                Utils.pause(1000);
                printStats(service);
            }
        });

        for (int i = 0; i < 20; i++) {
            service.execute(new Task());
            Utils.pause(200);
        }
    }

    public static void printStats(ThreadPoolExecutor service) {
        System.out.println(service.getPoolSize());
        System.out.println(service.getActiveCount());
    }
}
