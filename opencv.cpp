#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

class Recognizer{
cv::CascadeClassifier classifier;

public:
Recognizer(const std::string& model_path){
	classifier.load(model_path);
	if (classifier.empty()) { std::cout << "no model found in path: " << model_path << std::endl; }
}

void recognize_in(cv::Mat& img){
std::vector<cv::Rect> faces;
classifier.detectMultiScale(img, faces, 1.1, 10);

for(cv::Rect rect: faces){
	cv::rectangle(img, rect, cv::Scalar(255, 255, 255), 3);
}
}
};

int main(int argc, char**argv) {
cv::Mat img = cv::imread(argv[1]);

Recognizer recognizer("./haarcascade_frontalface_default.xml");

recognizer.recognize_in(img);

cv::imshow("Face", img);

cv::waitKey(0);	
return 0;
}
