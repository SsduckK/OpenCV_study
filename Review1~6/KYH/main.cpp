#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main()
{
    char TerminateKey;
    string ImageName;
    cout << "원하는 이미지의 이름과 확장자명을 입력해주세요 : ";
    cin >> ImageName;
    Mat BasicImage = imread("./" + ImageName, IMREAD_GRAYSCALE);
    Mat ResultImage;
    int brightness;
    int EditType;
    cout << "편집하고 싶은 방식을 선택하세요.(1. 밝기 올리기 2. 밝기 내리기 3. 명암비 조절하기 4. 이미지 합치기 0. 초기화) : ";
    cin >> EditType;
    switch(EditType)
    {
        case 0:
            break;

        case 1:
            cout << "밝기 올리기를 선택하셨습니다. 올리고 싶은 밝기의 수치를 입력해주세요 : " << endl;
            cin >> brightness;
            ResultImage = BasicImage + brightness;
            break;

        case 2:
            cout << "밝기 내리기를 선택하셨습니다. 내리고 싶은 밝기의 수치를 입력해주세요 : " << endl;
            cin >> brightness;
            ResultImage = BasicImage - brightness;
            break;

        case 3:
            cout << "명암비 조절을 선택하셨습니다. 조절하고 싶은 비율을 입력해주세요 : " << endl;
            int contrast;
            cin >> contrast;
            ResultImage = BasicImage + (BasicImage - 128) * contrast;
            break;

        case 4:
            cout << "이미지 합성하기를 선택하셨습니다. 합성하고 싶은 방식을 입력해주세요(1. 마스킹 2. 합성) : " << endl;
            int MaskOrNot;
            cin >> MaskOrNot;

            if(MaskOrNot == 1)
            {
                cout << "마스킹을 선택하셨습니다. 마스킹하고 싶은 이미지의 이름과 확장자를 입력해주세요. : " << endl;
                string MaskingImage;
                cin >> MaskingImage;
                Mat MaskImage = imread("./" + MaskingImage, IMREAD_GRAYSCALE);
                BasicImage.copyTo(ResultImage, MaskImage);
            }
          
            else
            {
                cout << "합성을 선택하셨습니다. 합성하고 싶은 이미지의 이름과 확장자를 입력해주세요. : " << endl;
                string AddingImage;
                cin >> AddingImage;                
                Mat AddImage = imread("./" + AddingImage, IMREAD_GRAYSCALE);
                addWeighted(BasicImage, 0.5, AddImage, 0.5, 0, ResultImage);
            }
    }

    imshow("BasicImage", BasicImage);
    imshow("ResultImage", ResultImage);
    waitKey();
    destroyAllWindows();
}