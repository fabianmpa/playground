/**
  @file videocapture_basic.cpp
  @brief A very basic sample for using VideoCapture and VideoWriter
  @author PkLab.net
  @date Aug 24, 2016
*/

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat frame,tracked,flipped,transposed,weighted,test,kale2,kale(400,400,CV_8UC3,Scalar(0,0,0));
char TrackbarName[50];
double alpha;
double beta;
int alpha_slider = 0;
const int alpha_slider_max = 100;

string type2str(int type) {
  string r;
  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);
  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }
  r += "C";
  r += (chans+'0');
  return r;
}

static void on_trackbar( int , void* )
{
   alpha = (double) alpha_slider/alpha_slider_max ;
   beta = ( 1.0 - alpha );
	 addWeighted( tracked, alpha, flipped, beta, 0.0, weighted);
   imshow( "Linear Blend", weighted );
}

int main(int, char**)
{
    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap;
    // OR advance usage: select any API backend
    int deviceID = 2;              // 2 = open /dev/video2
    int apiID = cv::CAP_V4L2;      // CAP_V4L2 = linux API
    // open selected camera using selected API
    cap.open(deviceID + apiID);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    //sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );
    //namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window
    //createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );
    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl << "Press any key to terminate" << endl;
    //string ty =  type2str( test.type() );
    //printf("Matrix: %s %dx%d \n", ty.c_str(), test.cols, test.rows );
		for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
				tracked = frame;
        if (frame.empty())
				{
          cerr << "ERROR! blank frame grabbed\n";
          break;
        }
        flip(tracked,flipped, 0); //flip around x axis
				//imshow("Flipped0",flipped);
        //flip(frame,flipped, 1); //flip around y axis
				//imshow("Flipped1",flipped);
        //flip(frame,flipped,-1); //flip around both axis
				//imshow("Flipped-1",flipped);
				//transpose(frame,transposed);
				//imshow("Transposed",transposed);
		    resize(frame,frame,Size(400,400));
		    for(int i=0;i<600;i++)
		    {
		    	for(int j=0;j<i/3;j++)
		    	{
		    			kale.at<uchar>(Point(i,j))=frame.at<uchar>(Point(i,j));//gives 1/8 of img
		    		if(j>i)
		    		{
		    			continue;
		    		}
		    	}
		    }
        flip(kale,kale2,0);
        addWeighted(kale,1,kale2,1,0,test);
        flip(kale2,kale2,1);
        addWeighted(test,1,kale2,1,0,test);
        flip(kale2,kale2,0);
        addWeighted(test,1,kale2,1,0,test);
        transpose(kale2,kale2);
        addWeighted(test,1,kale2,1,0,test);
        flip(kale2,kale2,0);
        addWeighted(test,1,kale2,1,0,test);
        flip(kale2,kale2,1);
        addWeighted(test,1,kale2,1,0,test);
        flip(kale2,kale2,0);
        addWeighted(test,1,kale2,1,0,test);
        //line(frame,Point(200,0),Point(200,200),Scalar(0,255,255),1);
        //line(frame,Point(0,0),Point(200,200),Scalar(0,255,255),1);
        //imshow("frame",frame);
        imshow("Kaleidoscope",test);
        //on_trackbar( alpha_slider, 0 );
        // show live and wait for a key with timeout long enough to show images
        if (waitKey(1) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}