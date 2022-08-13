#include <iostream>

#include <Eigen/Dense>

#include "opencv2/opencv.hpp"

void plotLineLow(Eigen::Vector2i p0, Eigen::Vector2i p1, std::vector<cv::Point> &line_points){
    int dx = p1(0) - p0(0);
    int dy = p1(1) - p0(1);
    int yi = 1;
    if(dy<0){
        yi = -1;
        dy = -dy;
    }
    int D = 2*dy-dx;
    int y = p0(1);

    for(int x=p0(0); x<p1(0); x++){
        
        cv::Point pt(x,y);
        line_points.push_back(pt);
        if(D>0){
            y += yi;
            D += 2*(dy-dx);
        }
        else{
            D += 2*dy;
        }
    }
}

void plotLineHigh(Eigen::Vector2i p0,Eigen::Vector2i p1,  std::vector<cv::Point> &line_points){
    int dx = p1(0) - p0(0);
    int dy = p1(1) - p0(1);
    int xi = 1;
    if(dx<0){
        xi = -1;
        dx = -dy;
    }
    int D = 2*dx-dy;
    int x = p0(0);

    for(int y=p0(1); y<p1(1); y++){
        
        cv::Point pt(x,y);
        line_points.push_back(pt);
        if(D>0){
            x += xi;
            D += 2*(dx-dy);
        }
        else{
            D += 2*dx;
        }
    }
}


int main (){
    Eigen::MatrixXf og(100, 60);
    og.setOnes();
    og *= 0.5;

    std::vector<cv::Point> line_points;

    Eigen::Vector2i p0;
    Eigen::Vector2i p1;
    p0 << 55,-100;
    p1 << 10, -599;

    

    int x0 = p0(0);
    int x1 = p1(0);

    int y0 = p0(1);
    int y1 = p1(1);

    cv::Point p0_pt(x0,y0);
    cv::Point p1_pt(x1,y1);
    

    line_points.push_back(p0_pt);

    if(std::abs(y1-y0)<std::abs(x1-x0)){
        if(x0>x1){
            plotLineLow(p1, p0, line_points);
        }
        else{
            plotLineLow(p0, p1, line_points);
        }
    }
    else{
        if(y0>y1){
            plotLineHigh(p1, p0, line_points);
        }
        else{
            plotLineHigh(p0, p1, line_points);
        }
    }

    line_points.push_back(p1_pt);

    for(int i=0; i<line_points.size(); i++){
        
        cv::Vec3b &pixel_color = map.at<cv::Vec3b>(  -line_points[i].y, line_points[i].x);
        pixel_color[0] = 255;
        pixel_color[1] = 255;
        pixel_color[2] = 255;

    }


    cv::imshow("blank", map);
    cv::waitKey(0);
}