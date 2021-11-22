package com.lab2.exceptions;

public class InvalidMatrixSizeException extends RuntimeException {
    public InvalidMatrixSizeException(String errorMessage) {
        super(errorMessage);
    }
}
