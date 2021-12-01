package com.lab5.tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Map;
import java.util.stream.Collectors;

public class Tasks {
    public static double task1(ArrayList<Integer> intList) throws IllegalArgumentException {
        if (intList.isEmpty()) {
            throw new IllegalArgumentException("Task 1. Empty list");
        }
        System.out.println("Collection: " + intList);
        return intList.stream()
                .mapToInt(n -> n).average().getAsDouble();
    }

    public static ArrayList<String> task2(ArrayList<String> strList) throws IllegalArgumentException {
        if (strList.isEmpty()) {
            throw new IllegalArgumentException("Task 2. Empty list");
        }
        System.out.println("Strings: " + strList);
        return strList.stream()
                .map(String::toUpperCase)
                .map(n -> "_new_" + n)
                .collect(Collectors.toCollection(ArrayList::new));
    }

    public static ArrayList<Integer> task3(ArrayList<Integer> intList) throws IllegalArgumentException {
        if (intList.isEmpty()) {
            throw new IllegalArgumentException("Task 3. Empty list");
        }
        System.out.println("Collection: " + intList);
        return intList.stream()
                .distinct()
                .map(n -> n * n)
                .collect(Collectors.toCollection(ArrayList::new));
    }

    public static ArrayList<String> task4(ArrayList<String> strList) throws IllegalArgumentException {
        if (strList.isEmpty()) {
            throw new IllegalArgumentException("Task 4. Empty list");
        }
        System.out.println("Strings: " + strList);
        final String firstLetter = "a";
        System.out.println("First letter: " + firstLetter);
        return strList.stream()
                .filter(n -> n.startsWith(firstLetter))
                .sorted()
                .collect(Collectors.toCollection(ArrayList::new));
    }

    public static Object task5(Collection<?> collection) throws IllegalArgumentException {
        if (collection.isEmpty()) {
            throw new IllegalArgumentException("Task 5. Empty collection");
        }
        System.out.println("Collection: " + collection);
        return collection.stream()
                .toArray()[collection.size() - 1];
    }

    public static int task6(int[] intArray) {
        System.out.println("Collection: " + Arrays.toString(intArray));
        return Arrays.stream(intArray)
                .filter(n -> n % 2 == 0)
                .sum();
    }

    public static Map<String, String> task7(ArrayList<String> strList) throws IllegalArgumentException {
        if (strList.isEmpty()) {
            throw new IllegalArgumentException("Task 7. Empty list");
        }
        System.out.println("Strings: " + strList);
        return strList.stream()
                .collect(Collectors.toMap(n -> n.substring(0, 1), n -> n.substring(1)));
    }
}
