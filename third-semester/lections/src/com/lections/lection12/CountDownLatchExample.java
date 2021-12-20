package com.lections.lection12;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CountDownLatchExample {
    static class Runner implements Runnable{
        private final CountDownLatch latch;

        public Runner(CountDownLatch latch) {
            this.latch = latch;
        }

        @Override
        public void run() {
            System.out.println(this+" is ready");
            try {
                latch.await();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(this + " has started at " + System.currentTimeMillis());
        }

        public static void main(String[] args) {
            ExecutorService service = Executors.newCachedThreadPool();
            CountDownLatch latch = new CountDownLatch(3);

            service.execute(new Runner(latch));
            service.execute(new Runner(latch));
            service.execute(new Runner(latch));
            service.execute(new Runner(latch));

            System.out.println("On start");
            latch.countDown();
            Utils.pause(2000);

            System.out.println("Warning");
            latch.countDown();
            Utils.pause(2000);

            System.out.println("Go");
            latch.countDown();

            service.shutdown();
        }
    }
}
