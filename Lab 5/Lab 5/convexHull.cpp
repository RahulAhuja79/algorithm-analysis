#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int checkDirection(Point a, Point b, Point c) {
    int res = (b.y - a.y) * (c.x - b.x) -
              (b.x - a.x) * (c.y - b.y);

    if (res == 0) return 0;
    return (res > 0) ? 1 : 2;
}

vector<Point> joinHulls(vector<Point> leftHull, vector<Point> rightHull) {

    int nL = leftHull.size();
    int nR = rightHull.size();

    int idxL = 0, idxR = 0;

    for (int i = 1; i < nL; i++)
        if (leftHull[i].x > leftHull[idxL].x)
            idxL = i;

    for (int i = 1; i < nR; i++)
        if (rightHull[i].x < rightHull[idxR].x)
            idxR = i;

    int upL = idxL, upR = idxR;
    bool flag = true;

    while (flag) {
        flag = false;

        while (checkDirection(rightHull[upR], leftHull[upL],
                              leftHull[(upL + 1) % nL]) == 2)
            upL = (upL + 1) % nL;

        while (checkDirection(leftHull[upL], rightHull[upR],
                              rightHull[(nR + upR - 1) % nR]) == 1) {
            upR = (nR + upR - 1) % nR;
            flag = true;
        }
    }

    int lowL = idxL, lowR = idxR;
    flag = true;

    while (flag) {
        flag = false;

        while (checkDirection(leftHull[lowL], rightHull[lowR],
                              rightHull[(lowR + 1) % nR]) == 2)
            lowR = (lowR + 1) % nR;

        while (checkDirection(rightHull[lowR], leftHull[lowL],
                              leftHull[(nL + lowL - 1) % nL]) == 1) {
            lowL = (nL + lowL - 1) % nL;
            flag = true;
        }
    }

    vector<Point> result;

    int pos = upL;
    result.push_back(leftHull[pos]);
    while (pos != lowL) {
        pos = (pos + 1) % nL;
        result.push_back(leftHull[pos]);
    }

    pos = lowR;
    result.push_back(rightHull[pos]);
    while (pos != upR) {
        pos = (pos + 1) % nR;
        result.push_back(rightHull[pos]);
    }

    return result;
}

vector<Point> solveHull(vector<Point> pts) {

    if (pts.size() <= 3)
        return pts;

    int mid = pts.size() / 2;

    vector<Point> leftPart(pts.begin(), pts.begin() + mid);
    vector<Point> rightPart(pts.begin() + mid, pts.end());

    leftPart = solveHull(leftPart);
    rightPart = solveHull(rightPart);

    return joinHulls(leftPart, rightPart);
}

int main() {

    // 🔹 Changed input values
    vector<Point> pts = {
        {1,4}, {4,2}, {2,5}, {6,1}, {5,3}, {3,0}, {7,4}, {0,2}
    };

    sort(pts.begin(), pts.end(),
         [](Point a, Point b) {
             return a.x < b.x;
         });

    vector<Point> hull = solveHull(pts);

    cout << "Convex Hull:\n";
    for (auto p : hull) {
        cout << "(" << p.x << "," << p.y << ") ";
    }

    return 0;
}