package com.lections.lection9;

import com.lections.lection9.utils.Utils;

import java.util.Random;

public class DaemonExample {
    static int stock;

    public static void main(String[] args) {
        System.out.println("Start");

        Thread t = new Thread(() -> {
            Random random = new Random();
            while (true) {
                stock = random.nextInt(1000);
                Utils.pause(1000);
            }
        });

        t.setDaemon(true);
        t.start();

        for (int i = 0; i < 10; i++) {
            Utils.pause(2000);
            System.out.println("Stock = " + stock);
        }

        System.out.println("Finish");
    }
}
