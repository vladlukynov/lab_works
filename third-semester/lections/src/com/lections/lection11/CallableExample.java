package com.lections.lection11;

import com.lections.lection9.utils.Utils;

import java.util.concurrent.*;

public class CallableExample {
    static class Task implements Callable<String> {
        @Override
        public String call() throws Exception {
            System.out.println("Start");
            Utils.pause(5000);
            System.out.println("Finish");
            return "done";
        }
    }

    public static void main(String[] args) {
        ExecutorService service = Executors.newSingleThreadExecutor();

        Future<String> future = service.submit(new Task());
        System.out.println("Task submitted");

        try {
            Utils.pause(3000);
            System.out.println("Get result");
            String result = future.get();
            System.out.println(result);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }

        service.shutdown();
    }
}
