#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <sstream>
#include <iostream>
#include <string>

using namespace cv;
using std::cout; using std::cerr; using std::endl;

int main(int, char**)
{
    Mat frame;
    std::stringstream ss;
    long int nFrames = 0;
    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture capture;
    // OR advance usage: select any API backend
    int deviceID = 2;              // 2 = open /dev/video2
    int apiID = cv::CAP_V4L2;      // CAP_V4L2 = linux API
    // open selected camera using selected API
    capture.open(deviceID + apiID);
    // check if we succeeded
    if (!capture.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    std::string name = "img_";
    std::string type = ".jpg";
    for (;;)
    {
        capture >> frame; // read the next frame from camera
        if (frame.empty())
        {
            cerr << "ERROR: Can't grab camera frame." << endl;
            break;
        }
        nFrames++;
        {
        ss<<"imgFolder"<<"/"<<name<<nFrames<<type;
        std::string filename = ss.str();
        ss.str("");
        imwrite(filename, frame);
        }
        if (waitKey(1) == 27/*ESC*/)
        {
            break;
        }
    }
    std::cout << "Number of captured frames: " << nFrames << endl;
    return nFrames > 0 ? 0 : 1;
}