package com.lections.lection11;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ExecutorsExample {

    public static void main(String[] args) {
        ExecutorService service = Executors.newSingleThreadExecutor();
        service.execute(() -> {
            Utils.pause(3000);
            System.out.println("Hello from " + Thread.currentThread());
        });

        if (!service.isShutdown()) {
            service.execute(() -> {
                Utils.pause(3000);
                System.out.println("Hello from " + Thread.currentThread());
            });
        } else {
            System.out.println("Service unavailable");
        }

        service.shutdown();

        try {
            service.awaitTermination(1, TimeUnit.HOURS);
            System.out.println("Finished");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
