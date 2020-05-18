#include <iostream>
#include <string>
#include <sstream>

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, const char** argv)
{
    // Read images
    cv::Mat lena = cv::imread("../lena.jpg");
    // Checking if Lena image has been loaded
    if (!lena.data){
        std::cout << "Lena image missing!" << std::endl;
        return -1;
    }

    // Read images
    cv::Mat photo = cv::imread("../photo.jpg");
    // Checking if Lena image has been loaded
    if (!photo.data){
        std::cout << "photo image missing!" << std::endl;
        return -1;
    }

    // Create images
    cv::namedWindow("Lena", cv::WINDOW_NORMAL);
    cv::namedWindow("Photo", cv::WINDOW_AUTOSIZE);

    // Move window
    cv::moveWindow("Lena", 10, 10);
    cv::moveWindow("Photo", 520, 10);

    // Show images
    cv::imshow("Lena", lena);
    cv::imshow("Photo", photo);

    // Resize window, only non autosize
    cv::resizeWindow("Lena", 512, 512);

    // wait for any key press
    cv::waitKey(0);

    // Destroy
    cv::destroyWindow("Lena");
    cv::destroyWindow("Photo");

    // Create 10 windows
    for (int i = 0; i < 10; i++)
    {
        std::ostringstream ss;
        ss << "Photo" << i;
        cv::namedWindow(ss.str());
        cv::moveWindow(ss.str(), 20*i, 20*i);
        cv::imshow(ss.str(), photo);
    }

    cv::waitKey(0);

    // Destroy all windows
    cv::destroyAllWindows();

    return 0;
}