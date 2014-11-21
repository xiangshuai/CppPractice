#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;


int main()
{
    initModule_nonfree();//��ʼ��ģ�飬ʹ��SIFT��SURFʱ�õ�
    Ptr<FeatureDetector> detector = FeatureDetector::create( "SIFT" );//����SIFT���������
    Ptr<DescriptorExtractor> descriptor_extractor = DescriptorExtractor::create( "SIFT" );//������������������
    Ptr<DescriptorMatcher> descriptor_matcher = DescriptorMatcher::create( "BruteForce" );//��������ƥ����
    if( detector.empty() || descriptor_extractor.empty() )
        cout<<"fail to create detector!";

    //����ͼ��
    Mat img1 = imread("demo.jpg");
    Mat img2 = imread("src1.jpg");

    //��������
    double t = getTickCount();//��ǰ�δ���
    vector<KeyPoint> keypoints1,keypoints2;
    detector->detect( img1, keypoints1 );//���img1�е�SIFT�����㣬�洢��keypoints1��
    detector->detect( img2, keypoints2 );
    cout<<"ͼ��1���������:"<<keypoints1.size()<<endl;
    cout<<"ͼ��2���������:"<<keypoints2.size()<<endl;

    //����������������������Ӿ��󣬼�������������
    Mat descriptors1,descriptors2;
    descriptor_extractor->compute( img1, keypoints1, descriptors1 );
    descriptor_extractor->compute( img2, keypoints2, descriptors2 );
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout<<"SIFT�㷨��ʱ��"<<t<<"��"<<endl;


    cout<<"ͼ��1�������������С��"<<descriptors1.size()
        <<"����������������"<<descriptors1.rows<<"��ά����"<<descriptors1.cols<<endl;
    cout<<"ͼ��2�������������С��"<<descriptors2.size()
        <<"����������������"<<descriptors2.rows<<"��ά����"<<descriptors2.cols<<endl;

    //����������
    Mat img_keypoints1,img_keypoints2;
    drawKeypoints(img1,keypoints1,img_keypoints1,Scalar::all(-1),0);
    drawKeypoints(img2,keypoints2,img_keypoints2,Scalar::all(-1),0);
    //imshow("Src1",img_keypoints1);
    //imshow("Src2",img_keypoints2);

    //����ƥ��
    vector<DMatch> matches;//ƥ����
    descriptor_matcher->match( descriptors1, descriptors2, matches );//ƥ������ͼ�����������
    cout<<"Match������"<<matches.size()<<endl;

    //����ƥ�����о����������Сֵ
	//������ָ���������������ŷʽ���룬�������������Ĳ��죬ֵԽС��������������Խ�ӽ�
    double max_dist = 0;
    double min_dist = 100;
    for(int i=0; i<matches.size(); i++)
    {
        double dist = matches[i].distance;
        if(dist < min_dist) min_dist = dist;
        if(dist > max_dist) max_dist = dist;
    }
    cout<<"�����룺"<<max_dist<<endl;
    cout<<"��С���룺"<<min_dist<<endl;

    //ɸѡ���Ϻõ�ƥ���
    vector<DMatch> goodMatches;
    for(int i=0; i<matches.size(); i++)
    {
        if(matches[i].distance < 0.31 * max_dist)
        {
            goodMatches.push_back(matches[i]);
        }
    }
    cout<<"goodMatch������"<<goodMatches.size()<<endl;

    //����ƥ����
    Mat img_matches;
    //��ɫ���ӵ���ƥ���������ԣ���ɫ��δƥ���������
    drawMatches(img1,keypoints1,img2,keypoints2,goodMatches,img_matches,
                Scalar::all(-1)/*CV_RGB(255,0,0)*/,CV_RGB(0,255,0),Mat(),2);

    imshow("MatchSIFT",img_matches);
    waitKey(0);
    return 0;
}
