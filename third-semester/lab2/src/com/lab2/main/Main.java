package com.lab2.main;

import java.io.*;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

import com.lab2.exceptions.*;
import com.lab2.exceptions.FileNotFoundException;

import static com.lab2.functions.Functions.*;

public class Main {
    public static void main(String[] args) {
        String inputPath = "input.txt";
        String outputPath = "output.txt";
        int N = 0;
        try (FileInputStream fileInputStream = new FileInputStream(inputPath);
             Scanner scanner = new Scanner(fileInputStream)) {
            N = scanner.nextInt();
        } catch (InputMismatchException error) {
            System.err.println("Wrong input. Check file \"" + inputPath + "\"");
            System.exit(1);
        } catch (NoSuchElementException error) {
            System.err.println("\"" + inputPath + "\" is empty");
            System.exit(1);
        } catch (IOException error) {
            System.err.println("Error with input stream");
            System.exit(1);
        }

        try {
            if ((N < 2) || (N > 1000000)) {
                throw new InvalidMatrixSizeException("Invalid size");
            }
            double[][] matrix1 = new double[N][N];
            double[][] matrix2 = new double[N][N];
            double[][] matrix3 = new double[N][N];
            inputMatrix(matrix1);
            copyMatrix(matrix2, matrix1);
            copyMatrix(matrix3, matrix1);

            rotateMatrix(matrix1);
            calculateMatrix(matrix1);
            outputMatrix(matrix1, outputPath, false);

            rotateMatrix(matrix2);
            rotateMatrix(matrix2);
            calculateMatrix(matrix2);
            outputMatrix(matrix2, outputPath, true);

            rotateMatrix(matrix3);
            rotateMatrix(matrix3);
            rotateMatrix(matrix3);
            calculateMatrix(matrix3);
            outputMatrix(matrix3, outputPath, true);
        } catch (InvalidMatrixSizeException | DivideByZeroException | FileNotFoundException error) {
            System.err.println(error.getMessage());
            System.exit(1);
        }
    }
}
