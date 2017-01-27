#include "detection.h"
int DetectLines(Mat& src, Mat& dst)
{
    Mat cdst;
    Canny(src, dst, 50, 200, 3);
    cvtColor(dst, cdst, COLOR_GRAY2BGR);

    vector<Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 10);
    //if (lines.size()>300000){
    for (size_t i = 0; i < lines.size(); i++)
    {
        Vec4i l = lines[i];
        line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, 2);
    }
    //}

    return 0;
}

int detectColor(Mat& src, Mat& dst, int H_MIN, int H_MAX , int S_MIN,int S_MAX, int V_MIN, int  V_MAX ){
   Mat3b bgr = src;

   Mat3b hsv;
   cvtColor(bgr, hsv, COLOR_BGR2HSV);

    Mat1b mask1, mask2;
    inRange(hsv, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), mask1);
    //inRange(hsv, Scalar(170, 70, 50), Scalar(180, 255, 255), mask2);

    //inRange(bgr, Scalar(90, 235, 235), Scalar(0, 0, 85), mask2); //BGR

    Mat1b mask = mask1 | mask2;
		Mat element = Mat();

		dst = mask;
		/// Apply the erosion operation
		erode( dst, dst, element);
		dilate( dst, dst, element );
		dilate( dst, dst, element );
    return 1;
}


OurCircle findPoint(Mat& filter){
			vector<vector<Point> > contours;
			vector<Vec4i> heirarchy;
			vector<Point2i> center;
			vector<int> radius;


    cv::findContours( filter.clone(), contours, heirarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);

size_t count = contours.size();


for(unsigned int i=0; i<count; i++)
{
    cv::Point2f c;
    float r;
    cv::minEnclosingCircle( contours[i], c, r);

    //if (!enableRadiusCulling || r >= minTargetRadius)
    //{
        center.push_back(c);
        radius.push_back(r);
    //}
}

	size_t count2 = center.size();

	int max = 0;
	unsigned int maxi = 0;
	for(unsigned int i = 0; i < count2; i++)
	{
	  // cv::circle(cameraFrame, center[i], radius[i], red, 3);
	  if(radius[i] >= max){
	    maxi = i;
	    max = radius[i];
	  }
	}
	if(!center.empty() && radius.size() == center.size() && maxi < center.size()){
		OurCircle c;
		c.center = center[maxi];
		c.radius = max;
		c.exist = true;
		return c;
	}else{
		OurCircle c;
		c.exist = false;
		return c;
	}
}
