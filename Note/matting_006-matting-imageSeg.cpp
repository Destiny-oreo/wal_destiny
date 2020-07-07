#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat watershedCluster(Mat &image, int &numSegments);
void createDisplaySegments(Mat &segments, int numSegments, Mat &image);
int main(int argc, char** argv) {
	Mat src = imread("D:/vcprojects/images/cvtest.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	int numSegments;
	Mat markers = watershedCluster(src, numSegments);
	createDisplaySegments(markers, numSegments, src);
	waitKey(0);
	return 0;
}

Mat watershedCluster(Mat &image, int &numComp) {
	// 二值化
	Mat gray, binary;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
	// 形态学与距离变换
	Mat k = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	morphologyEx(binary, binary, MORPH_OPEN, k, Point(-1, -1));
	Mat dist;
	distanceTransform(binary, dist, DistanceTypes::DIST_L2, 3, CV_32F);
	normalize(dist, dist, 0.0, 1.0, NORM_MINMAX);

	// 开始生成标记
	threshold(dist, dist, 0.1, 1.0, THRESH_BINARY);
	normalize(dist, dist, 0, 255, NORM_MINMAX);
	dist.convertTo(dist, CV_8UC1);

	// 标记开始
	vector<vector<Point>> contours;
	vector<Vec4i> hireachy;
	findContours(dist, contours, hireachy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
	if (contours.empty()) {
		return Mat();
	}

	Mat markers(dist.size(), CV_32S);
	markers = Scalar::all(0);
	for (int i = 0; i < contours.size(); i++) {
		drawContours(markers, contours, i, Scalar(i + 1), -1, 8, hireachy, INT_MAX);
	}
	circle(markers, Point(5, 5), 3, Scalar(255), -1);

	// 分水岭变换
	watershed(image, markers);
	numComp = contours.size();
	return markers;
}

void createDisplaySegments(Mat &markers, int numSegments, Mat &image) {
	// generate random color
	vector<Vec3b> colors;
	for (size_t i = 0; i < numSegments; i++) {
		int r = theRNG().uniform(0, 255);
		int g = theRNG().uniform(0, 255);
		int b = theRNG().uniform(0, 255);
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}

	// 颜色填充与最终显示
	Mat dst = Mat::zeros(markers.size(), CV_8UC3);
	int index = 0;
	for (int row = 0; row < markers.rows; row++) {
		for (int col = 0; col < markers.cols; col++) {
			index = markers.at<int>(row, col);
			if (index > 0 && index <= numSegments) {
				dst.at<Vec3b>(row, col) = colors[index - 1];
			}
			else {
				dst.at<Vec3b>(row, col) = Vec3b(255, 255, 255);
			}
		}
	}
	imshow("分水岭图像分割-演示",dst);
	return;
} 