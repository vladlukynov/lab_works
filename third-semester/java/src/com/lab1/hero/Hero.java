package com.lab1.hero;

import com.lab1.strategies.MovingStrategy;

public class Hero {
    private Point position;
    private MovingStrategy movingStrategy;

    public Hero() {
        position = new Point(0.0, 0.0);
    }

    public void setMovingStrategy(MovingStrategy movingStrategy) {
        this.movingStrategy = movingStrategy;
    }

    public Point getPosition() {
        return position;
    }

    public void moveHero(Point finishPoint) {
        if (this.movingStrategy == null) {
            System.err.println("Not set moving strategy!");
            return;
        }
        movingStrategy.moveHero(this.position, finishPoint);
        this.position = finishPoint;
        System.out.println("New location: (" + finishPoint.x + ";" + finishPoint.y + ")");
    }
}
