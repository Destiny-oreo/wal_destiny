#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img(500, 500, CV_8UC3);
	RNG rng(12345);	//��ʼ����

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
	Mat points(sampleCount, 1, CV_32FC2);	//����һ�е�����-��
	Mat labels;	//k-means���
	Mat centers;	//k-means���

	// ���������
	for (int k = 0; k < numCluster; k++) {
		Point center;
		center.x = rng.uniform(0, img.cols);
		center.y = rng.uniform(0, img.rows);
		Mat pointChunk = points.rowRange(k*sampleCount / numCluster, 
			k == numCluster - 1 ? sampleCount : (k + 1)*sampleCount / numCluster);

		rng.fill(pointChunk, RNG::NORMAL, Scalar(center.x, center.y), Scalar(img.cols*0.05, img.rows*0.05));
	}//����ÿ�����ĵ㣬���ƺ÷�Χ��Ȼ��ʹ��rowRange��ǳ�������Ը�˹����������ĵ㸽����Ӧ�����ľ��������
	randShuffle(points, 1, &rng);//ѭ���Ժ�����ȫ���ĵ����꣬Ȼ����ң�����ȥǰ1/4�ǵ�һ�����ĵ㸽��֮��ķֲ�

	// ʹ��KMeans
	kmeans(points, numCluster, labels, TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1), 3, KMEANS_PP_CENTERS, centers);//�õ�labels��centers

	// �ò�ͬ��ɫ��ʾ����
	img = Scalar::all(255);//��ʼ��Ϊ��ɫ����
	for (int i = 0; i < sampleCount; i++) {
		int index = labels.at<int>(i);//�����ȡÿ����ķ�����
		Point p = points.at<Point2f>(i);//ȡ���������
		circle(img, p, 2, colorTab[index], -1, 8);//�������껭��Ŷ�Ӧ����ɫԲȦ
	}

	// ÿ�����������������Բ
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