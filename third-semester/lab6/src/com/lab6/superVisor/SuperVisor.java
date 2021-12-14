package com.lab6.superVisor;

import com.lab6.abstractProgram.AbstractProgram;

import static com.lab6.abstractProgram.AbstractProgram.ProgramStatus.*;
import static com.lab6.main.Main.mutex;

public class SuperVisor implements Runnable {
    final private AbstractProgram target;

    public SuperVisor(AbstractProgram target) {
        this.target = target;
    }

    @Override
    public void run() {
        System.out.println("Started SuperVisor");
        Thread abstractProgramThread = new Thread(target);
        abstractProgramThread.start();
        while (target.getStatus() != FATAL_ERROR) {
            synchronized (mutex) {
                if (target.getReadyToChange()) {
                    try {
                        mutex.wait();
                    } catch (InterruptedException error) {
                        error.printStackTrace();
                    }
                }
                if ((target.getStatus() == AbstractProgram.ProgramStatus.UNKNOWN) ||
                        (target.getStatus() == AbstractProgram.ProgramStatus.STOPPING)) {
                    System.out.println("SuperVisor. Current status: " + target.getStatus());
                    System.out.println("SuperVisor. Program restarted. Set status " + AbstractProgram.ProgramStatus.RUNNING);
                    target.setStatus(AbstractProgram.ProgramStatus.RUNNING);
                }
                target.setReadyToChange(true);
                mutex.notify();
            }
        }
        System.out.println("SuperVisor. " + FATAL_ERROR + ". Interrupt abstract program");
        abstractProgramThread.interrupt();
    }
}
