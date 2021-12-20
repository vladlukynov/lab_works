package com.lections.lection9.utils;

public class Utils {
    public static void pause(int millis) {
        try {
            Thread.sleep(millis);
        } catch (InterruptedException error) {
            error.printStackTrace();
        }
    }
}
