package com.lections.lection10;

import com.lections.lection9.utils.Utils;

import java.util.Random;

public class WaitNotifyExample {
    static String meal;
    static String[] meals = {"Steak", "Pasta", "IceCream", "Soup"};

    static Object bell = new Object();

    static class Cook implements Runnable {
        @Override
        public void run() {
            Random random = new Random();
            while (true) {
                int pause = 3000 + random.nextInt(3000);
                Utils.pause(pause);
                String readyMeal = meals[random.nextInt(meals.length)];
                System.out.println("Cook: " + readyMeal);
                synchronized (bell) {
                    meal = readyMeal;
                    bell.notify();
                }
            }
        }
    }

    static class Waiter implements Runnable {
        @Override
        public void run() {
            while (true) {
                synchronized (bell) {
                    while (meal == null) {
                        try {
                            bell.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    String readMeal = meal;
                    meal = null;
                    System.out.println("Waiter: " + readMeal);
                }
            }
        }
    }

    public static void main(String[] args) {
        new Thread(new Cook()).start();
        new Thread(new Waiter()).start();
    }
}
