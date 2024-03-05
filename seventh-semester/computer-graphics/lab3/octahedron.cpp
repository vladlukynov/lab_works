#define _USE_MATH_DEFINES
#define STB_IMAGE_IMPLEMENTATION

#include <cmath>
#include <ctime>
#include <stb_image.h>
#include <stdexcept>
#include <glut.h>

#include "include/glut_functions.hpp"
#include "include/octahedron.hpp"

unsigned int texture;

Octahedron::Octahedron() {
    this->position = new GLdouble[3] {0.0, 0.0, 0.0};
    this->rotateAngle = 0.0;
    this->liftAngle = 0.0;
    this->size = 1.0;
    this->rotateDirection = false;
    this->squareSideAnimationAngle = 0.0;
    this->triangleAnimationAngle = 0.0;
    initTexture();
}

Octahedron::Octahedron(GLdouble size, GLdouble* position) {
    this->position = new GLdouble[3] {position[0], position[1], position[2]};
    this->rotateAngle = 0.0;
    this->liftAngle = 0.0;
    this->size = size;
    this->rotateDirection = false;
    this->squareSideAnimationAngle = 0.0;
    this->triangleAnimationAngle = 0.0;
    initTexture();
}

Octahedron::~Octahedron() {
    delete[] this->position;
}

void Octahedron::startSquareSideAnimation() {
    const GLdouble maxSquareSideAnimationAngle = (std::asin(2.0 * std::sqrt(2.0) / 3.0) * 180.0) / M_PI;

    GLdouble currentTime = 0.0;
    GLdouble startTime = std::clock() / (double) CLOCKS_PER_SEC;
    
    GLdouble deltaY = (0.5 - std::sqrt(6.0) / 6.0) * this->size;
    GLdouble startX = this->position[0];
    GLdouble startY = this->position[1];
    GLdouble startZ = this->position[2];

    do {
        currentTime = std::clock() / (double) CLOCKS_PER_SEC;
        
        GLdouble rotateAngleRad = this->rotateAngle * M_PI / 180.0;

        this->squareSideAnimationAngle = (currentTime - startTime) * maxSquareSideAnimationAngle;
        this->position[0] = startX - 2 * (currentTime - startTime) * (std::sqrt(3.0) / 6.0 * this->size) * std::cos(rotateAngleRad);
        this->position[1] = startY + deltaY * std::sin(M_PI * (currentTime - startTime));
        this->position[2] = startZ + 2 * (currentTime - startTime) * (std::sqrt(3.0) / 6.0 * this->size) * std::sin(rotateAngleRad);

        display();
    } while (currentTime < startTime + 1.0);

    this->squareSideAnimationAngle = 0.0;
    this->rotateAngle += 180.0;
    display();
}

// void drawCube(GLfloat size) {
//     GLfloat vertex[] = {-size / (GLfloat) 2.0, -size / (GLfloat) 2.0, 0,
//                         size / (GLfloat) 2.0, -size / (GLfloat) 2.0, 0,
//                         size / (GLfloat) 2.0, size / (GLfloat) 2.0, 0,
//                         -size / (GLfloat) 2.0, size / (GLfloat) 2.0, 0};

//     GLfloat sideTexCoord[] = {0.0, 1.0 / 3.0, 0.25, 1.0 / 3.0,
//                               0.25, 0.0, 0.0, 0.0};
//     GLfloat topTexCoord[] = {0.5, 2.0 / 3.0, 0.75, 2.0 / 3.0,
//                              0.75, 1.0 / 3.0, 0.5, 1.0 / 3.0};
//     GLfloat bottomTexCoord[] = {0.0, 2.0 / 3.0, 0.25, 2.0 / 3.0,
//                                 0.25, 1.0 / 3.0, 0.0, 1.0 / 3.0};
//     GLfloat normal[] = {-1.0, -1.0, 3.0,
//                         1.0, -1.0, 3.0,
//                         1.0, 1.0, 3.0,
//                         -1.0, 1.0, 3.0};

//     glMaterialf(GL_FRONT, GL_SHININESS, shininessDefaultParameter);
//     glMaterialfv(GL_FRONT, GL_AMBIENT, ambientDefaultParameters);
//     glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseDefaultParameters);
//     glMaterialfv(GL_FRONT, GL_SPECULAR, specularDefaultParameters);

//     glEnable(GL_TEXTURE_2D);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     glPushMatrix();
//     {
//         glEnableClientState(GL_VERTEX_ARRAY);
//         glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//         glEnableClientState(GL_NORMAL_ARRAY);

