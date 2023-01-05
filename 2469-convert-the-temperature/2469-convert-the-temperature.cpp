class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> vec;
        double Kelvin=celsius + 273.15;
        double Fahrenheit=celsius*1.80 + 32;  
        vec.push_back(Kelvin);
        vec.push_back(Fahrenheit);
        return vec;
    }
};