package com.lections.lection10;

import com.lections.lection9.utils.Utils;

import java.util.LinkedList;
import java.util.List;

public class KillThreads {
    static class Car {
        String engine;
        String hull;
        String wheels;

        @Override
        public String toString() {
            return "Car{" +
                    "engine='" + engine + '\'' +
                    ", hull='" + hull + '\'' +
                    ", wheels='" + wheels + '\'' +
                    '}';
        }
    }

    static void constructCar(Car car) {
        Utils.pause(1000);
        car.engine = "M-300";
        Utils.pause(1000);
        car.hull = "H-Truck";
        Utils.pause(1000);
        car.wheels = "Pirelli";
    }

    public static void main(String[] args) {
        List<Car> cars = new LinkedList<>();

        Thread t = new Thread(() -> {
            while (true) {
                Car car = new Car();
                cars.add(car);
                constructCar(car);
                System.out.println("Ready car" + cars.size());
            }
        });
        t.start();

        Utils.pause(12000);
        t.stop();

        cars.stream().forEach(System.out::println);
    }
}
