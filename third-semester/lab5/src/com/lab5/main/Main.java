package com.lab5.main;

import java.util.ArrayList;
import java.util.Map;

import static com.lab5.tasks.Tasks.*;

public class Main {
    public static void main(String[] args) {
        try {
            System.out.println("----- Task 1 -----");
            ArrayList<Integer> intList1 = new ArrayList<>();
            intList1.add(1);
            intList1.add(2);
            intList1.add(3);
            intList1.add(4);
            intList1.add(5);
            System.out.println("Average: " + task1(intList1));

            System.out.println("----- Task 2 -----");
            ArrayList<String> strList1 = new ArrayList<>();
            strList1.add("str1");
            strList1.add("str2");
            strList1.add("str3");
            System.out.println("Strings: " + task2(strList1));

            System.out.println("----- Task 3 -----");
            ArrayList<Integer> intList2 = new ArrayList<>();
            intList2.add(1);
            intList2.add(2);
            intList2.add(3);
            intList2.add(4);
            intList2.add(4);
            intList2.add(5);
            intList2.add(5);
            System.out.println("Squared values: " + task3(intList2));

            System.out.println("----- Task 4 -----");
            ArrayList<String> strList2 = new ArrayList<>();
            strList2.add("simple");
            strList2.add("auto");
            strList2.add("apple");
            strList2.add("car");
            System.out.println("Strings: " + task4(strList2));

            System.out.println("----- Task 5 -----");
            ArrayList<Integer> intList3 = new ArrayList<>();
            intList3.add(1);
            intList3.add(3);
            intList3.add(2);
            System.out.println("Last element: " + task5(intList3));

            System.out.println("----- Task 6 -----");
            int[] intArray = {1, 2, 3, 4, 5};
            System.out.println("Sum: " + task6(intArray));

            System.out.println("----- Task 7 -----");
            ArrayList<String> strList3 = new ArrayList<>();
            strList3.add("simple");
            strList3.add("apple");
            strList3.add("car");
            Map<String, String> strMap = task7(strList3);
            System.out.println("Map:");
            strMap.forEach((k, v) -> System.out.println(k + v));
        } catch (IllegalArgumentException error) {
            System.err.println(error.getMessage());
        }
    }
}
