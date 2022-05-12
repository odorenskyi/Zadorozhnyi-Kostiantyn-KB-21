#ifndef MODULESZADOROZHNYI_H_INCLUDED
#define MODULESZADOROZHNYI_H_INCLUDED

#include <cmath>

class ClassLab12_Zadorozhnyi{
public:
    ClassLab12_Zadorozhnyi(){}
    ClassLab12_Zadorozhnyi(float radius);
    void setRadius(float radius);
    float getRadius();
    float getVolumeBall();
private:
    float radius = 0.0;
};

ClassLab12_Zadorozhnyi::ClassLab12_Zadorozhnyi(float radius){
    this->radius = radius;
}

void ClassLab12_Zadorozhnyi::setRadius(float radius){
    this->radius = radius;
}

float ClassLab12_Zadorozhnyi::getRadius(){
    return radius;
}

float ClassLab12_Zadorozhnyi::getVolumeBall(){
    return (4 * M_PI * pow(radius, 3))/3;
}

#endif // MODULESZADOROZHNYI_H_INCLUDED
