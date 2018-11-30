#ifndef BRDF_H
#define BRDF_H

/*
  Class containing the combined Bidirectional Reflection Distribution Function (BRDF) and
  Bidirection Emissivity Distribution Function (BEDF) of a material.

  */

class BDF{
public:    
    /*
      \brief Returns the ratio of the intensity at thetaO to the total intensity along thetaI (i.e. normalised to 1),
      at a given wavelength and temperature

      \params lambda the wavelength at which the BRDF is being computed
      \params T the temperature, in Kelvin, in which the BRDF is being computed
      \params thetaI the incident angle
      \params thetaO the outgoing angle
      */
    double f(double lambda, double T, double thetaI, double thetaO);
    /*
      \brief Returns the directional emissivity of the surface, computed at a temperature T, wavelength lambda and angle theta

      */
    double e(double lambda, double T, double theta);

};

#endif
