package com.lab1.strategies;

import com.lab1.hero.Point;

public interface MovingStrategy {
    void moveHero(Point startPoint, Point finishPoint);
}
