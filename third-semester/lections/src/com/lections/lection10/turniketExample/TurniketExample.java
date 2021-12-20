package com.lections.lection10.turniketExample;

import com.lections.lection9.utils.Utils;

import java.util.Random;

public class TurniketExample {

    static Counter counter = new Counter();

/*    synchronized static void incrementCounter() {
        int tmp1 = counter;
        int tmp2 = tmp1 + 1;
        counter = tmp2;
        System.out.println(Thread.currentThread().getName() + ": " + counter);
    }*/

    static class Turniket implements Runnable {
        @Override
        public void run() {
            Random random = new Random();
            while (true) {
                Utils.pause(2000);
                counter.inc();
            }
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 8; i++) {
            new Thread(new Turniket()).start();
        }

/*        while (true) {
            Utils.pause(1000);
            System.out.println(counter);
        }*/
    }
}
