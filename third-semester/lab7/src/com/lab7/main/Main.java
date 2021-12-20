package com.lab7.main;

import com.lab7.workers.*;
import com.lab7.workersThreadFactory.readerThreadFactory;
import com.lab7.workersThreadFactory.writerThreadFactory;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.SynchronousQueue;

public class Main {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Wrong number of arguments");
            System.exit(1);
        }

        int countOfThreads = 0;
        try {
            countOfThreads = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            System.err.println("Input is not a number");
            System.exit(1);
        }

        SynchronousQueue<String> queue = new SynchronousQueue<>();

        ExecutorService writerExecutor = Executors.newFixedThreadPool(countOfThreads, new writerThreadFactory());
        ExecutorService readerExecutor = Executors.newFixedThreadPool(countOfThreads, new readerThreadFactory());

        Writer writer = new Writer(queue);
        Reader reader = new Reader(queue);

        for (int i = 0; i < countOfThreads; i++) {
            writerExecutor.execute(writer);
            readerExecutor.execute(reader);
        }

        writerExecutor.shutdown();
        readerExecutor.shutdown();
    }
}
