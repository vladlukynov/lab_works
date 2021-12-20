package com.lections.lection11;

import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.*;

public class MatrixExample {
    public static void main(String[] args) {
        double[][] matrix = generateMatrix(10000, 10000);

        int cores = Runtime.getRuntime().availableProcessors();
        ExecutorService service = Executors.newFixedThreadPool(cores);

        evaluate(() -> {
            List<Future<Double>> futures = new LinkedList<>();
            for (double[] doubles : matrix) {
                Future<Double> f = service.submit(new RowTask(doubles));
                futures.add(f);
            }
            double sum = 0;
            for (Future<Double> f : futures) {
                try {
                    sum += f.get();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } catch (ExecutionException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("sum = " + sum);
            service.shutdown();
            try {
                service.awaitTermination(1, TimeUnit.HOURS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
    }

    static class RowTask implements Callable<Double> {
        private final double[] row;

        RowTask(double[] row) {
            this.row = row;
        }

        @Override
        public Double call() {
            double sum = 0;
            for (double v : row) {
                sum += calculate(v);
            }
            return sum;
        }
    }

    public static double calculate(double n) {
        double result = 0;
        for (int i = 0; i < 10; i++) {
            result += Math.pow(Math.sin(Math.pow(n, Math.E)) / Math.cos(Math.pow(n, Math.E)), Math.PI);
        }
        return result;
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
