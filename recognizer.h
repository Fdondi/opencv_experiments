#include<memory>

namespace cv{
class Mat;
class CascadeClassifier;
}

class Recognizer{
std::unique_ptr<cv::CascadeClassifier> classifier;

public:
Recognizer(const std::string& model_path);
~Recognizer();

void recognize_in(cv::Mat& img);
};

