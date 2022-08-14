
#include "utils.hpp"

void computeBresenhamsLine(cv::Point p0, cv::Point p1, std::vector<cv::Point> &line_points){

    int x0 = p0.x;
    int x1 = p1.x;

    int y0 = p0.y;
    int y1 = p1.y;

    std::cout << "x0 " << x0 << " x1 " << x1 << " y0 " << y0 << " y1 " << y1 << std::endl;

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
}

void plotLineLow(cv::Point p0, cv::Point p1, std::vector<cv::Point> &line_points){
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    int yi = 1;
    if(dy<0){
        yi = -1;
        dy = -dy;
    }
    int D = 2*dy-dx;
    int y = p0.y;

    for(int x=p0.x; x<p1.x; x++){
        
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

void plotLineHigh(cv::Point p0, cv::Point p1,  std::vector<cv::Point> &line_points){
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    int xi = 1;
    if(dx<0){
        xi = -1;
        dx = -dy;
    }
    int D = 2*dx-dy;
    int x = p0.x;

    for(int y=p0.y; y<p1.y; y++){
        
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