#include <iostream>
#include <string>
#include <sstream>

// Opencv includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

// Create a variable to save the position value in track
int blurAmount = 15;

// Trackbar call back function
static void onChange(int pos, void* userInput);

// Mouse callback
static void onMouse(int event, int x, int y, int, void* userInput);

int main (int argc, char** argv)
{
    // Read images
    cv::Mat lena = cv::imread("../lena.jpg");

    // Create windows
    cv::namedWindow("LenaW");

    // Create a trackbark
    cv::createTrackbar("LenaT", "LenaW", &blurAmount, 30, onChange, &lena);
    cv::setMouseCallback("LenaW", onMouse, &lena);

    // Call to onChange to init
    onChange(blurAmount, &lena);

    // wait app for a key to exit
    cv::waitKey(0);

    // destroy the windows
    cv::destroyWindow("LenaW");

    return 0;
}

// Trackbar call back function
static void onChange(int pos, void* userInput)
{
    if(pos <= 0)
        return;
    // Aux variable for result
    cv::Mat imgBlur;

    // get the pointer input image
    cv::Mat* img = (cv::Mat*)userInput;

    // apply a blur filter
    cv::blur(*img, imgBlur, cv::Size(pos, pos));

    // show the result
    cv::imshow("LenaW", imgBlur);
}

// Mouse callback
static void onMouse(int event, int x, int y, int, void* userInput)
{
    if (event!= cv::EVENT_LBUTTONDOWN)
        return;
    // get the pointer input image
    cv::Mat* img = (cv::Mat*)userInput;

    // Draw circle
    cv::circle(*img, cv::Point(x, y), 10, cv::Scalar(0, 255, 0), 3);

    // call on change ro get blurred image
    onChange(blurAmount, img);
}

