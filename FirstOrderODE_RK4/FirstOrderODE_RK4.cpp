#include"vector"
#include"iostream"
#include"fstream"
#include"math.h"

using namespace std;

double f(double x, double y){
    /*
    
    Function defined by dy_dx = f(x, y). Free to change
    
    */

    return y;
}

double RK4(double y_0, double x_0, double dx){

    // initialise variables
    double k1, k2, k3, k4;    // RK4 coefficients
    double y_1, x_1;          // new x and y values

    // calculate coefficients
    k1 = f(x_0, y_0);
    k2 = f(x_0 + dx/2, y_0 + k1*(dx/2));
    k3 = f(x_0 + dx/2, y_0 + k2*(dx/2));
    k4 = f(x_0 + dx, y_0 + dx*k3);

    // increment y1 and return
    y_1 = y_0 + (dx/6)*(k1 + 2*k2 + 2*k3 + k4);

    return y_1;

}


int main(){

    // -------------- CHANGE THESE -----------------

    double y_0 = -1;
    double x_start = 0;
    double x_end = 4;
    double n = 5000; 

    // ---------------------------------------------

    if(x_end <= x_start){
        cout << "x_end needs to be greater than x_start!" << endl;
        exit(0);
    }

    if(n <= 0){
        cout << "n needs to be greater than 0!" << endl;
        exit(0);
    }

    double dx = (x_end - x_start)/n;

    vector<double> x = {x_start};
    vector<double> y = {y_0};

    double x_0 = x_start;

    while(x_0 <= x_end){

        y_0 = RK4(y_0, x_0, dx);
        x_0 += dx;

        x.push_back(x_0);
        y.push_back(y_0);

    }

    ofstream f1("solution.csv");
    f1 << "x,y" << endl;

    for(int i = 0; i<x.size(); i++){
        f1 << x[i] << "," << y[i] << endl;
    }

    f1.close();
}