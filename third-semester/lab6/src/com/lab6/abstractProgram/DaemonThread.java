package com.lab6.abstractProgram;

import java.util.Random;

import static com.lab6.main.Main.mutex;

public class DaemonThread implements Runnable {
    final private AbstractProgram target;

    DaemonThread(AbstractProgram target) {
        this.target = target;
    }

    @Override
    public void run() {
        while (target.getStatus() != AbstractProgram.ProgramStatus.FATAL_ERROR) {
            synchronized (mutex) {
                Random random = new Random();
                if (!target.getReadyToChange()) {
                    try {
                        mutex.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                target.setStatus(AbstractProgram.ProgramStatus.class.getEnumConstants()[random.nextInt(AbstractProgram.ProgramStatus.class.getEnumConstants().length)]);
                System.out.println("Daemon. Set status " + target.getStatus());
                try {
                    Thread.sleep(2000);
                    target.setReadyToChange(false);
                    mutex.notify();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
