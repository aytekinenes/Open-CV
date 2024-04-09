#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>



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



//resim k�rpma
cv::Mat RectPhoto(string Path, int x, int y, int genislik, int yukseklik)
{
    cv::namedWindow("Image in the folder");
    cv::Mat photo = cv::imread(Path);
    cv::imshow("image in the folder", photo);
    cv::waitKey();

    cv::Mat rected_Photo;
    photo.copyTo(rected_Photo);
    rected_Photo = cv::Mat(rected_Photo, cv::Rect(x, y, genislik, yukseklik));
    return rected_Photo;
}


// Resimde �izgi ciz
cv::Mat DrawLineInPicture(string Path, int x1, int y1, int x2, int y2, int Blue, int Green, int Red, int Thicness)
{
    // 
    cv::Mat RealPhoto = cv::imread(Path);
    cv::Mat FakePhoto;
    // !!!! photo max x value = cols, photo min y value = rows
    RealPhoto.copyTo(FakePhoto);
    cv::line(FakePhoto, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(Blue, Green, Red, Thicness));
     
   // cv::line(FakePhoto, cv::Point(x1, y1), 
   //      cv::Point(FakePhoto.cols, FakePhoto.rows), cv::Scalar(Blue, Green, Red, Thicness));
    
    return FakePhoto;
    

}

// Resimde dortgen ciz
cv::Mat DrawRectangle(string Path, int x1, int y1, int x2, int y2, int thickness)
{
    cv::Mat photo = cv::imread(Path);
    cv::Point start(x1, y1);
    cv::Point end(x2, y2);
    cv::rectangle(photo, start, end, cv::Scalar(0, 0, 255), 5);
    return photo;
}


 // Resimde dortgen ciz 2 
cv::Mat DrawRectangle2(string Path, int x, int y, int width, int heigth, int thickness)
{
    cv::Mat photo = cv::imread(Path);
    cv::rectangle(photo, Rect(x, y, width, heigth), cv::Scalar(0, 0, 255), thickness);

    return photo;

}

// Resim uzerinde text yaz
cv::Mat WriteTextOnPhoto(string Path, string Text, int x, int y, int Blue, int Green, int Red, 
    double fontSize, int thickness, bool mirror = false)
{
    cv::Mat photo = cv::imread(Path);
    cv::Mat FakePhoto;
    cv::Point p(x, y);
    cv::Point pmirror(x, y + 50);
    cv::Scalar c(Blue, Green, Red);
    photo.copyTo(FakePhoto);
    
    cv::putText(FakePhoto, Text, p, FONT_ITALIC, fontSize, c, thickness, 8, false);
    cv::putText(FakePhoto, Text, p, FONT_ITALIC, fontSize, c, thickness, 8, true);
    return FakePhoto;

}

// Resim uzerinde daire ciz
cv::Mat DrawCircle(string Path, int x, int y, int radius = 50, 
    int Blue = 128, int Green = 0, int Red = 128, int thickness= 2)
{
    cv::Mat photo = cv::imread(Path);
    cv::Point center(x, y);
    cv::Scalar color(Blue, Green, Red);
    cv::circle(photo,center,  radius, color, thickness);
    return photo;
}

// default bgr = 0 Blue, 1 Green, 2 Red             VEC3D(return unsigned char)



//  RGB VEC3B
void ReadValueofPhoto(string Path)
{
    cv::Mat photo = cv::imread(Path);
    cv::imshow("Photo", photo);
    cv::Mat fakePhoto;
    photo.copyTo(fakePhoto);
    cv::waitKey();
    uchar blue, green, red;

    for (int x = 0; x < photo.cols; x++)
    {
        for (int y = 0; y < photo.rows; y++)
        {
            blue = fakePhoto.at<Vec3b>(cv::Point(x, y))[0];

            if (blue >100 && blue == 255)
            {
                blue = 0;
                fakePhoto.at<cv::Vec3b>(cv::Point(x, y))[0] = blue;
            }

        }
    }
    cv::imshow("Blue=0", fakePhoto);
    cv::waitKey();

    return;
}

void CopyPhoto(cv::Mat photo, cv::Mat &copyPhoto)
{
    copyPhoto =  cv::Mat(cv::Size(photo.cols, photo.rows), CV_8UC3);
    char b, g, r;
    cv::namedWindow("Copy Period", 1);

    for (int x = 0; x < copyPhoto.cols; x++)
    {
        for (int y = 0; y < copyPhoto.rows; y++)
        {
            b = photo.at<cv::Vec3b>(cv::Point(x, y))[0]; // blue
            g = photo.at<cv::Vec3b>(cv::Point(x, y))[1]; // green
            r = photo.at<cv::Vec3b>(cv::Point(x, y))[2]; // red

            copyPhoto.at<cv::Vec3b>(cv::Point(x, y))[0] = b;
        //    copyPhoto.at<cv::Vec3b>(cv::Point(x, y))[1] = g;
            copyPhoto.at<cv::Vec3b>(cv::Point(x, y))[2] = r;


            cv::imshow("Copy Period", copyPhoto);
            cv::waitKey();

        }
    }
    cout << "Operating completed" << endl;  
}


