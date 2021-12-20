package com.lections.lection7.lambda;

import java.util.ArrayList;
import java.util.List;

@FunctionalInterface
interface LambdaExp {
    int calc(int value1, int value2);
}

@FunctionalInterface
interface Condition {
    boolean checkCondition(int value);
}

public class LambdaExpression {
    public static void main(String[] args) {
        System.out.println("Пример лямбда-выражения");
        final int value1_ = 6;
        final int value2_ = 3;

        LambdaExp lambdaExp1 = new LambdaExp() {
            @Override
            public int calc(int value1, int value2) {
                return value1 * value2;
            }
        };

        LambdaExp lambdaExp2 = (value1, value2) -> value1 * value2;

        int result1 = lambdaExp1.calc(value1_, value2_);
        int result2 = lambdaExp2.calc(value1_, value2_);

        System.out.println(result1 + " " + result2);

        System.out.println("Передача лямбда-выражения как параметр метода");
        Condition condition = value -> value < 5;
        int[] numbers = {1, 3, 5, 7, 9};
        printNumbersFromArray(numbers, condition);
        printNumbersFromArray(numbers, value -> value == 5);

        System.out.println("Ссылка на метод");
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.forEach(System.out::print);
        System.out.println();
        list.forEach(i -> System.out.print(i));
        System.out.println();

        System.out.println("Возврат лямбда-выражения как результат метода");
        System.out.println(value1_ + " + " + value2_ + " = " + superCalc(value1_, value2_, createLambda(1)));
        System.out.println(value1_ + " - " + value2_ + " = " + superCalc(value1_, value2_, createLambda(2)));
        System.out.println(value1_ + " * " + value2_ + " = " + superCalc(value1_, value2_, createLambda(3)));
        System.out.println(value1_ + " / " + value2_ + " = " + superCalc(value1_, value2_, createLambda(4)));
    }

    private static void printNumbersFromArray(int[] array, Condition condition) {
        boolean isFirst = true;
        for (int i : array) {
            if (isFirst) {
                if (condition.checkCondition(i)) {
                    System.out.print(i);
                    isFirst = false;
                }
            } else {
                if (condition.checkCondition(i)) {
                    System.out.print(" " + i);
                }
            }
        }
        System.out.println();
    }

    private static int superCalc(int value1, int value2, LambdaExp lambdaExp) {
        return lambdaExp.calc(value1, value2);
    }

    private static LambdaExp createLambda(int num) {
        return switch (num) {
            case 1 -> (value1, value2) -> value1 + value2;
            case 2 -> (value1, value2) -> value1 - value2;
            case 3 -> (value1, value2) -> value1 * value2;
            case 4 -> (value1, value2) -> value1 / value2;
            default -> (value1, value2) -> 0;
        };
    }
}
