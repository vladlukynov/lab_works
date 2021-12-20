package com.lections.lection9;

import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class MatrixExample {
    public static void main(String[] args) {
        double[][] matrix = generateMatrix(20, 1000000);
        evaluate(() -> {
            for (double[] doubles : matrix) {
                for (double aDouble : doubles) {
                    double result = calculate(aDouble);
                }
            }
        });
        evaluate(() -> {
            List<Thread> threadList = new LinkedList<>();

            for (double[] doubles : matrix) {
                Thread t = new Thread(new RowTask(doubles));
                threadList.add(t);
            }

            for (Thread t : threadList) {
                try {
                    t.join();
                } catch (InterruptedException error) {
                    error.printStackTrace();
                }
            }
        });
    }

    static class RowTask implements Runnable {
        private final double[] row;

        RowTask(double[] row) {
            this.row = row;
        }

        @Override
        public void run() {
            for (double v : row) {
                double result = calculate(v);
            }
        }
    }

    public static double calculate(double n) {
        return Math.pow(Math.sin(Math.pow(n, Math.E)) / Math.cos(Math.pow(n, Math.E)), Math.PI);
    }

    private static void evaluate(Runnable task) {
        long start = System.currentTimeMillis();
        task.run();
        long stop = System.currentTimeMillis();
        long elapsed = stop - start;
        System.out.println("Elapsed: " + elapsed);
    }

    public static double[][] generateMatrix(int rows, int cols) {
        double[][] matrix = new double[rows][cols];
        Random random = new Random();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = random.nextDouble();
            }
        }
        return matrix;
    }
}
