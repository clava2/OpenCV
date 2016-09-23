#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

Mat InputImage, Target;
Mat MapX, MapY;

const char* TargetWindowName = "Target";
int ind = 0;

void UpdateMap(void);

int main(int argc, char* argv[])
{

	if (argc != 2)
	{
		cout << "²ÎÊý´íÎó£¡" << endl;
		return 1;
	}
	InputImage = imread(argv[1]);
	Target.create(InputImage.size(), InputImage.type());
	MapX.create(InputImage.size(), CV_32FC1);
	MapY.create(InputImage.size(), CV_32FC1);

	namedWindow(TargetWindowName);
	while (true)
	{
		int c = waitKey(1000);
		if (c == '\n')
		{
			break;
		}

		UpdateMap();
		remap(InputImage,Target, MapX, MapY, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));

		imshow(TargetWindowName, Target);

	}

	return 0;
}

void UpdateMap(void)
{
	ind = ind % 4;
	for (int j = 0; j != InputImage.rows; ++j)
	{
		for (int i = 0; i != InputImage.cols; ++i)
		{
			switch (ind)
			{
			case 0:
				if (i > InputImage.cols * 0, 25 && i < InputImage.cols*0.75&&j>InputImage.rows*0.25&&j < InputImage.rows*0.75)
				{
					MapX.at<float>(j, i) = 2 * (i - InputImage.cols*0.25) + 0.5;
					MapY.at<float>(j, i) = 2 * (j - InputImage.cols*0.25) + 0.5;
				}
				else
				{
					MapX.at<float>(j, i) = 0;
					MapY.at<float>(j, i) = 0;
				}
				break;
			case 1:
				MapX.at<float>(j, i) = i;
				MapY.at<float>(j, i) = InputImage.rows - j;
				break;
			case 2:
				MapX.at<float>(j, i) = InputImage.cols - i;
				MapY.at<float>(j, i) = j;
				break;
			case 3:
				MapX.at<float>(j, i) = InputImage.cols - i;
				MapY.at<float>(j, i) = InputImage.rows - j;
				break;
			}
		}
	}
	ind++;
}