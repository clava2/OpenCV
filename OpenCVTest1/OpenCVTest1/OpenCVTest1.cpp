#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	float BlendRate = 0.5;
	if (argc == 1)
	{
		cout << "用法：输入两个图片的路径，然后加上混合率，此程序将会将两张图片混合" << endl;
		return 1;
	}
	if (argc == 2)
	{
		cout << "输入的图片路径太少！" << endl;
		return 2;
	}
	if (argc == 3)
	{
		cout << "没有输入混合率，将会均匀混合！" << endl;
	}
	if (argc == 4)
	{
		BlendRate = atof(argv[3]);
	}

	Mat Input1 = imread(argv[1]);
	if (!Input1.data)
	{
		cout << "读取图片1的内容时出错！" << endl;
		return 3;
	}
	
	Mat Input2 = imread(argv[2]);
	if (!Input2.data)
	{
		cout << "读取图片2的内容时出错！" << endl;
		return 4;
	}

	addWeighted(Input1, BlendRate, Input2, 1 - BlendRate, 0.0, Input1);

	namedWindow("Blending");
	imshow("Blending", Input1);

	waitKey(0);
}