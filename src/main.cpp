#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

int main_old() {
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

int main() {
  cv::VideoCapture cap(0);

  cv::Mat frame = cv::imread("../assets/tray_portrait.jpg");
  cv::Mat output_frame = frame.clone();

  cv::namedWindow("snapper-trackbar");
  int l_h = 155, l_s = 99, l_v = 0;
  int u_h = 179, u_s = 255, u_v = 255;

  while (true) {
    cv::Mat frame_bgr, frame_hsv;
    cv::cvtColor(frame, frame_bgr, cv::COLOR_BGR2GRAY);
    cv::cvtColor(frame, frame_hsv, cv::COLOR_BGR2HSV);

    cv::medianBlur(frame_hsv, frame_hsv, 3);

    cv::Scalar lower_red(l_h, l_s, l_v);
    cv::Scalar upper_red(u_h, u_s, u_v);

    cv::Mat mask0;
    cv::inRange(frame_hsv, lower_red, upper_red, mask0);

    cv::Mat result;
    cv::bitwise_and(output_frame, output_frame, result, mask0);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(mask0, contours, hierarchy, cv::RETR_TREE,
                     cv::CHAIN_APPROX_SIMPLE);

    for (size_t i = 1; i < contours.size(); ++i) {
      std::vector<cv::Point> approx;
      cv::approxPolyDP(contours[i], approx,
                       0.01 * cv::arcLength(contours[i], true), true);
      cv::drawContours(output_frame, contours, static_cast<int>(i),
                       cv::Scalar(0, 0, 255), 5);
    }

    cv::imshow("output", output_frame);
    cv::imshow("frame", result);

    if (cv::waitKey(1) == 'q') {
      break;
    }
  }

  return 0;
}
