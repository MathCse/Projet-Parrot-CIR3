#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>



#include <control.h>
#include <image.h>
#include <unistd.h>

using namespace cv;
using namespace std;

class OurCircle{
	public:
		Point2i center;
		int radius;
		bool exist;
};


class ImageProcessing : public sumo::Image
{
public:
	void handleImage(const struct sumo::image *, const uint8_t *buffer, size_t size)
	{
    cout << "receive frame" << endl; //ttest
    std::vector<uint8_t> v;
    //v.assign(buffer, buffer+size);
    //cv::Mat img = cv::imdecode(v, CV_LOAD_IMAGE_COLOR);
		fprintf(stderr, "received image of %zu bytes at %p\n", size, buffer);
	}
};
int H_MIN_GREEN = 0;
int H_MAX_GREEN = 255;
int S_MIN_GREEN = 0;
int S_MAX_GREEN = 255;
int V_MIN_GREEN = 0;
int V_MAX_GREEN = 255;

int H_MIN_RED = 0;
int H_MAX_RED = 255;
int S_MIN_RED = 0;
int S_MAX_RED = 255;
int V_MIN_RED = 0;
int V_MAX_RED = 255;

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
}


OurCircle findPoint(Mat& filter){
			vector<vector<Point> > contours;
			vector<Vec4i> heirarchy;
			vector<Point2i> center;
			vector<int> radius;


    cv::findContours( filter.clone(), contours, heirarchy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);

size_t count = contours.size();


for( int i=0; i<count; i++)
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
	int maxi = 0;
	for( int i = 0; i < count2; i++)
	{
	  // cv::circle(cameraFrameOrigin, center[i], radius[i], red, 3);
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

void on_trackbar(int, void*)
{//This function gets called whenever a
	// trackbar position is changed
	//cout <<"H: " <<  H_MIN << ", " << H_MAX << endl;
}
void createTrackbars()
{
	String trackbarWindowName = "TrackBars";
	namedWindow(trackbarWindowName, WINDOW_NORMAL);
	createTrackbar("H_MIN_GREEN", trackbarWindowName, &H_MIN_GREEN, H_MAX_GREEN, on_trackbar);
	createTrackbar("H_MAX_GREEN", trackbarWindowName, &H_MAX_GREEN, H_MAX_GREEN, on_trackbar);
	createTrackbar("S_MIN_GREEN", trackbarWindowName, &S_MIN_GREEN, S_MAX_GREEN, on_trackbar);
	createTrackbar("S_MAX_GREEN", trackbarWindowName, &S_MAX_GREEN, S_MAX_GREEN, on_trackbar);
	createTrackbar("V_MIN_GREEN", trackbarWindowName, &V_MIN_GREEN, V_MAX_GREEN, on_trackbar);
	createTrackbar("V_MAX_GREEN", trackbarWindowName, &V_MAX_GREEN, V_MAX_GREEN, on_trackbar);

	createTrackbar("H_MIN_RED", trackbarWindowName, &H_MIN_RED, H_MAX_RED, on_trackbar);
	createTrackbar("H_MAX_RED", trackbarWindowName, &H_MAX_RED, H_MAX_RED, on_trackbar);
	createTrackbar("S_MIN_RED", trackbarWindowName, &S_MIN_RED, S_MAX_RED, on_trackbar);
	createTrackbar("S_MAX_RED", trackbarWindowName, &S_MAX_RED, S_MAX_RED, on_trackbar);
	createTrackbar("V_MIN_RED", trackbarWindowName, &V_MIN_RED, V_MAX_RED, on_trackbar);
	createTrackbar("V_MAX_RED", trackbarWindowName, &V_MAX_RED, V_MAX_RED, on_trackbar);

	setTrackbarPos("H_MIN_GREEN", trackbarWindowName, 64);
	setTrackbarPos("H_MAX_GREEN", trackbarWindowName, 136);
	setTrackbarPos("S_MIN_GREEN", trackbarWindowName, 183);
	setTrackbarPos("S_MAX_GREEN", trackbarWindowName, 255);
	setTrackbarPos("V_MIN_GREEN", trackbarWindowName, 95);
	setTrackbarPos("V_MAX_GREEN", trackbarWindowName, 164);

	setTrackbarPos("H_MIN_RED", trackbarWindowName, 129);
	setTrackbarPos("H_MAX_RED", trackbarWindowName, 255);
	setTrackbarPos("S_MIN_RED", trackbarWindowName, 146);
	setTrackbarPos("S_MAX_RED", trackbarWindowName, 255);
	setTrackbarPos("V_MIN_RED", trackbarWindowName, 151);
	setTrackbarPos("V_MAX_RED", trackbarWindowName, 255);


}

int main(int argc, char** argv)
{

		createTrackbars();
		on_trackbar(0, 0);

		//Ouverture du sumo
		sumo::Control * Sumo;
	  Sumo = new sumo::Control(new ImageProcessing);
		//Sumo->open();



    VideoCapture stream1(0);
    while(true){
      Mat cameraFrame;
			Mat redFilter;
			Mat greenFilter;

      stream1.read(cameraFrame);
      flip(cameraFrame, cameraFrame, 1);

      Mat cameraFrameOrigin = cameraFrame;
      detectColor(cameraFrame, redFilter, H_MIN_RED, H_MAX_RED, S_MIN_RED, S_MAX_RED, V_MIN_RED, V_MAX_RED);
			detectColor(cameraFrame, greenFilter, H_MIN_GREEN, H_MAX_GREEN, S_MIN_GREEN, S_MAX_GREEN, V_MIN_GREEN, V_MAX_GREEN);

			OurCircle redPoint;
			redPoint = findPoint(greenFilter);
			if(redPoint.exist){
				cv::Scalar blue(0,255,0);
				cv::circle(cameraFrame, redPoint.center, redPoint.radius, blue, 3);
			}

			OurCircle c;
			c = findPoint(redFilter);
			if(c.exist){
			  //cout << "center[" << maxi << "] : " << c.center.x <<   endl;
				cv::Scalar red(255,0,0);
			  cv::circle(cameraFrame, c.center, c.radius, red, 3);

			  if(c.center.x < redFilter.cols/3){
			    if(c.center.y < redFilter.rows/3){
			      cout << "Avancer gauche" << endl;
			      if(Sumo)
			        Sumo->move(10,-20);

			    }
			    else if(c.center.y < 2*redFilter.rows/3){
			      cout << "Gauche" << endl;
			      if(Sumo)
			        Sumo->move(10, -90);
			    }
			    else if(c.center.y < redFilter.rows){
			      cout << "Reculer gauche" << endl;
			      if(Sumo)
			        Sumo->move(-10, 20);

			    }
			  }
			  else if(c.center.x < 2*redFilter.cols/3){
			    if(c.center.y < redFilter.rows/3){
			      cout << "Avancer" << endl;
			      if(Sumo)
			        Sumo->move(15, 0);
			    }
			    else if(c.center.y < 2*redFilter.rows/3){
			      cout << "Arrêt" << endl;
			      if(Sumo)
			        Sumo->move(0,0);
			    }
			    else if(c.center.y < redFilter.rows){
			      cout << "Reculer" << endl;
			      if(Sumo)
			        Sumo->move(-30,0);
			    }
			  }
			  else if(c.center.x < redFilter.cols){
			    if(c.center.y < redFilter.rows/3){
			      cout << "Avancer droite" << endl;
			      if(Sumo)
			        Sumo->move(10, 20);
			    }
			    else if(c.center.y < 2*redFilter.rows/3){
			      cout << "Droite" << endl;
			      if(Sumo)
			        Sumo->move(10, 90);
			    }
			    else if(c.center.y < redFilter.rows){
			      cout << "Reculer droite" << endl;
			      if(Sumo)
			        Sumo->move(-10, -90);
			    }
			  }
			}else{
			  cout << "Arret" << endl;
			  if(Sumo)
			    Sumo->move(0,0);
			}

    //cout << "max : " << max << endl;
    //cout << "maxi: " << maxi << endl;
    //cout << "rows" << cameraFrame.rows << endl;
    //cout << "cols" << cameraFrame.cols << endl;
    imshow("Camera", cameraFrame);
		imshow("Red", redFilter);
		imshow("Green", greenFilter);


      //imshow("result", dest);
    if(waitKey(30)>=0)
      break;
    }

    return 0;
}
