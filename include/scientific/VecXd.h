#ifndef VECXD_H
#define VECXD_H

#include "stdafx.h"

class VecXd{
private:
    void calculateMagnitude();
protected:
    double* _data;
    bool _deleteOnDeconstructor = false;
    unsigned int _length;
public:
    VecXd(double* data, unsigned int length);
    VecXd(unsigned int length);
    VecXd(unsigned int length, double defaultValue);
    VecXd();
    ~VecXd();

    void normalise();
    double magnitude();
    void copyTo(const VecXd &other);
    double dot(VecXd &other);


    double& at(unsigned int index);
    double & operator[](unsigned int index);
    void    addScalar(double scalar);
    void    add(VecXd &other);
    void    add(VecXd &other, VecXd &dst);
    void    subtract(VecXd &other);
    void    subtract(VecXd &other, VecXd &dst);
    void    multiplyScalar(double scalar);
    void    multiplyScalar(double scalar, VecXd &dst);
    void    multiplyElementWise(VecXd &other);
    void    multiplyElementWise(VecXd &other, VecXd &dst);

};

#endif // VECTORXD_H
