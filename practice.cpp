// #include <iostream>
// using namespace std;
// #define d 256
// void rabinKarp(string txt, string pat, int q){
//     int n = txt.length();
//     int m = pat.length();
//     int h = 1;
//     int i,j;
//     int t=0,p=0;
//     for(i=0;i<m-1;i++)
//         h=(h*d)%q;
//     for(i = 0;i<m;i++){
//         p=(d * p+pat[i])%q;
//         t=(d * t+txt[i])%q;
//     }
//     for(i = 0;i<n-m;i++){
//         if(p==t){
//             for(j = 0;j<m;j++){
//                 if(pat[j]!=txt[i+j]){
//                     break;
//                 }
//             }
//             if(j==m){
//                 cout<<"Pattern foud at index: "<<i<<endl;
//             }
//         }
//         if(i<n-m){
//             t = (d*(t-txt[i]*h) + txt[i+m])%q;
//             if(t<0)
//                 t+=q;
//         }
//     }
// }
// int main(){
//     string txt,pat;
//     getline(cin,txt);
//     getline(cin,pat);
//     int q = 101;
//     rabinKarp(txt,pat,q);
// }



// //凸包-Graham扫描
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// #include <iomanip>
// #include <cstring>
// #include <cstdio>
// using namespace std;


// struct Point
// {
// 	double x;
// 	double y;
// }p[40000];

// //计算叉积，小于0说明p1在p2的逆时针方向(右边)，即p0p1的极角大于p0p2的极角
// double cross_product(Point p0, Point p1, Point p2)
// {
// 	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
// }

// //计算距离
// double dis(Point p1, Point p2)
// {
// 	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
// }

// bool com(const Point &p1, const Point &p2)
// {
// 	double temp = cross_product(p[0], p1, p2);
// 	if (fabs(temp) < 1e-6)//极角相等按照距离从小到大排序
//     {
//         return dis(p[0], p1) < dis(p[0], p2);
//     }
// 	else
//     {
//         return temp > 0;
//     }
// }

// vector<Point> graham_scan(int n)
// {
// 	vector<Point> ch;
// 	int top = 2;
// 	int index = 0;
// 	for (int i = 1; i < n; ++i)//选出Y坐标最小的点，若Y坐标相等，选择X坐标小的点
// 	{
// 		if (p[i].y < p[index].y || (p[i].y == p[index].y && p[i].x < p[index].x))
// 		{
// 			index = i;
// 		}
// 	}
// 	swap(p[0], p[index]);
// 	ch.push_back(p[0]);
// 	//按极角排序
// 	sort(p + 1, p + n, com);
// 	ch.push_back(p[1]);
// 	ch.push_back(p[2]);
// 	for (int i = 3; i < n; ++i)
// 	{
// 		while (top > 0 && cross_product(ch[top - 1], p[i], ch[top]) >= 0)
// 		{
// 			--top;
// 			ch.pop_back();
// 		}
// 		ch.push_back(p[i]);
// 		++top;
// 	}
// 	return ch;
// }

// //旋转卡壳法
// // double rotating_caliper(vector<Point> v)
// // {
// // 	double max_dis = 0.0;
// // 	int n = v.size();
// // 	if (n == 2)
// // 	{
// // 		max_dis = dis(v[0], v[1]);
// // 	}
// // 	else
// // 	{
// // 		v.push_back(v[0]);
// // 		int j = 2;
// // 		for (int i = 0; i < n; ++i)
// // 		{
// // 			while (cross_product(v[i], v[i + 1], v[j]) < cross_product(v[i], v[i + 1], v[j + 1]))
// // 			{
// // 				j = (j + 1) % n;
// // 			}
// // 			max_dis = max(max_dis, max(dis(v[j], v[i]), dis(v[j], v[i + 1])));
// // 		}
// // 	}
// // 	return max_dis;
// // }
// int main() {
//     int n;
//     cout << "Enter number of points: ";
//     cin >> n;

//     if (n < 3) {
//         cout << "Convex hull is not possible with less than 3 points." << endl;
//         return 0;
//     }

//     cout << "Enter the points (x y):" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> p[i].x >> p[i].y;
//     }

//     vector<Point> convexHull = graham_scan(n);

//     cout << "Convex Hull Points:" << endl;
//     for (const auto& point : convexHull) {
//         cout << "(" << point.x << ", " << point.y << ")" << endl;
//     }

//     // double maxDistance = rotating_caliper(convexHull);
//     // cout << "Maximum Distance between two hull points: " << fixed << setprecision(6) << maxDistance << endl;

//     return 0;
// }


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
    int x ;
    int y ;
}p[100];
double cross_product(Point p0, Point p1, Point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int dis(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
bool com(const Point &p1, const Point &p2){
    double temp = cross_product(p[0],p1,p2);
    if(fabs(temp)<1e-6){
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
    for(int i = 1;i<n;i++){
        if(p[i].y < p[index].y || (p[i].y == p[index].y && p[i].x < p[index].x)){
            index = i;
        }
    }
    swap(p[0],p[index]);
    ch.push_back(p[0]);
    sort(p+1,p+n,com);
    ch.push_back(p[1]);
    ch.push_back(p[2]);
    for(int i = 3;i<n;i++){
        while(top > 0 && cross_product(ch[top-1], p[i], ch[top])>=0){
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