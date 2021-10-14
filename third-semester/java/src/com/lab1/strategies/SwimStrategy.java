package com.lab1.strategies;

import com.lab1.hero.Point;

public class SwimStrategy implements MovingStrategy {
    private final double speed;

    {
        speed = 2.0;
    }

    @Override
    public void moveHero(Point startPoint, Point finishPoint) {
        double distance = Point.getDistance(finishPoint, startPoint);
        System.out.println("Hero swim from (" + startPoint.x + ";" + startPoint.y + ") to (" + finishPoint.x + ";" + finishPoint.y + ")");
        System.out.printf("Distance: %.2f points\n", distance);
        System.out.println("Speed: " + speed + " points/sec");
        System.out.printf("Time spent: %.2f sec\n", distance / speed);
    }
}
