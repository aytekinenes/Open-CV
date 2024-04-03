#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>



using namespace cv;
using namespace std;

void ShowImage(std::string path)
{
    cv::Mat img = cv::imread(path);
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void ShowVideo(std::string path)
{
    cout << "aaaa" << endl;
    cv::VideoCapture video;
    video.open(path);
    if (video.isOpened())
    {
        cout << "Video opened" << endl;
        cv::Mat frame;
        cv::namedWindow("Video windows");
        int fps = 23;
        int key = 0;

        while (video.read(frame))
        {
            // ASCII table
            //  ESC == 27
            //    + == 43
            //    - == 45
            cv::imshow("Second OpenCV Appliciation", frame);
            key == cv::waitKey(fps);
            if (key == 27)
            {
                cout << "Exit video" << endl;
                break;
            }
            
            else if (key == 43)
            {
                fps++;
                cout << "FPS = " << fps << endl;
            
            }
            else if (key == 45)
            {
                fps--;
                cout << "FPS = " << fps << endl;
            }
                
        }
        cv::destroyAllWindows();
    }
    else
    {
        cout << "video does't opened" << endl;
    }
    return;
}

void ShowWebcam(int ch)
{
    cv::VideoCapture video;
    if (video.open(ch))
    {
        cout << "Camera is open" << endl;
        cv::namedWindow("Webcam windows");
        cv::Mat frame;

        while (video.grab())
        {
            video.retrieve(frame);
            cv::imshow("Webcam windows", frame);
            if (cv::waitKey(23) == 27)
            {
                break;
            }
        }
        cv::destroyAllWindows();
    }
    else 
    {
        cout << "\nch : " << ch << " Cameras is not open..!" << endl;

    }

}

void ShowIPCam(std::string ip)
{
    cv::VideoCapture video;
    if (video.open(ip))
    {
        cout << "Camera is open" << endl;
        cv::namedWindow("Webcam windows");
        cv::Mat frame;

        while (video.grab())
        {
            video.retrieve(frame);
            cv::imshow("Webcam windows", frame);
            if (cv::waitKey(23) == 27)
            {
                break;
            }
        }
        cv::destroyAllWindows();
    }
    else
    {
        cout << "\nch : " << ip << " Cameras is not open..!" << endl;
    }
}

cv::Mat CreateBasicPhoto(int genislik, int yukseklik, int blue, int green, int red)
{
    cv::Mat photo(yukseklik, genislik, CV_8UC3, cv::Scalar(blue, green, red)); //cv_8uc5 = blue, green, red
   // photo = cv::Scalar(blue, green, red);
    cv::imshow("Windows", photo);
    cv::waitKey();
    return photo;
}


int main()
{
    std::string imgPath = "C:/Users/hp/Desktop/OpencvNS/image/sw.jpg";
    std::string videoPath = "C:/Users/hp/Desktop/OpencvNS/image/semihsayginer.mp4";
    std::string IPCamAddress = "192.168.1.22";




    // ShowImage(imgPath);
    // ShowVideo(videoPath);
    // ShowWebcam(0);
    // ShowIPCam(IPCamAddress);
    //CreateBasicPhoto(640, 480, 0,0,255);   // Red
    //CreateBasicPhoto(640, 480, 255, 0, 0); // Blue
    //CreateBasicPhoto(640, 480, 0, 255, 0); // Green


    /*
    cv::Mat createdPhoto = CreateBasicPhoto(640, 480, 128, 0, 128);
    cv::imshow("Windows", createdPhoto);
    */
    



    return 0;
}