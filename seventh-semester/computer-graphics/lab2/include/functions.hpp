#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

enum change_mode_t {
    LIGHT_CHANGE, R_CHANGE, G_CHANGE, B_CHANGE
};

void initTexture();
void createLighting();
void display();
void idle();
void changeMode(bool isNext);
void changeParameter(bool isUp);
void specialKeyHandle(int key, int, int);

#endif
