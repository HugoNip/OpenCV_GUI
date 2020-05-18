#include <iostream>
#include <sstream>
#include <string>

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

const int CV_GUI_NORMAL = 0x10;

int main (int argc, const char** argv)
{
    // Read images
    cv::Mat lena = cv::imread("../lena.jpg");
    // Create windows
    cv::namedWindow("Lena");
    // Show images
    cv::imshow("Lena", lena);

    // Display overlay
    cv::displayOverlay("Lena", "Overlay 5 secs", 5000);

    // Display status Bar
    cv::displayStatusBar("Lena", "Status bar 5secs", 5000);

    // save window parameters
    cv::saveWindowParameters("Lena");

    // Load window parameters
    cv::loadWindowParameters("Lena");

    // wait for any key press
    cv::waitKey(0);

    // Destroy the windows
    cv::destroyWindow("Lena");

    return 0;
}