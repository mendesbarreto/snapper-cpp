#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

int main() {
  std::cout << "Let's Start Snapper Example" << std::endl;
  std::cout << "Loading example" << std::endl;
  cv::Mat image = cv::imread("../assets/rick.jpg", cv::IMREAD_COLOR);

  if (image.empty()) {
    std::cerr << "The Rick image failed to load" << std::endl;
    return 1;
  }

  cv::Point text_position(80, 80);
  int font_size = 1;
  cv::Scalar font_Color(0, 0, 0);

  int font_weight = 2;
  putText(image, "This is RICK!", text_position, cv::FONT_HERSHEY_COMPLEX,
          font_size, font_Color,
          font_weight); // Putting the text in the matrix//

  // Show our image
  cv::imshow("Rick", image);
  cv::waitKey(0);

  return 0;
}
