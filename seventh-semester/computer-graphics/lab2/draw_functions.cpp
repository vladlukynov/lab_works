#include "include/draw_functions.hpp"

#include <glut.h>

GLfloat ambientDefaultParameters[] = {0.2, 0.2, 0.2, 1.0};
GLfloat diffuseDefaultParameters[] = {0.8, 0.8, 0.8, 1.0};
GLfloat specularDefaultParameters[] = {0.0, 0.0, 0.0, 1.0};
GLfloat shininessDefaultParameter = 0.0;

void drawCone(GLdouble radius, GLdouble height, GLint slices, GLint stacks) {
    GLfloat shininessParameter = 30.0;
    GLfloat ambientParameters[] = {0.4, 0.5, 0.6, 0.6};
    GLfloat diffuseParameters[] = {0.4, 0.3, 0.2, 0.6};
    GLfloat specularParameters[] = {0.4, 0.2, 0.3, 1.0};

    glMaterialf(GL_FRONT, GL_SHININESS, shininessParameter);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientParameters);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseParameters);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularParameters);

    glPushMatrix();
    {
        glRotatef(-90, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, -(GLfloat) height / (GLfloat) 2.0);
        glutSolidCone(radius, height, slices, stacks);
    }
    glPopMatrix();
}

void drawCube(GLfloat size) {
    GLfloat vertex[] = {-size / (GLfloat) 2.0, -size / (GLfloat) 2.0, 0,
                        size / (GLfloat) 2.0, -size / (GLfloat) 2.0, 0,
                        size / (GLfloat) 2.0, size / (GLfloat) 2.0, 0,
                        -size / (GLfloat) 2.0, size / (GLfloat) 2.0, 0};

    GLfloat sideTexCoord[] = {0.0, 1.0 / 3.0, 0.25, 1.0 / 3.0,
                              0.25, 0.0, 0.0, 0.0};
    GLfloat topTexCoord[] = {0.5, 2.0 / 3.0, 0.75, 2.0 / 3.0,
                             0.75, 1.0 / 3.0, 0.5, 1.0 / 3.0};
    GLfloat bottomTexCoord[] = {0.0, 2.0 / 3.0, 0.25, 2.0 / 3.0,
                                0.25, 1.0 / 3.0, 0.0, 1.0 / 3.0};
    GLfloat normal[] = {-1.0, -1.0, 3.0,
                        1.0, -1.0, 3.0,
                        1.0, 1.0, 3.0,
                        -1.0, 1.0, 3.0};

    glMaterialf(GL_FRONT, GL_SHININESS, shininessDefaultParameter);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientDefaultParameters);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseDefaultParameters);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularDefaultParameters);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glPushMatrix();
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);

        glTexCoordPointer(2, GL_FLOAT, 0, sideTexCoord);
        glNormalPointer(GL_FLOAT, 0, normal);
        for (int i = 0; i < 4; i++) {
            glPushMatrix();
            {
                glRotatef((GLfloat) 90.0 * (GLfloat) i, 0.0, 1.0, 0.0);
                glTranslatef(0.0, 0.0, size / (GLfloat) 2.0);
                glVertexPointer(3, GL_FLOAT, 0, vertex);
                glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            }
            glPopMatrix();
        }
        glTexCoordPointer(2, GL_FLOAT, 0, bottomTexCoord);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, size / (GLfloat) 2.0);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        glRotatef(180, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, size);
        glTexCoordPointer(2, GL_FLOAT, 0, topTexCoord);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
    }

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawTorus(GLfloat innerRadius, GLfloat outerRadius, GLint slices, GLint stacks) {
    glPushMatrix();
    {
        GLfloat shininessParameter = 128.0;
        GLfloat ambientParameters[] = {0.6, 0.2, 0.3, 1.0};
        GLfloat diffuseParameters[] = {0.6, 0.2, 0.3, 1.0};
        GLfloat specularParameters[] = {0.4, 0.4, 0.4, 1.0};

        glMaterialf(GL_FRONT, GL_SHININESS, shininessParameter);
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambientParameters);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseParameters);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specularParameters);

        glutSolidTorus(innerRadius, outerRadius, slices, stacks);
    }
    glPopMatrix();
}
