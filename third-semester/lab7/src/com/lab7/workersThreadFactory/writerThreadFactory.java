package com.lab7.workersThreadFactory;

import java.util.concurrent.ThreadFactory;

public class writerThreadFactory implements ThreadFactory {

    private int writerCount;

    public writerThreadFactory() {
        writerCount = 0;
    }

    @Override
    public Thread newThread(Runnable r) {
        writerCount++;
        String name = "writer " + writerCount;
        return new Thread(r, name);
    }
}
