package com.lections.lection10;

import com.lections.lection9.utils.Utils;

public class MutexExample {
    final private Object mutex = new Object();

    void a() {
        System.out.println("Start a()");
        synchronized (mutex) {
            System.out.println("Locked mutex in a()");
            Utils.pause(10000);
            System.out.println("Unlocked mutex in a()");
        }
        System.out.println("Unlocked mutex in a()");
    }

    void b() {
        System.out.println("Start b()");
        synchronized (mutex) {
            System.out.println("Locked mutex in b()");
            Utils.pause(10000);
            System.out.println("Unlocked mutex in b()");
        }
        System.out.println("Finished b()");
    }

    public static void main(String[] args) {
        MutexExample me = new MutexExample();
        new Thread(me::a).start();
        new Thread(me::b).start();
    }
}
