#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat rotate(Mat source, double angle) {
    Mat destination;
    Point2f pt(source.cols/2., source.rows/2.); // It Points to the Center of the Image
    Mat r = getRotationMatrix2D(pt, angle, 1.0); // 1 denotes original size
    warpAffine(source, destination, r, Size(source.cols, source.rows));
    return destination;
}
int main() {
    string imgname;
    double ang;
    Mat source, destination;

    cout << "Enter the Path of the Image followed by Extension : ";
    cin >> imgname;
    src = imread(imgname, CV_LOAD_IMAGE_UNCHANGED); // Reading the Image
    cout << "Enter the angle of Rotation : ";
    cin >> ang;
    
    destination = rotate(source, ang);

    // Show the Original Image
    const char* pzOriginalImage = "Original Image";
    namedWindow(pzOriginalImage, CV_WINDOW_AUTOSIZE);
    imshow(pzOriginalImage, src);
    
    // Show the Rotated Image
    const char* pzRotatedImage = "Rotated Image";
    namedWindow(pzRotatedImage, CV_WINDOW_AUTOSIZE);
    imshow(pzRotatedImage, dst);

    waitKey(0);
    return 0;
}
