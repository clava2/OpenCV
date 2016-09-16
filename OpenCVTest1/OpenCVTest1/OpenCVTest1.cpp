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

int main(int argc, char* argv[])
{

	if (argc != 2)
	{
		cout << "输入的参数格式不正确！" << endl;
		return 1;
	}
	Mat Input = imread(argv[1]);
	if (!Input.data)
	{
		cout << "加载失败！" << endl; 
		return 2;
	}

	Mat Output = Input.clone();
	medianBlur(Input, Output, XR);

	namedWindow("Original");
	namedWindow("Target");

	imshow("Original", Input);
	imshow("Target", Output);

	waitKey(0);
	return 0;
}