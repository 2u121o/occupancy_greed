#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include "opencv2/opencv.hpp"

void computeBresenhamsLine(cv::Point p0, cv::Point p1, std::vector<cv::Point> &line_points);
void plotLineLow(cv::Point p0, cv::Point p1, std::vector<cv::Point> &line_points);
void plotLineHigh(cv::Point p0, cv::Point p1,  std::vector<cv::Point> &line_points);

#endif
