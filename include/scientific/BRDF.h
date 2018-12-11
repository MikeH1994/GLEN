#ifndef BRDF_H
#define BRDF_H

#include "VecXd.h"

/*
  Class containing the combined Bidirectional Reflection Distribution Function (BRDF) and
  Direction Emissivity Distribution Function (DEDF) of a material.

  */

class BRDF{
public:    
    /*
      \brief Returns the ratio of the intensity at thetaO to the total intensity along thetaI (i.e. normalised to 1),
      at a given temperature.

      \params lambda the wavelength at which the BRDF is being computed
      \params T the temperature, in Kelvin, in which the BRDF is being computed
      \params thetaI the incident angle
      \params thetaO the outgoing angle
      */
    std::shared_ptr<VecXd> brdf(double T, double thetaI, double thetaO);
    /*
      \brief Returns the directional emissivities of the surface, computed at a temperature T and angle theta

      */
    std::shared_ptr<VecXd> emissivity(double T, double theta);


    static void createBRDF(double s, double d);

};

#endif
