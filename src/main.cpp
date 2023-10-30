#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <ostream>

cv::Mat crop(cv::Mat sourceImage, double offsetWidth, double offsetHeight,
             int width, int height) {

  /* std::cout << "Starting Crop Image"; */
  cv::Mat inputImage = sourceImage.clone();

  if (offsetWidth < 0) {
    offsetWidth = sourceImage.cols / 2.0;
  }

  if (offsetHeight < 0) {
    offsetHeight = sourceImage.rows / 2.0;
  }

  int x = offsetWidth;
  int y = offsetHeight;

  /* std::cout << "Cropping image x: " << x << " y: " << y << " w: " << width */
  /*           << " h: " << height << std::endl; */
  /* std::cout << "Image w: " << sourceImage.cols / 2.0 << std::endl; */

  cv::Mat outputImage = inputImage(cv::Rect(x, y, width, height));

  return outputImage;
}

int main() {
  cv::Mat frame = cv::imread("../assets/tray_portrait.jpg");
  cv::Mat outputFrame;
  int64 start = cv::getTickCount();

  int imagesToCrop = 100000;

  for (int i = 0; i < imagesToCrop; i++) {
    outputFrame = crop(frame, 300, 300, 2420, 3650);
  }

  int64 delta = cv::getTickCount() - start;
  double freq = cv::getTickFrequency();
  double elapsed = delta / freq;
  std::cout << "Took " << elapsed << " seconds."
            << "to crop " << imagesToCrop << " images" << std::endl;

  cv::imshow("Crop", outputFrame);
  cv::waitKey(0);

  return 0;
}
