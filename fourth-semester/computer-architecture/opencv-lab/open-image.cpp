#include "opencv2/core.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

int main()
{
  cv::Mat img = cv::imread("image.jpg");
  cv::namedWindow("Window");
  cv::imshow("Window", img);
  cv::waitKey();
  img.release();
  cv::destroyWindow("Window");
  
  return 0;
}
