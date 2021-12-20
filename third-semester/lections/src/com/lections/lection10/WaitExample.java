package com.lections.lection10;

import com.lections.lection9.utils.Utils;
import jdk.jshell.execution.Util;

public class WaitExample {

    public static void main(String[] args) {
        Object mutex = new Object();
        new Thread(() -> {
            System.out.println("Start run");
            synchronized (mutex) {
                System.out.println("Locked mutex");
                try {
                    Utils.pause(5000);
                    System.out.println("Before wait");
                    mutex.wait(10000);
                    System.out.println("awoke");
                    Utils.pause(5000);
                } catch (InterruptedException error) {
                    error.printStackTrace();
                }
                System.out.println("Unlocked mutex");
            }
        }).start();

        Utils.pause(1000);
        System.out.println("Main is trying to lock mutex");
        synchronized (mutex) {
            System.out.println("Main locked mutex");
            Utils.pause(3000);
        }
        System.out.println("Main unlocked mutex");
    }
}
