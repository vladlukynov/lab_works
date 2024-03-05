#include "include/functions.hpp"

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include <iostream>
#include <stdexcept>
#include <glut.h>

#include "include/draw_functions.hpp"

change_mode_t CHANGE_MODE = LIGHT_CHANGE;
unsigned int texture;
GLfloat cameraAngle = 0.0;
GLfloat lightningRColor = 1.0;
GLfloat lightningGColor = 1.0;
GLfloat lightningBColor = 1.0;
GLfloat light = 1.0;
const char TEXTURE_FILE_PATH[] = "../../../lab2/texture.png";

void initTexture() {
    GLint width;
    GLint height;
    GLint cnt;
    unsigned char *data = stbi_load(TEXTURE_FILE_PATH,
                                    &width, &height, &cnt, 0);
    if (data == nullptr) {
        throw std::runtime_error("Image reading error");
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
                     0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

void createLighting() {
    GLfloat colorLightning[] = {light * lightningRColor,
                                light * lightningGColor,
                                light * lightningBColor};

    glPushMatrix();
    {
        GLfloat position[] = {0.0, 1.0, 0.0, 1.0};

        glLightfv(GL_LIGHT0, GL_POSITION, position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, colorLightning);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, colorLightning);
        glLightfv(GL_LIGHT0, GL_SPECULAR, colorLightning);
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.796, 0.89, 0.859, 1.0);

    glPushMatrix();
    {
        glTranslatef(0.0, 0.0, -4.0);

        glPushMatrix();
        {
            glTranslatef(0.0, 0.0, 2.0);
            glRotatef(-45.0, 0.0, 1.0, 0.0);
            glRotatef(cameraAngle, 0.0, 0.0, 1.0);
            createLighting();
        }
        glPopMatrix();

        glPushMatrix();
        {
            glTranslatef(0.7, -0.3, -0.5);
            glRotatef(30, 1.0, 1.0, 0.0);
            drawCube(0.6);
        }
        glPopMatrix();

        glPushMatrix();
        {
            glTranslatef(-0.6, -0.5, -1.0);
            glRotatef(-60.0, 1.0, 0.0, 0.0);
            drawTorus(0.2, 0.5, 50, 50);
        }
        glPopMatrix();

        glPushMatrix();
        {
            glTranslatef(0.0, 0.0, 2.0);
            glRotatef(30.0, 1.0, 0.0, 0.0);
            drawCone(0.25, 0.5, 50, 50);
        }
        glPopMatrix();
    }
    glPopMatrix();

    glFlush();
}

void idle() {
    cameraAngle = cameraAngle < 360.0 ? cameraAngle + (GLfloat) 0.1 : (GLfloat) 0.0;
    display();
}

void changeMode(bool isNext = true) {
    if (CHANGE_MODE == LIGHT_CHANGE) {
        std::cout << (isNext ? "R-color changing mode selected\n" : "B-color changing mode selected\n");
        CHANGE_MODE = isNext ? R_CHANGE : B_CHANGE;
        return;
    }
    if (CHANGE_MODE == R_CHANGE) {
        std::cout << (isNext ? "G-color changing mode selected\n" : "Light changing mode selected\n");
        CHANGE_MODE = isNext ? G_CHANGE : LIGHT_CHANGE;
        return;
    }
    if (CHANGE_MODE == G_CHANGE) {
        std::cout << (isNext ? "B-color changing mode selected\n" : "R-color changing mode selected\n");
        CHANGE_MODE = isNext ? B_CHANGE : R_CHANGE;
        return;
    }
    std::cout << (isNext ? "Light changing mode selected\n" : "G-color changing mode selected\n");
    CHANGE_MODE = isNext ? LIGHT_CHANGE : G_CHANGE;
}

void changeParameter(bool isUp = true) {
    if (CHANGE_MODE == LIGHT_CHANGE) {
        light = (isUp && (light < 1.0)) ? light + (GLfloat) 0.1 :
                (!isUp && (light > 0.0)) ? light - (GLfloat) 0.1 : light;
        return;
    }
    if (CHANGE_MODE == R_CHANGE) {
        lightningRColor = (isUp && (lightningRColor < 1.0)) ? lightningRColor + (GLfloat) 0.1 :
                          (!isUp && (lightningRColor > 0.0)) ? lightningRColor - (GLfloat) 0.1 : lightningRColor;
        return;
    }
    if (CHANGE_MODE == G_CHANGE) {
        lightningGColor = (isUp && (lightningGColor < 1.0)) ? lightningGColor + (GLfloat) 0.1 :
                          (!isUp && (lightningGColor > 0.0)) ? lightningGColor - (GLfloat) 0.1 : lightningGColor;
        return;
    }
    lightningBColor = (isUp && (lightningBColor < 1.0)) ? lightningBColor + (GLfloat) 0.1 :
                      (!isUp && (lightningBColor > 0.0)) ? lightningBColor - (GLfloat) 0.1 : lightningBColor;
}

void specialKeyHandle(int key, int, int) {
    if (key == GLUT_KEY_RIGHT) {
        changeMode();
    } else if (key == GLUT_KEY_LEFT) {
        changeMode(false);
    } else if (key == GLUT_KEY_UP) {
        changeParameter();
    } else if (key == GLUT_KEY_DOWN) {
        changeParameter(false);
    }
}
