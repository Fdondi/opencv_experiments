#include "recognizer.h"

#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>

#include<iostream>

int main(int argc, char**argv) {
cv::Mat img = cv::imread(argv[1]);

Recognizer recognizer("./haarcascade_frontalface_default.xml");

recognizer.recognize_in(img);

cv::imshow("Face", img);

cv::waitKey(0);	
return 0;
}
