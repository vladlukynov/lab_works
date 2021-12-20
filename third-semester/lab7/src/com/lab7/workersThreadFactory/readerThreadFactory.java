package com.lab7.workersThreadFactory;

import java.util.concurrent.ThreadFactory;

public class readerThreadFactory implements ThreadFactory {

    private int readerCount;

    public readerThreadFactory() {
        readerCount = 0;
    }

    @Override
    public Thread newThread(Runnable r) {
        readerCount++;
        String name = "reader " + readerCount;
        return new Thread(r, name);
    }
}
