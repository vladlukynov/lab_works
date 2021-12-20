package com.lab7.workers;

import java.util.concurrent.SynchronousQueue;

public class Reader implements Runnable {

    private final SynchronousQueue<String> queue;

    public Reader(SynchronousQueue<String> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        String message;
        try {
            message = queue.take();
            System.out.println(Thread.currentThread().getName() + " take a message: " + message);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
