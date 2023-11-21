#include "recognizer.h"

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>

#include<iostream>

int main() {

cv::Mat img;
cv::VideoCapture cap(0);

Recognizer recognizer("./haarcascade_frontalface_default.xml");

while(true){

	cap.read(img);

	recognizer.recognize_in(img);

	cv::imshow("Face", img);
	cv::waitKey(1);
}

return 0;
}
