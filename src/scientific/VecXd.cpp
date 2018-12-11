#include "Vec3d.h"

VecXd::VecXd(double* data, unsigned int length){
    _deleteOnDeconstructor = false;
    _data = data;
    _length = length;
    calculateMagnitude();
}

VecXd::VecXd(unsigned int length){
    _deleteOnDeconstructor = true;
    _data = new double[length];
    for(unsigned int i = 0; i<length; i++){
        _data[i] = 0;
    }
}

VecXd::VecXd(unsigned int length, double defaultValue){
    _deleteOnDeconstructor = true;
    _data = new double[length];
    for(unsigned int i = 0; i<length; i++){
        _data[i] = defaultValue;
    }
}

VecXd::VecXd(){

}

VecXd::~VecXd(){
    if (_deleteOnDeconstructor){
        delete[] _data;
    }
}

void VecXd::normalise(){
    double mag = magnitude();
    if (mag<EPS_){
        throw std::runtime_error("Cannot normalise a vector with a magnitude of less than one");
    }
    multiplyScalar(1.0/mag);
}

double VecXd::magnitude(){
    return sqrt(_data[0]*_data[0] + _data[1]*_data[1] + _data[2]*_data[2]);
}

void VecXd::copyTo(const VecXd &other){
    if (_length!=other._length){
        throw std::runtime_error("Vectors are not same size in copyTo()");
    }
    for(unsigned int i = 0; i<_length; i++){
        other._data[i] = _data[i];
    }
}

double VecXd::dot(VecXd &other){
    if (_length!=other._length){
        throw std::runtime_error("Vectors are not the same size in dot product");
    }
    double dotProduct = 0;
    for(unsigned int i = 0; i<_length; i++){
        dotProduct+=_data[i]*other._data[i];
    }
    return dotProduct;
}

double& VecXd::at(unsigned int index){
    return _data[index];
}

double & VecXd::operator[](unsigned int index){
    return _data[index];
}

void VecXd::addScalar(double scalar){
    for(unsigned int i = 0; i<_length; i++){
        _data[i]+=scalar;
    }
}

void VecXd::multiplyScalar(double scalar){
    multiplyScalar(scalar,*this);
}

void VecXd::multiplyScalar(double scalar, VecXd &dst){
    if (_length!=dst._length){
        throw std::runtime_error("Vectors not same length in multiplyScalar");
    }
    for(unsigned int i = 0; i<_length; i++){
        dst[i]=_data[i]*scalar;
    }
}

void VecXd::add(VecXd &other){
    add(other,*this);
}

void VecXd::add(VecXd &other,VecXd &dst){
    if (_length!=other._length||_length!=dst._length){
        throw std::runtime_error("Vectors are not the same time in addVector");
    }
    for(unsigned int i = 0; i<_length; i++){
        dst._data[i]=_data[i] + other._data[i];
    }
}

void VecXd::subtract(VecXd &other){
    subtract(other,*this);
}

void VecXd::subtract(VecXd &other,VecXd &dst){
    if (_length!=other._length||_length!=dst._length){
        throw std::runtime_error("Vectors are not the same time in addVector");
    }
    for(unsigned int i = 0; i<_length; i++){
        dst._data[i]=_data[i] - other._data[i];
    }
}

void VecXd::multiplyElementWise(VecXd &other){
    multiplyElementWise(other,*this);
}


void VecXd::multiplyElementWise(VecXd &other,VecXd &dst){
    if (_length!=other._length){
        throw std::runtime_error("Vectors are not the same size in multiplyByElements");
    }
    for(unsigned int i = 0; i<_length; i++){
        dst._data[i]=_data[i]*other._data[i];
    }
}
