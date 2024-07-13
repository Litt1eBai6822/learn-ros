#include <opencv2/opencv.hpp>  
using namespace cv;  
  
int main()  
{  
    // 打开硬盘上的视频文件  
    VideoCapture cap("path_to_your_video_file.mp4"); // 替换为视频文件的实际路径  
    if (!cap.isOpened()) {  
        std::cout << "Error opening video file" << std::endl;  
        return -1;  
    }  
  
    namedWindow("读取视频帧", WINDOW_AUTOSIZE); // 创建窗口，并设置窗口大小可自动调节  
  
    while (true)  
    {  
        Mat frame;  
        cap >> frame;  
        if (frame.empty()) {  
            std::cout << "End of video file reached" << std::endl;  
            break;  
        }  
        imshow("读取视频帧", frame);  
  
        int key = waitKey(30); // 等待按键事件，同时显示当前帧  
        if (key == 27 || key == -1) { // 检查是否按下ESC键或窗口被关闭  
            break;  
        }  
    }  
  
    cap.release(); // 释放VideoCapture对象  
    destroyAllWindows(); // 销毁所有OpenCV创建的窗口  
  
    return 0;  
}