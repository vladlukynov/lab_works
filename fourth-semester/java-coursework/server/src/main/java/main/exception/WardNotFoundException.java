package main.exception;

public class WardNotFoundException extends RuntimeException {
    public WardNotFoundException(String message) {
        super(message);
    }
}
