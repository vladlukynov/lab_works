#include <Windows.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

int main()
{
  cv::VideoCapture videoCapture(0, cv::CAP_DSHOW);

  cv::Mat frame;
  cv::namedWindow("Camera");

  while (true)
  {
    videoCapture.read(frame);
    cv::imshow("Camera", frame);
    char c = cv::waitKey(33);
    if (c == 27)
    {
      break;
    }
  }
  videoCapture.release();

  return 0;
}