// Resmi boyutland�rarak b�y�tmek
cv::Mat BiggerPhoto(cv::Mat photo, int coefficient =2)
{
    int newPhotoW  = photo.cols * coefficient;
    int newPhotoH = photo.rows * coefficient;
    cv::Mat newPhoto(cv::Size(newPhotoW, newPhotoH), CV_8UC3);

    cv::Vec3b bgr;
    cout << "Operating Started" << endl;
    for (int i = 0; i < photo.cols; i++)
    {
        for (int j = 0; j < photo.rows; j++)
        {
            bgr = photo.at<cv::Vec3b>(cv::Point(i, j));
            int startX = i * coefficient;
            int startY = j * coefficient;
            int endX = startX + coefficient;
            int endY = startY + coefficient;

            for (int x = startX; x < endX; x++)
            {
                for (int y = startY; y < endY; y++)
                {
                    newPhoto.at<cv::Vec3b>(cv::Point(x, y)) = bgr;
                }
            }

        }
    }
    cout << "Operating Completed..." << endl;
    return newPhoto;
}


cv::Mat SmallerPhoto(cv::Mat photo, int coefficient =2)
{
    if (!photo.data && !photo.empty())
    {
        cout << "Error ";
        return cv::Mat::zeros(cv::Size(1, 1), CV_8UC3);
    }
    int width = photo.cols / coefficient;
    int height = photo.rows / coefficient;

    cv::Mat smallPhoto(cv::Size(width, height), CV_8UC3);
    cv::Vec3b bgrVec;

    cout << "Operating Started" << endl;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            bgrVec = photo.at<cv::Vec3b>(cv::Point(x * coefficient, y * coefficient));
            smallPhoto.at<cv::Vec3b>(cv::Point(x, y)) = bgrVec;

        }
    }
    cout << "Operating Completed" << endl;
    return smallPhoto;
}





int main()
{
    std::string imgPath = "C:/Users/hp/Desktop/OpencvNS/image/sw.jpg";
    std::string rgbImagePath = "C:/Users/hp/Desktop/OpencvNS/image/rgb.png";
    std::string eImagePath = "C:/Users/hp/Desktop/OpencvNS/image/Eee.png";
    std::string videoPath = "C:/Users/hp/Desktop/OpencvNS/image/semihsayginer.mp4";
    std::string IPCamAddress = "192.168.1.22";
    cv::String impPath = "C:/Users/hp/Desktop/OpencvNS/image/sw.jpg";
    


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
    

    /*
    // Rect Photo - Resim k�rp
    cv::imshow("Window1", RectPhoto(imgPath, 0, 0, 400, 200));
    cv::waitKey();
    */



    /*
    // Draw line - Resimde �izgi �iz
    cv::imshow("Drawn Photo", DrawLineInPicture(imgPath, 0, 0,500,200, 255, 0, 0, 10));
    cv::waitKey();
    */




    /*
    // Draw Rectangle - Resimde kare ciz 
    cv::imshow("Draw Rectangle", DrawRectangle(imgPath,50,50,150,150,50));
    cv::waitKey();
    */


    /*
    // Draw Rectangle - Resimde kare ciz 2
    cv::imshow("Draw Rectangle", DrawRectangle2(imgPath, 50, 100, 200, 200, 10));
    cv::waitKey();
    */



    /*
    // Write text on Photo - Resim uzerine yazi yaz
    cv::imshow("WriteTextOnPhoto", WriteTextOnPhoto(imgPath, "Open cv C++",200,200,128,0,128, 3, 2,true));
    cv::waitKey();
    */



    /*
    // Draw circle on Photo - Resim uzerinde daire ciz
    cv::imshow("Draw Circle", DrawCircle(imgPath,100,100));
    cv::waitKey();
    */


    /*
    // Foto uzerinde RGB renklerin de�i�tirilmesi
    ReadValueofPhoto(rgbImagePath);
    */




    /*
    // copy Photo - Resim kopyalama
    cv::Mat photo = cv::imread(eImagePath);
    cv::Mat copyPhoto;

    CopyPhoto(photo, copyPhoto);
    cv::imshow("CopyPhoto", copyPhoto);
    cv::waitKey();
    */





    /*
    // Resim boyutland�rma - Enlarge photo
    cv::Mat OriginalPhoto = imread(imgPath);
    cv::Mat newPhoto = BiggerPhoto(OriginalPhoto);

    cv::imshow("Original Photo", OriginalPhoto);
    cv::imshow("Enlarge Photo", newPhoto);
    cv::waitKey();
    */


    


/*
    // Resmi Kucultmek // smaller Photo

    string window1 = "Original Photo";
    string window2 = "Smaller Photo";

    cv::namedWindow(window1);
    cv::namedWindow(window2);


    cv::Mat OriginalPhoto = cv::imread(imgPath);
    cv::imshow(window1, OriginalPhoto);

    cv::Mat smallPhoto = SmallerPhoto(OriginalPhoto);
    cv::imshow(window2, smallPhoto);
    cv::waitKey();
*/







    return 0;
}