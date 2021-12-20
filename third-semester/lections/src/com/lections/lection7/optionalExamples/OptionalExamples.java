package com.lections.lection7.optionalExamples;

import java.util.NoSuchElementException;
import java.util.Optional;

public class OptionalExamples {
    public static void main(String[] args) {
        System.out.println("--- Creation examples (5) ---");
        createOptional();

        System.out.println("--- Present examples (10) ---");
        presentExamples();

        System.out.println("--- else examples (13) ---");
        elseExamples();
    }

    private static void createOptional() {
        Optional<Cat> cat = Optional.of(new Cat("Cat", 5, 6));
        System.out.println("Cat: " + cat);

        Optional<Cat> nullCat = Optional.ofNullable(null);
        System.out.println("Null cat: " + nullCat);

        Optional<Cat> empty = Optional.empty();
        System.out.println("Empty cat: " + empty);
    }

    private static void presentExamples() {
        Optional<Cat> optionalCat = Optional.of(new Cat("Cat", 5, 6));
        if (optionalCat.isPresent()) {
            System.out.println(optionalCat.get().getName());
        }

        Optional<Cat> emptyCat = Optional.empty();
        if (emptyCat.isPresent()) {
            System.out.println(emptyCat.get());
        } else {
            System.out.println("No value");
        }
    }

    private static void elseExamples() {
        Optional<Cat> optionalCat = Optional.of(new Cat("Cat", 5, 6));
        Optional<Cat> emptyCat = Optional.empty();
        Cat emergencyCat = new Cat("Murzik", 3, 5);
        System.out.println(optionalCat.orElse(emergencyCat));
        System.out.println(emptyCat.orElse(emergencyCat));

        System.out.println(optionalCat.orElseGet(() -> emergencyCat));
        System.out.println(emptyCat.orElseGet(() -> emergencyCat));

        System.out.println(optionalCat.orElseThrow());
        try {
            System.out.println(emptyCat.orElseThrow());
        } catch (NoSuchElementException error) {
            System.err.println("No cat :( " + error.getMessage());
        }
    }

    private static class Cat {
        public Cat(String name, int age, int weight) {
            this.name = name;
            this.age = age;
            this.weight = weight;
        }

        @Override
        public String toString() {
            return "Cat{name=" + name + ",age=" + age + ",weight=" + weight + "}";
        }

        public String getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        String name;
        int age;
        int weight;
    }
}
