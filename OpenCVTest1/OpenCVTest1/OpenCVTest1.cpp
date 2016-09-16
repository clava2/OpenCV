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
		cout << "�÷�����������ͼƬ��·����Ȼ����ϻ���ʣ��˳��򽫻Ὣ����ͼƬ���" << endl;
		return 1;
	}
	if (argc == 2)
	{
		cout << "�����ͼƬ·��̫�٣�" << endl;
		return 2;
	}
	if (argc == 3)
	{
		cout << "û���������ʣ�������Ȼ�ϣ�" << endl;
	}
	if (argc == 4)
	{
		BlendRate = atof(argv[3]);
	}

	Mat Input1 = imread(argv[1]);
	if (!Input1.data)
	{
		cout << "��ȡͼƬ1������ʱ����" << endl;
		return 3;
	}
	
	Mat Input2 = imread(argv[2]);
	if (!Input2.data)
	{
		cout << "��ȡͼƬ2������ʱ����" << endl;
		return 4;
	}

	addWeighted(Input1, BlendRate, Input2, 1 - BlendRate, 0.0, Input1);

	namedWindow("Blending");
	imshow("Blending", Input1);

	waitKey(0);
}