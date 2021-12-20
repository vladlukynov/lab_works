package com.lections.lection12;

import com.lections.lection9.utils.Utils;

import java.util.Random;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CyclicBarrierExample {
    static class Runner implements Runnable {
        private final CyclicBarrier barrier;

        public Runner(CyclicBarrier barrier) {
            this.barrier = barrier;
        }

        @Override
        public void run() {
            System.out.println(Thread.currentThread().getName() + " started");
            Random random = new Random();
            Utils.pause(5000 + random.nextInt(5000));
            System.out.println(Thread.currentThread().getName() + " finished");
            try {
                barrier.await();
            } catch (InterruptedException | BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        CyclicBarrier barrier = new CyclicBarrier(4, () -> System.out.println("Finished"));
        ExecutorService service = Executors.newCachedThreadPool();

        service.execute(new Runner(barrier));
        service.execute(new Runner(barrier));
        service.execute(new Runner(barrier));
        service.execute(new Runner(barrier));

        service.shutdown();

        System.out.println("Awaiting for all runners");
    }
}
