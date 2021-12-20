package com.lab7.workers;

import java.util.concurrent.SynchronousQueue;

public class Writer implements Runnable {

    private final SynchronousQueue<String> queue;

    public Writer(SynchronousQueue<String> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        String message = Thread.currentThread().getName() + " send message for you";
        try {
            queue.put(message);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
