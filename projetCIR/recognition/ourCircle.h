#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
class OurCircle{
	public:
		Point2i center;
		int radius;
		bool exist = false;
};
