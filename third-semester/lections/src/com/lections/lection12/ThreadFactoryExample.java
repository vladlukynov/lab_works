package com.lections.lection12;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ThreadFactoryExample {
    public static void main(String[] args) {
        ExecutorService service = Executors.newCachedThreadPool(r -> {
            Thread t = new Thread(r, "MyThread");
            t.setDaemon(true);
            return t;
        });

        service.execute(() -> {
            System.out.println(Thread.currentThread());
        });

        Utils.pause(1000);
    }
}
