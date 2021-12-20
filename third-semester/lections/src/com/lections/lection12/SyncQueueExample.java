package com.lections.lection12;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.*;

public class SyncQueueExample {

    public static void main(String[] args) {
        BlockingQueue<String> queue = new SynchronousQueue<>();
        ExecutorService service = Executors.newCachedThreadPool();

        service.execute(() -> {
            System.out.println("create");
            System.out.println("ready");
            try {
                queue.put("Something");
                System.out.println("Send");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        service.execute(() -> {
            System.out.println("do some other stuff");
            Utils.pause(3000);
            System.out.println("Waiting");
            try {
                String thing = queue.take();
                System.out.println("got " + thing);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
    }
}