package com.lections.lection12;

import com.lections.lection11.ExecutorExamples;
import com.lections.lection9.utils.Utils;

import java.util.Random;
import java.util.concurrent.*;

public class CompletionServiceExample {
    static class Task implements Callable<String> {
        private int id;
        private int millis;

        public Task(int id, int millis) {
            this.id = id;
            this.millis = millis;
        }

        @Override
        public String call() throws Exception {
            Utils.pause(millis);
            return id + ": " + millis;
        }
    }

    public static void main(String[] args) {
        ExecutorService service = Executors.newCachedThreadPool();

        ExecutorCompletionService<String> completionService = new ExecutorCompletionService<>(service);

        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            completionService.submit(new Task(i, random.nextInt(7000) + 3000));
        }

        for (int i = 0; i < 10; i++) {
            try {
                Future<String> future = completionService.take();
                System.out.println(future.get());
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }

        service.shutdown();
    }
}
