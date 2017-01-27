#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "ourCircle.h"

int DetectLines(Mat& src, Mat& dst);
int detectColor(Mat& src, Mat& dst, int H_MIN, int H_MAX , int S_MIN,int S_MAX, int V_MIN, int  V_MAX );
OurCircle findPoint(Mat& filter);
