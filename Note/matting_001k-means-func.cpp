#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img(500, 500, CV_8UC3);
	RNG rng(12345);	//初始种子

	Scalar colorTab[] = {
		Scalar(0, 0, 255),
		Scalar(0, 255, 0),
		Scalar(255, 0, 0),
		Scalar(0, 255, 255),
		Scalar(255, 0, 255)
	};

	int numCluster = rng.uniform(2, 5);
	printf("number of clusters : %d\n", numCluster);

	int sampleCount = rng.uniform(5, 1000);
	Mat points(sampleCount, 1, CV_32FC2);	//生成一列点坐标-空
	Mat labels;	//k-means输出
	Mat centers;	//k-means输出

	// 生成随机数
	for (int k = 0; k < numCluster; k++) {
		Point center;
		center.x = rng.uniform(0, img.cols);
		center.y = rng.uniform(0, img.rows);
		Mat pointChunk = points.rowRange(k*sampleCount / numCluster, 
			k == numCluster - 1 ? sampleCount : (k + 1)*sampleCount / numCluster);

		rng.fill(pointChunk, RNG::NORMAL, Scalar(center.x, center.y), Scalar(img.cols*0.05, img.rows*0.05));
	}//生成每个中心点，限制好范围，然后使用rowRange来浅拷贝，以高斯随机生成中心点附近相应数量的具体点坐标
	randShuffle(points, 1, &rng);//循环以后生成全部的点坐标，然后打乱，不再去前1/4是第一个中心点附近之类的分布

	// 使用KMeans
	kmeans(points, numCluster, labels, TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1), 3, KMEANS_PP_CENTERS, centers);//得到labels和centers

	// 用不同颜色显示分类
	img = Scalar::all(255);//初始化为白色背景
	for (int i = 0; i < sampleCount; i++) {
		int index = labels.at<int>(i);//按序号取每个点的分类编号
		Point p = points.at<Point2f>(i);//取具体点坐标
		circle(img, p, 2, colorTab[index], -1, 8);//根据坐标画编号对应的颜色圆圈
	}

	// 每个聚类的中心来绘制圆
	for (int i = 0; i < centers.rows;  i++) {
		int x = centers.at<float>(i, 0);
		int y = centers.at<float>(i, 1);
		printf("c.x= %d, c.y=%d", x, y);
		circle(img, Point(x, y), 40, colorTab[i], 1, LINE_AA);
	}

	imshow("KMeans-Data-Demo", img);
	waitKey(0);
	return 0;
}