#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using std::cout;
using std::cin;
using std::endl;

const int XR = 10;
const int YR = 10;

void showImage( int Value);

Mat Input;
Mat InputGray;
Mat Output;

int TrackValue1 = 3;
int TrackValue2 = 0;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "输入的参数不正确！" << endl;
		return 1;
	}

	Input = imread(argv[1]);

	cvtColor(Input, InputGray, CV_BGR2GRAY);

	namedWindow("Window1");

	cvCreateTrackbar("Track1", "Window1", &TrackValue1,4,showImage);

	cvCreateTrackbar("Track2", "Window1", &TrackValue2, 255, showImage);

	showImage(0);

	waitKey(0);
}

void showImage(int Value)
{
	threshold(InputGray, Output, Value, 255, TrackValue1);
	imshow("Window1", Output);
}