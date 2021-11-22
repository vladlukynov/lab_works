package com.lab2.functions;

import com.lab2.exceptions.DivideByZeroException;
import com.lab2.exceptions.FileNotFoundException;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;

public class Functions {
    public static void inputMatrix(double[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                matrix[i][j] = (-1) * matrix.length + Math.random() * (matrix.length * 2 + 1);
            }
        }
    }

    public static void outputMatrix(double[][] matrix, String path, boolean append) {
        DecimalFormat decimalFormat = new DecimalFormat("#.##");
        File file = new File(path);
        if (!file.exists()) {
            throw new FileNotFoundException("Output file not found");
        }
        try (FileWriter fileWriter = new FileWriter(path, append)) {
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix.length; j++) {
                    fileWriter.write(decimalFormat.format(matrix[i][j]) + " ");
                }
                fileWriter.write("\n");
            }
            fileWriter.write("\n");
        } catch (IOException error) {
            System.err.println("Error with output stream");
            System.exit(1);
        }
    }

    public static void rotateMatrix(double[][] matrix) {
        double[][] temp = new double[matrix.length][matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                temp[i][j] = matrix[j][matrix.length - i - 1];
            }
        }
        copyMatrix(matrix, temp);
    }

    public static void calculateMatrix(double[][] matrix) {
        double[][] temp = new double[matrix.length][matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                double sumOfElements = 0;
                if (i > 0) {
                    sumOfElements += matrix[i - 1][j];
                }
                if (i < matrix.length - 1) {
                    sumOfElements += matrix[i + 1][j];
                }
                if (j > 0) {
                    sumOfElements += matrix[i][j - 1];
                }
                if (j < matrix.length - 1) {
                    sumOfElements += matrix[i][j + 1];
                }
                if (sumOfElements != 0) {
                    temp[i][j] = matrix[i][j] / sumOfElements;
                } else {
                    throw new DivideByZeroException("Divide by zero");
                }
            }
        }
        copyMatrix(matrix, temp);
    }

    public static void copyMatrix(double[][] matrix1, double[][] matrix2) {
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1.length; j++) {
                matrix1[i][j] = matrix2[i][j];
            }
        }
    }
}
