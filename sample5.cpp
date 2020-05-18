#include <iostream>
#include <sstream>
#include <string>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

// OpenGL includes
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

cv::Mat frame;
GLfloat angle = 0.0;
GLuint texture;
cv::VideoCapture camera;

int loadTexture() {
    if (frame.data == NULL) return -1;

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, frame.cols, frame.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, frame.data);

    return 0;
}

void on_opengl(void* param)
{
    glLoadIdentity();
    // Load texture
    glBindTexture(GL_TEXTURE_2D, texture);
    // Rotate plane
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    // Create the plate
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex2d(-1.0, -1.0);
    glTexCoord2d(1.0, 0.0); glVertex2d(+1.0, -1.0);
    glTexCoord2d(1.0, 1.0); glVertex2d(+1.0, +1.0);
    glTexCoord2d(0.0, 1.0); glVertex2d(-1.0, +1.0);
    glEnd();
}

int main(int argc, char** argv) {
    // Open Webcam
    camera.open(0);
    if (!camera.isOpened()){
        camera.open("Recording3.webm");
        if (!camera.isOpened())
            return -1;
    }

    // Create new windows
    cv::namedWindow("OpenGL Camera", cv::WINDOW_OPENGL);

    // Enable texture
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture);

    cv::setOpenGlDrawCallback("OpenGL Camera", on_opengl);

    while (cv::waitKey(30) != 'q') {
        camera >> frame;
        // Create first texture
        loadTexture();
        cv::updateWindow("OpenGL Camera");
        angle = angle + 4;
    }

    cv::destroyWindow("OpenGL Camera");

    return 0;
}