//         glTexCoordPointer(2, GL_FLOAT, 0, sideTexCoord);
//         glNormalPointer(GL_FLOAT, 0, normal);
//         for (int i = 0; i < 4; i++) {
//             glPushMatrix();
//             {
//                 glRotatef((GLfloat) 90.0 * (GLfloat) i, 0.0, 1.0, 0.0);
//                 glTranslatef(0.0, 0.0, size / (GLfloat) 2.0);
//                 glVertexPointer(3, GL_FLOAT, 0, vertex);
//                 glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//             }
//             glPopMatrix();
//         }
//         glTexCoordPointer(2, GL_FLOAT, 0, bottomTexCoord);
//         glRotatef(90.0, 1.0, 0.0, 0.0);
//         glTranslatef(0.0, 0.0, size / (GLfloat) 2.0);
//         glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

//         glRotatef(180, 1.0, 0.0, 0.0);
//         glTranslatef(0.0, 0.0, size);
//         glTexCoordPointer(2, GL_FLOAT, 0, topTexCoord);
//         glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

//         glDisableClientState(GL_VERTEX_ARRAY);
//         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//         glDisableClientState(GL_NORMAL_ARRAY);
//     }

//     glPopMatrix();

//     glDisable(GL_TEXTURE_2D);
//     glBindTexture(GL_TEXTURE_2D, 0);
// }

void Octahedron::startTriangleSideAnimation() {
    const GLdouble maxRotateAngle = 60.0;
    const GLdouble maxLiftAngleRad = M_PI / 4.0;
    const GLdouble minLiftAngleRad = std::asin(1.0 / std::sqrt(3.0));
    const GLdouble deltaLiftAngle = (maxLiftAngleRad - minLiftAngleRad) * 180.0 / M_PI;
    const GLdouble deltaY = (0.5 - 1.0 / std::sqrt(6.0)) * this->size;

    GLdouble startTime = std::clock() / (double) CLOCKS_PER_SEC;
    GLdouble currentTIme = 0.0;
    GLdouble startRotateAngle = this->rotateAngle;
    GLdouble startRotateAngleRad = this->rotateAngle * M_PI / 180.0;
    GLdouble startY = this->position[1];

    GLdouble radius = this->size / std::sqrt(3.0);
    GLdouble center[] = {this->position[0] + radius * std::cos(startRotateAngleRad),
                         this->position[2] - radius * std::sin(startRotateAngleRad)};

    do {
        currentTIme = std::clock() / (double) CLOCKS_PER_SEC;
        
        this->rotateAngle = startRotateAngle + ((this->rotateDirection) ? -maxRotateAngle * (currentTIme - startTime) : 
                                                                           maxRotateAngle * (currentTIme - startTime));
        GLdouble rotateAngleRad = this->rotateAngle * M_PI / 180.0;

        this->triangleAnimationAngle = this->rotateDirection ? 90.0 * (currentTIme - startTime) : -90.0 * (currentTIme - startTime);
        this->liftAngle = deltaLiftAngle * std::sin(M_PI * (currentTIme - startTime));

        this->position[0] = center[0] - radius * std::cos(rotateAngleRad);
        this->position[1] = startY + deltaY * std::sin(M_PI * (currentTIme - startTime));
        this->position[2] = center[1] + radius * std::sin(rotateAngleRad);

        display();
    } while (currentTIme < startTime + 1.0);
}

void Octahedron::reverseRotateDirection() {
    this->rotateDirection = !this->rotateDirection;
}

void Octahedron::initTexture() {
    GLint width;
    GLint height;
    GLint cnt;
    unsigned char *data = stbi_load("../../../lab3/brick.jpg",
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

void Octahedron::draw() {
    GLfloat sideTexCoord[] = {0.0, 0.0, 0.0, 1.0,
                              1.0, 1.0, 1.0, 0.0};

    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, sideTexCoord);

    glPushMatrix();
    {
        glTranslated(this->position[0], this->position[1], this->position[2]);
        glRotated(this->rotateAngle, 0.0, 1.0, 0.0);
        glRotated(-this->liftAngle, 0.0, 0.0, 1.0);

        // For Square Side
        glRotated(this->squareSideAnimationAngle, 0.0, 0.0, 1.0);

        this->drawFigure();
    }
    glPopMatrix();

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);
        glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glDisable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Octahedron::drawFigure() {
    const GLdouble initInclinationAngle = (std::atan(std::sqrt(2.0)) * 180.0) / M_PI;

    glPushMatrix();
    {
        GLdouble scaleCoeff = this->size / std::sqrt(2.0);
        glRotated(initInclinationAngle, 0.0, 0.0, 1.0);
        glRotated(45.0, 0.0, 1.0, 0.0);

        // For Triangle Side
        glRotated(this->triangleAnimationAngle, 0.0, 1.0, 0.0);
        
        glScaled(scaleCoeff, scaleCoeff, scaleCoeff);
        glutSolidOctahedron();
    }
    glPopMatrix();
}
