#include<unordered_set>
#include<functional>
#include<iostream>
#include<iomanip>
#include<utility>
#include<memory>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
using namespace std;

struct Point{
    int x;
    int y;
}p[100];

double cross_product(Point p0, Point p1, Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
}
double dis(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
bool com(const Point &p1, const Point &p2){
    double temp = cross_product(p[0],p1,p2);
    if(fabs(temp)< 1e-6){
        return dis(p[0],p1) < dis(p[0],p2);
    }
    else{
        return temp>0;
    }
}
vector<Point> graham_scan(int n){
    vector<Point> ch;
    int top = 2;
    int index = 0;
    for(int i = 1;i<n;++i){
        if(p[i].y<p[index].y || (p[i].y==p[index].y && p[i].x<p[index].x)){
            index = i;
        }
    }
    swap(p[0], p[index]);
    ch.push_back(p[0]);
    sort(p+1,p+n,com);
    ch.push_back(p[1]);
    ch.push_back(p[2]);
    for(int i = 3;i<n;i++){
        while(top > 0 && cross_product(ch[top-1],p[i],ch[top])>=0){
            top--;
            ch.pop_back();
        }
        ch.push_back(p[i]);
        top++;
    }
    return ch;
}
int main(){
    int n;
    cout<<"Enter number of points: ";
    cin>>n;

    if(n<3){
        cout<<"Convex hull not possible with less than 3 points";
        return 1;
    }

    cout<<"Enter the points (x,y):"<<endl;
    for(int i = 0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    vector<Point> convexHull = graham_scan(n);

    cout<<"ConvexHull Points: "<<endl;
    for(const auto& point: convexHull){
        cout<<"("<<point.x<<" "<<point.y<<")"<<endl;
    }
    return 0;
}