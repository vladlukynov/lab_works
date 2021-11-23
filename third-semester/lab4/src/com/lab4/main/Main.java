package com.lab4.main;

import com.lab4.annotations.Repeat;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Main {

    public static void main(String[] args) {
        try {
            execute();
        } catch (InvocationTargetException | IllegalAccessException error) {
            System.err.println(error.getMessage());
        }
    }

    public static void execute() throws InvocationTargetException, IllegalAccessException {
        Cat cat = new Cat();
        Class<? extends Cat> catClass = cat.getClass();
        Method[] methods = catClass.getDeclaredMethods();
        for (Method m : methods) {
            m.setAccessible(true);
            if (m.isAnnotationPresent(Repeat.class)) {
                int repeatNum = m.getAnnotation(Repeat.class).value();
                for (int i = 0; i < repeatNum; i++) {
                    m.invoke(cat);
                }
            }
        }
    }
}
