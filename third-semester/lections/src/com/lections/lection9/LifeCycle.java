package com.lections.lection9;

import com.lections.lection9.utils.Utils;

public class LifeCycle {
    public static void main(String[] args) {
        Thread t = new Thread(() -> {
            Utils.pause(10000);
            System.out.println(Thread.currentThread());
        });
        System.out.println(t.getState());
        t.start();
        System.out.println(t.getState());

        /*for (int i = 0; i < 12; i++) {
            Utils.pause(1000);
            System.out.println(t.getState());
        }*/

        try {
            t.join(5000);
        } catch (InterruptedException error) {
            error.printStackTrace();
        }
        System.out.println(t.getState());
    }
}
