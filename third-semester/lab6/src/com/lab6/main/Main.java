package com.lab6.main;

import com.lab6.abstractProgram.AbstractProgram;
import com.lab6.superVisor.SuperVisor;

public class Main {

    public final static Object mutex = new Object();

    public static void main(String[] args) {
        AbstractProgram abstractProgram = new AbstractProgram();
        SuperVisor superVisor = new SuperVisor(abstractProgram);
        Thread superVisorThread = new Thread(superVisor);
        superVisorThread.start();
    }
}
