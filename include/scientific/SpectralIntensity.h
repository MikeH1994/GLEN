#ifndef SPECTRALINTENSITY_H
#define SPECTRALINTENSITY_H

#include "stdafx.h"

class SpectralIntensity{
public:
   double _minWavelength;
   double _maxWavelength;
   double _wavelengthIncrements;
   unsigned int _nBins;
   std::vector<double> _intensities;
   std::vector<double> _wavelengths;

   SpectralIntensity(double minWavelength, double maxWavelength, unsigned int nBins);
};

#endif // SPECTRALINTENSITY_H
