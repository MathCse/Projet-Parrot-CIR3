#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <control.h>
#include <image.h>

using namespace std;
using namespace cv;



class ImageProcessing : public sumo::Image
{
public:
	void handleImage(const struct sumo::image *, const uint8_t *buffer, size_t size)
	{
    std::vector<uint8_t> v;
    v.assign(buffer, buffer+size);
    cv::Mat img = cv::imdecode(v, CV_LOAD_IMAGE_COLOR);
    cout << "receive frame" << endl; //ttest
		fprintf(stderr, "received image of %zu bytes at %p\n", size, buffer);
	}
};

int main(){
  VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.

  if (!stream1.isOpened()) { //check if video device has been initialised
    cout << "cannot open camera";
  }

  //unconditional loop

  sumo::Control sumo(new ImageProcessing);

  while (true) {
    Mat cameraFrame;
    Mat dest;
    stream1.read(cameraFrame);
    flip(cameraFrame, cameraFrame, 1);
    medianBlur ( cameraFrame, dest, 15 );
    int radius = 50;
    Point center(150, 150 );
    circle(cameraFrame, center, radius, cv::Scalar(0, 255, 0), 5);

    Mat img_hsv;
    cvtColor(cameraFrame,img_hsv,CV_RGB2HSV);
    

    imshow("cam", cameraFrame);
    imshow("result", dest);
    imshow("hsv", img_hsv);
      if (waitKey(30) >= 0){
          cout << "test" << endl;
          cout << "batteryLevel: " << sumo.batteryLevel();
          //sumo.highJump();
          break;
      }
    }
    return 0; // retour 0
  }
