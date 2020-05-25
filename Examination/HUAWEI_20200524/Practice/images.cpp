/******************************************************************************
1.已知：一幅灰度图image，宽和高分别为const int kWidth = 200, const int kHeight = 120,
每个像素灰度值为[0,255]
要求：选定任意一个像素(x,y)，通过算法找到所有与其联通且灰度值相同的像素，并将所有找到的元素灰度
值置位给定的值ｖ。
*******************************************************************************/

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

// void fillRunVectors(const Mat& bwImage, int& NumberOfRuns, vector<int>& stRun, vector<int>& enRun, vector<int>& rowRun)
// {
//     for (int i = 0; i < bwImage.rows; i++)
//     {
//         const uchar* rowData = bwImage.ptr<uchar>(i);

//         if (rowData[0] == 255)
//         {
//             NumberOfRuns++;
//             stRun.push_back(0);
//             rowRun.push_back(i);
//         }
//         for (int j = 1; j < bwImage.cols; j++)
//         {
//             if (rowData[j - 1] == 0 && rowData[j] == 255)
//             {
//                 NumberOfRuns++;
//                 stRun.push_back(j);
//                 rowRun.push_back(i);
//             }
//             else if (rowData[j - 1] == 255 && rowData[j] == 0)
//             {
//                 enRun.push_back(j - 1);
//             }
//         }
//         if (rowData[bwImage.cols - 1])
//         {
//             enRun.push_back(bwImage.cols - 1);
//         }
//     }
// }

// //fillRunVectors

// void firstPass(vector<int>& stRun, vector<int>& enRun, vector<int>& rowRun, int NumberOfRuns,
//     vector<int>& runLabels, vector<pair<int, int>>& equivalences, int offset)
// {
//     runLabels.assign(NumberOfRuns, 0);
//     int idxLabel = 1;
//     int curRowIdx = 0;
//     int firstRunOnCur = 0;
//     int firstRunOnPre = 0;
//     int lastRunOnPre = -1;
//     for (int i = 0; i < NumberOfRuns; i++)
//     {
//         if (rowRun[i] != curRowIdx)
//         {
//             curRowIdx = rowRun[i];
//             firstRunOnPre = firstRunOnCur;
//             lastRunOnPre = i - 1;
//             firstRunOnCur = i;

//         }
//         for (int j = firstRunOnPre; j <= lastRunOnPre; j++)
//         {
//             if (stRun[i] <= enRun[j] + offset && enRun[i] >= stRun[j] - offset)
//             {
//                 if (runLabels[i] == 0) // 没有被标号过
//                     runLabels[i] = runLabels[j];
//                 else if (runLabels[i] != runLabels[j])// 已经被标号            
//                     equivalences.push_back(make_pair(runLabels[i], runLabels[j])); // 保存等价对
//             }
//         }
//         if (runLabels[i] == 0) // 没有与前一列的任何run重合
//         {
//             runLabels[i] = idxLabel++;
//         }

//     }
// }

// //firstPass

// void replaceSameLabel(vector<int>& runLabels, vector<pair<int, int>>&
//     equivalence)
// {
//     int maxLabel = *max_element(runLabels.begin(), runLabels.end());
//     vector<vector<bool>> eqTab(maxLabel, vector<bool>(maxLabel, false));
//     vector<pair<int, int>>::iterator vecPairIt = equivalence.begin();
//     while (vecPairIt != equivalence.end())
//     {
//         eqTab[vecPairIt->first - 1][vecPairIt->second - 1] = true;
//         eqTab[vecPairIt->second - 1][vecPairIt->first - 1] = true;
//         vecPairIt++;
//     }
//     vector<int> labelFlag(maxLabel, 0);
//     vector<vector<int>> equaList;
//     vector<int> tempList;
//     cout << maxLabel << endl;
//     for (int i = 1; i <= maxLabel; i++)
//     {
//         if (labelFlag[i - 1])
//         {
//             continue;
//         }
//         labelFlag[i - 1] = equaList.size() + 1;
//         tempList.push_back(i);
//         for (vector<int>::size_type j = 0; j < tempList.size(); j++)
//         {
//             for (vector<bool>::size_type k = 0; k != eqTab[tempList                [j] - 1].size(); k++)
//             {
//                 if (eqTab[tempList[j] - 1][k] && !labelFlag[k])
//                 {
//                     tempList.push_back(k + 1);
//                     labelFlag[k] = equaList.size() + 1;
//                 }
//             }
//         }
//         equaList.push_back(tempList);
//         tempList.clear();
//     }
//     cout << equaList.size() << endl;
//     for (vector<int>::size_type i = 0; i != runLabels.size(); i++)
//     {
//         runLabels[i] = labelFlag[runLabels[i]-1];
//     }
// }

// //replaceSameLabel



#define kHeight 200
#define kWidth 200

class Connection
{
private:
    char image[kHeight][kWidth] = {0};
    vector< pair<const int, const int> > ConPos;
    char val = 0;


public:
    
    Connection();
    ~Connection();

    int findConnectionPixel(const int h, const int w);
    int changeConnectionPixel();
};

Connection::Connection()
{
    srand((char)time(NULL));
    // srand((char)time(0));
    for (int i=0; i<kHeight; i++)
    {
        for (int j=0; j<kWidth; j++)
        {
            // image[i][j] = rand()%256;
            if(i%2==0)
                image[i][j] = 0;
            else
                image[i][j] = 1;
        }
    }
}

Connection::~Connection()
{
    ;
}

int Connection::findConnectionPixel(const int y, const int x)
{
    const int lpos = x-1;
    const int rpos = x+1;
    const int upos = y-1;
    const int dpos = y+1;

    const char center = image[y][x];
    const char left = image[y][lpos];
    const char right = image[y][rpos];
    const char up = image[upos][x];
    const char down = image[dpos][x];
    val = center;

    if(lpos > 0 && left==center)
    {
        pair<const int, const int> lpixel(y, lpos);
        ConPos.push_back(lpixel);
        findConnectionPixel(y, lpos);
    }
    if(rpos < kWidth && right==center)
    {
        pair<const int, const int> rpixel(y, rpos);
        ConPos.push_back(rpixel);
        findConnectionPixel(y, rpos);
    }
    if(upos > 0 && up==center)
    {
        pair<const int, const int> upixel(upos, x);
        ConPos.push_back(upixel);
        findConnectionPixel(upos, x); 
    }
    if(dpos < kHeight && down==center)
    {
        pair<const int, const int> dpixel(dpos, x);
        ConPos.push_back(dpixel);
        findConnectionPixel(dpos, x);
    }

    return 0;

}

int Connection::changeConnectionPixel()
{
    for (int i=0; i<ConPos.size(); i++)
    {
        pair<const int, const int> pixel = ConPos[i];
        int y_ = pixel.first;
        int x_ = pixel.second;
        image[y_][x_] = val;
        cout << "(" << x_ << ", " << y_  << ")" << endl; 
    }

    return 0;
}

int main()
{
    Connection c;
    const int y = 50;
    const int x = 40;

    c.findConnectionPixel(y, x);
    c.changeConnectionPixel();
    return 0;
}
