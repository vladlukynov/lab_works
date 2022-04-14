#include <Windows.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

int blurValue = 1;
double alpha = 1.0;
int beta = 0;

void updateBlurValue(int value, void*);
void updateAlpha(int value, void*);
void updateBeta(int value, void*);

int main()
{
  cv::VideoCapture videoCapture(0, cv::CAP_DSHOW);

  cv::Mat frame;
  cv::namedWindow("Camera");
  cv::createTrackbar("Blur", "Camera", NULL, 100, updateBlurValue);
  cv::createTrackbar("Brightness", "Camera", NULL, 200, updateAlpha);
  cv::createTrackbar("Contrast", "Camera", NULL, 100, updateBeta);

  while (true)
  {
    videoCapture.read(frame);

    cv::Size size(blurValue, blurValue);
    cv::GaussianBlur(frame, frame, size, 0, 0);

    for (int y = 0; y < frame.rows; y++) {
      for (int x = 0; x < frame.cols; x++) {
        for (int c = 0; c < frame.channels(); c++) {
          frame.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(alpha * frame.at<cv::Vec3b>(y, x)[c] + beta);
        }
      }
    }

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

void updateBlurValue(int value, void*)
{
  if (value % 2 != 0) {
    blurValue = value;
  }
}

void updateAlpha(int value, void*)
{
  double temp = value;
  alpha = temp / 100;
}

void updateBeta(int value, void*)
{
  beta = value;
}