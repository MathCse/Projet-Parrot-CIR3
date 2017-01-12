#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <string>
#include <control.h>
#include <image.h>
#include <unistd.h>

using namespace cv;
using namespace std;

class OurCircle{
	public:
		Point2i center;
		int radius;
		bool exist = false;
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

int H_MIN_GREEN_DEFAULT = 0;
int H_MAX_GREEN_DEFAULT = 255;
int S_MIN_GREEN_DEFAULT = 0;
int S_MAX_GREEN_DEFAULT = 255;
int V_MIN_GREEN_DEFAULT = 0;
int V_MAX_GREEN_DEFAULT = 255;

int H_MIN_RED_DEFAULT = 0;
int H_MAX_RED_DEFAULT = 255;
int S_MIN_RED_DEFAULT = 0;
int S_MAX_RED_DEFAULT = 255;
int V_MIN_RED_DEFAULT = 0;
int V_MAX_RED_DEFAULT = 255;


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


bool readDefaultCalibration(){
	ifstream infile("../default.par", ios::in);
	if(infile){
		string line;

		getline(infile, line);
		H_MIN_GREEN_DEFAULT = atoi(line.c_str());
		cout << "H_MIN GREEN DEFAULT" <<  H_MIN_GREEN_DEFAULT << endl;
		getline(infile, line);
		H_MAX_GREEN_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		S_MIN_GREEN_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		S_MAX_GREEN_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		V_MIN_GREEN_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		V_MAX_GREEN_DEFAULT = atoi(line.c_str());

		getline(infile, line);
		H_MIN_RED_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		H_MAX_RED_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		S_MIN_RED_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		S_MAX_RED_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		V_MIN_RED_DEFAULT = atoi(line.c_str());
		getline(infile, line);
		V_MAX_RED_DEFAULT = atoi(line.c_str());
		infile.close();
		return true;
	}

	return false;

}

bool writeDefaultCalibration(){
	ofstream infile("../default.par", ios::out);
	if(infile){
		infile << H_MIN_GREEN << endl;
		infile << H_MAX_GREEN << endl;
		infile << S_MIN_GREEN << endl;
		infile << S_MAX_GREEN << endl;
		infile << V_MIN_GREEN << endl;
		infile << V_MAX_GREEN << endl;

		infile << H_MIN_RED << endl;
		infile << H_MAX_RED << endl;
		infile << S_MIN_RED << endl;
		infile << S_MAX_RED << endl;
		infile << V_MIN_RED << endl;
		infile << V_MAX_RED << endl;
		infile.close();
		return true;
	}
	return false;
}


void on_trackbar(int, void*)
{//This function gets called whenever a
	// trackbar position is changed
	//cout <<"H: " <<  H_MIN << ", " << H_MAX << endl;
}
void createTrackbars()
{
	String trackbarWindowName = "TrackBars";
	readDefaultCalibration();
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

	setTrackbarPos("H_MIN_GREEN", trackbarWindowName, H_MIN_GREEN_DEFAULT);
	setTrackbarPos("H_MAX_GREEN", trackbarWindowName, H_MAX_GREEN_DEFAULT);
	setTrackbarPos("S_MIN_GREEN", trackbarWindowName, S_MIN_GREEN_DEFAULT);
	setTrackbarPos("S_MAX_GREEN", trackbarWindowName, S_MAX_GREEN_DEFAULT);
	setTrackbarPos("V_MIN_GREEN", trackbarWindowName, V_MIN_GREEN_DEFAULT);
	setTrackbarPos("V_MAX_GREEN", trackbarWindowName, V_MAX_GREEN_DEFAULT);

	setTrackbarPos("H_MIN_RED", trackbarWindowName, H_MIN_RED_DEFAULT);
	setTrackbarPos("H_MAX_RED", trackbarWindowName, H_MAX_RED_DEFAULT);
	setTrackbarPos("S_MIN_RED", trackbarWindowName, S_MIN_RED_DEFAULT);
	setTrackbarPos("S_MAX_RED", trackbarWindowName, S_MAX_RED_DEFAULT);
	setTrackbarPos("V_MIN_RED", trackbarWindowName, V_MIN_RED_DEFAULT);
	setTrackbarPos("V_MAX_RED", trackbarWindowName, V_MAX_RED_DEFAULT);
}


int main(int argc, char** argv)
{

		createTrackbars();
		on_trackbar(0, 0);

		//Ouverture du sumo
		sumo::Control * Sumo;
	  Sumo = new sumo::Control(new ImageProcessing);
		int sumoOk=0;

		if(sumoOk == 1){
			Sumo->open();
		}



    VideoCapture stream1(0);
		stream1.set(CV_CAP_PROP_FRAME_WIDTH, 800);
		stream1.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

    double deltaT=0;
    double fps = 15;
    OurCircle oldRedPoint;
    stream1.set(CV_CAP_PROP_FPS, fps);

		bool calibration = true;
		while (calibration){
			Mat redFilter;
			Mat greenFilter;
			Mat cameraFrame;
			stream1.read(cameraFrame);
			flip(cameraFrame, cameraFrame, 1);

			detectColor(cameraFrame, redFilter, H_MIN_RED, H_MAX_RED, S_MIN_RED, S_MAX_RED, V_MIN_RED, V_MAX_RED);
			detectColor(cameraFrame, greenFilter, H_MIN_GREEN, H_MAX_GREEN, S_MIN_GREEN, S_MAX_GREEN, V_MIN_GREEN, V_MAX_GREEN);
			Point2i smallWord;
			smallWord.x = 10;//cameraFrame.cols/2;
			smallWord.y = 10;

			//putText(cameraFrame, "Calibration vert", Point(20,20), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);

			imshow("Green calibration", greenFilter);
			imshow("Red calibration", redFilter);

			if(waitKey(30)>=0){
				writeDefaultCalibration();
				destroyAllWindows();
				break;
			}
		}

    while(true){
      string battery = " ";
      if(Sumo && sumoOk){
        //battery= to_string(Sumo->batteryLevel())+"%";
      }
      deltaT +=1/fps;

      Mat cameraFrame;
			Mat redFilter;
			Mat greenFilter;
      stream1.read(cameraFrame);
      flip(cameraFrame, cameraFrame, 1);
      Mat cameraFrameOrigin = cameraFrame;
      detectColor(cameraFrame, redFilter, H_MIN_RED, H_MAX_RED, S_MIN_RED, S_MAX_RED, V_MIN_RED, V_MAX_RED);
			detectColor(cameraFrame, greenFilter, H_MIN_GREEN, H_MAX_GREEN, S_MIN_GREEN, S_MAX_GREEN, V_MIN_GREEN, V_MAX_GREEN);
			OurCircle redPoint;
			redPoint = findPoint(redFilter);
       putText(cameraFrame, battery, Point(20,20) , FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);
			if(redPoint.exist){
				cv::Scalar blue(0,255,0);
				cv::circle(cameraFrame, redPoint.center, redPoint.radius, blue, 3);
        if(deltaT>=0.1){

          if(!oldRedPoint.exist){
            oldRedPoint = redPoint;
            cout << "coucou" << endl;
          } else {
            cout << (-oldRedPoint.center.y+redPoint.center.y)<< endl;
              if((-oldRedPoint.center.y+redPoint.center.y)<-60){
                std::cout << " JUMP! " << endl;
								if(sumoOk && Sumo){
                	Sumo->highJump();
								}
              }
          }
          deltaT = 0;
        }

        oldRedPoint = redPoint;

			} else{
        oldRedPoint.exist = false;
				OurCircle c;
				c = findPoint(greenFilter);
				double vitesse, angle;
				if(c.exist){
					Point2i smallWord = c.center;
	        smallWord.x -= 40;
	        smallWord.y += 10;
	        //cout << "center[" << maxi << "] : " << c.center.x <<   endl;
					cv::Scalar red(255,0,0);
	        cv::circle(cameraFrame, c.center, c.radius, red, 3);

	        if(c.center.x > 2*cameraFrame.cols/5 && c.center.x < 3*cameraFrame.cols/5 ){
	          angle = 0;
	          if(vitesse>0){
	            putText(cameraFrame, "Avancer", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	          }else if(vitesse<0){
	            putText(cameraFrame, "Reculer", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	          } else if (vitesse==0){
	            putText(cameraFrame, "Arret", smallWord, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
	          }
	        } else {
	          angle = (double)(-50/(double)(-cameraFrame.cols/2))*(-cameraFrame.cols/2+c.center.x);
	          if (vitesse>0){
	            if(angle>0){
	              putText(cameraFrame, "Avancer droite", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }else if(angle<0){
	              putText(cameraFrame, "Avancer gauche", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }
	          } else if (vitesse<0){
	            if(angle>0){
	              putText(cameraFrame, "Reculer droite", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }else if(angle<0){
	              putText(cameraFrame, "Reculer gauche", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }
	          } else if (vitesse ==0){
	             if(angle>0){
	              putText(cameraFrame, "Droite", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }else if(angle<0){
	              putText(cameraFrame, "Gauche", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	          }
	        } }

	        if(c.center.y > 2*cameraFrame.rows/5 && c.center.y < 3*cameraFrame.rows/5) {
	          vitesse = 0;
	          if(angle>0){
	            putText(cameraFrame, "Droite", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	          }else if(angle<0){
	            putText(cameraFrame, "Gauche", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	          } else if (angle==0){
	            putText(cameraFrame, "Arret", smallWord, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
	          }
	        } else {

	          vitesse =  (double)(100/(double)(cameraFrame.rows/2))*(-c.center.y+cameraFrame.rows/2);
	          if (vitesse>0){
	            if(angle>0){
	              putText(cameraFrame, "Avancer droite", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }else if(angle<0){
	              putText(cameraFrame, "Avancer gauche", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }
	          } else if (vitesse<0){
	            if(angle>0){
	              putText(cameraFrame, "Reculer droite", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }else if(angle<0){
	              putText(cameraFrame, "Reculer gauche", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }
	          } else if (vitesse== 0){
	             if(angle>0){
	              putText(cameraFrame, "Droite", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	            }else if(angle<0){
	              putText(cameraFrame, "Gauche", smallWord, FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 0, 255), 2);
	          }
	        }
	      }
	      } else {
	        vitesse = 0;
	        angle = 0;
	      }
				cout << "vitesse: " <<  vitesse << " angle: " << angle << endl;
        rectangle(cameraFrame, Point(10,50), Point(10+1.2*fabs(vitesse),70),Scalar(0, 0, 255), CV_FILLED);
				if(Sumo)
					Sumo->move(vitesse,angle);

			}




    imshow("Camera", cameraFrame);
		//imshow("camera2", cameraFrameOrigin);
		imshow("Red", redFilter);
		imshow("Green", greenFilter);


      //imshow("result", dest);
    if(waitKey(30)>=0)
      break;
    }

    return 0;
}
