package com.lab2.exceptions;

public class DivideByZeroException extends RuntimeException {
    public DivideByZeroException(String errorMessage) {
        super(errorMessage);
    }
}
