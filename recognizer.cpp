#include "recognizer.h"

#include<opencv2/highgui.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/imgproc.hpp>

Recognizer::Recognizer(const std::string& model_path){
	classifier=std::make_unique<cv::CascadeClassifier>();
	classifier->load(model_path);
	assert(!classifier->empty());	
}

Recognizer::~Recognizer() = default;

void Recognizer::recognize_in(cv::Mat& img){
	std::vector<cv::Rect> faces;
	classifier->detectMultiScale(img, faces, 1.1, 10);

	for(cv::Rect rect: faces){
		cv::rectangle(img, rect, cv::Scalar(255, 255, 255), 3);
	}
}
