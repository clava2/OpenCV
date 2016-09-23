#include <opencv/highgui.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("����Ĳ�������������ȷ�ϣ�\n");
	}
	cvNamedWindow("Video", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(argv[1]);
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
		{
			break;
		}
		cvShowImage("Video", frame);
		char c = cvWaitKey(33);
		if (c == 27)
		{
			break;
		}
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Video");
}