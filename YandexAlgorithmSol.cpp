#include <iostream>

using namespace std;

int resultFunc(double time){
    if(time >= 0){
        cout << fixed;
        cout.precision(10);
        cout << "YES" << endl << time;
        return 0;
    }
        cout << "NO" << endl;
        return 0;
}

int main(){
    double L, Xk, Vk, Xa, Va, result;
    cin>>L>>Xk>>Vk>>Xa>>Va;
    //Considering question by using absolute equations.
    // Same V's
    if(Va-Vk == 0){
        result = (L - (Xk + Xa)) / (2 * Va);
        resultFunc(result);
    }
    else{
        result = (Xk-Xa)/(Va-Vk);
        if(result < 0){
            if(Va != 0) 
                result = (L -(Xk + Xa)) / (Va);
            else 
                result = (L -(Xk + Xa)) / (Vk);
                
            resultFunc(result);
        }
        else
            resultFunc(result);
        // There must be one more condition statement for absolute value.
    }
    return 0;
}
