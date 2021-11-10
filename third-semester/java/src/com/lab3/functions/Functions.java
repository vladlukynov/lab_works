package com.lab3.functions;

import com.lab3.animals.*;
import com.lab3.queue.Queue;

import java.util.Scanner;

public class Functions {
    public static Queue<Chordates> produce(Class<? extends Chordates> upperBoundClass) {
        Queue<Chordates> queue = new Queue<>();
        if (upperBoundClass.isAssignableFrom(Chordates.class)) {
            queue.add(new Chordates());
        }
        if (upperBoundClass.isAssignableFrom(Mammals.class)) {
            queue.add(new Mammals());
        }
        if (upperBoundClass.isAssignableFrom(Carnivores.class)) {
            queue.add(new Carnivores());
        }
        if (upperBoundClass.isAssignableFrom(Feline.class)) {
            queue.add(new Feline());
        }
        if (upperBoundClass.isAssignableFrom(Cats.class)) {
            queue.add(new Cats());
        }
        if (upperBoundClass.isAssignableFrom(Cat.class)) {
            queue.add(new Cat());
        }
        return queue;
    }

    public static Queue<Chordates> consume(Class<? super Cat> lowerBoundClass,
                                           Queue<Chordates> upperBoundQueue) {
        Queue<Chordates> queue = new Queue<>();
        while (!upperBoundQueue.isEmpty()) {
            Chordates chordates = upperBoundQueue.get();
            if (chordates.getClass().isAssignableFrom(lowerBoundClass)) {
                queue.add(chordates);
            }
        }
        return queue;
    }

    public static Class<? extends Chordates> selectUpperBoundClass() throws IllegalArgumentException {
        System.out.println("""
                Upper bound generic
                Select class:
                1. Chordates
                2. Mammals
                3. Carnivores
                4. Feline
                5. Cats
                6. Cat""");
        int selectedClass = inputClassNumber();
        return switch (selectedClass) {
            case 1 -> Chordates.class;
            case 2 -> Mammals.class;
            case 3 -> Carnivores.class;
            case 4 -> Feline.class;
            case 5 -> Cats.class;
            case 6 -> Cat.class;
            default -> throw new IllegalArgumentException("Wrong number");
        };
    }

    public static Class<? super Cat> selectLowerBoundClass() throws IllegalArgumentException {
        System.out.println("""
                Lower bound generic
                Select class:
                1. Chordates
                2. Mammals
                3. Carnivores
                4. Feline
                5. Cats
                6. Cat""");
        int selectedClass = inputClassNumber();
        return switch (selectedClass) {
            case 1 -> Chordates.class;
            case 2 -> Mammals.class;
            case 3 -> Carnivores.class;
            case 4 -> Feline.class;
            case 5 -> Cats.class;
            case 6 -> Cat.class;
            default -> throw new IllegalArgumentException("Wrong number");
        };
    }

    public static int inputClassNumber() throws IllegalArgumentException {
        Scanner scanner = new Scanner(System.in);
        int selectedClass;
        if (scanner.hasNextInt()) {
            selectedClass = scanner.nextInt();
        } else {
            throw new IllegalArgumentException("Input is not a number");
        }
        return selectedClass;
    }
}
