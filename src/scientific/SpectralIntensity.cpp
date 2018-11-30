#include "SpectralIntensity.h"


SpectralIntensity::SpectralIntensity(double minWavelength, double maxWavelength, unsigned int nBins){
    _minWavelength = minWavelength;
    _maxWavelength = maxWavelength;
    _nBins = nBins;
    _wavelengthIncrements = (maxWavelength-minWavelength)/nBins;

    for(unsigned int i = 0; i<nBins; i++){
        _wavelengths.push_back(_minWavelength + i*_wavelengthIncrements);
        _intensities.push_back(0);
    }
}
