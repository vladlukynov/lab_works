package com.lections.lection10.turniketExample;

public class Counter {
    private int counter;
    final private Object mutex = new Object();

    /*public synchronized void inc() {
        counter++;
        System.out.println(Thread.currentThread().getName() + ": " + counter);
    }*/

    public void inc() {
        synchronized (mutex) {
            counter++;
            System.out.println(Thread.currentThread().getName() + ": " + counter);
        }
    }

    public synchronized void mul() {
        counter *= 2;
    }
}
