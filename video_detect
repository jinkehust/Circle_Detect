#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  

using namespace cv;

void FindCircles(Mat srcImage)
{
	Mat midImage, dstImage;
	cvtColor(srcImage, midImage, CV_BGR2GRAY);//转化边缘检测后的图为灰度图  
	GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);
	vector<Vec3f> circles;
	HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1, midImage.rows / 200, 50, 80, 0, 0);
	//依次在图中绘制出圆  
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//绘制圆心  
		circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		//绘制圆轮廓  
		circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
	}

	imshow("【效果图】", srcImage);
	waitKey(10);
}

int main()
{
	VideoCapture capture(0);     //调用摄像头
	Mat frame;

	while (1)
	{
		capture >> frame;   //摄像头当前图片读给frame
		FindCircles(frame);
	}
	return 0;
}
