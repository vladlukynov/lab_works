package com.lab2.exceptions;

public class FileNotFoundException extends RuntimeException {
    public FileNotFoundException(String errorMessage) {
        super(errorMessage);
    }
}
