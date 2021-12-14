package com.lab6.abstractProgram;

public class AbstractProgram implements Runnable {

    public enum ProgramStatus {UNKNOWN, STOPPING, RUNNING, FATAL_ERROR}

    private ProgramStatus programStatus;
    private boolean readyToChange;

    public AbstractProgram() {
        programStatus = ProgramStatus.STOPPING;
        readyToChange = false;
    }

    @Override
    public void run() {
        programStatus = ProgramStatus.RUNNING;
        System.out.println("Abstract program running with status " + programStatus);
        Thread daemonThread = new Thread(new DaemonThread(this));
        daemonThread.setDaemon(true);
        daemonThread.start();
    }

    public void setReadyToChange(boolean readyToChange) {
        this.readyToChange = readyToChange;
    }

    public boolean getReadyToChange() {
        return readyToChange;
    }

    public void setStatus(ProgramStatus status) {
        this.programStatus = status;
    }

    public ProgramStatus getStatus() {
        return programStatus;
    }
}
