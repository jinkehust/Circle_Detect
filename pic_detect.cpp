#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  

using namespace cv;

void FindCircles(Mat srcImage)
{
	Mat midImage, dstImage;
	cvtColor(srcImage, midImage, CV_BGR2GRAY);//转化边缘检测后的图为灰度图  
	GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);
	vector<Vec3f> circles;
	HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1, midImage.rows / 20, 50, 100, 0, 0);
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
	waitKey(0);
}

int main(int argc, char** argv)
{

	Mat srcImage = imread("golf.jpg");
	imshow("【原始图】", srcImage);
	//调用函数
	FindCircles(srcImage);
	return 0;
}
