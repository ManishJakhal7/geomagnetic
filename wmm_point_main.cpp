#include<bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include<iostream>

#include "EGM96151.h"
#include "Geomagnetismheader.h"

//#include "magneticModel.h"

using namespace std;

/* char MAG_GeomagIntroduction_WMM(MAGtype_MagneticModel* MagneticModel, char* VersionDate, char* ModelDate)
{
    
}

*/
/*
#ifndef MAGNETIC_MODEL_H
#define MAGNETIC_MODEL_H

#endif // MAGNETIC_MODEL_H

struct MAGtype_MagneticModel {
    int epoch;
    int nMax;
};

struct MAGtype_Ellipsoid {
    // members not shown
};

struct MAGtype_CoordSpherical {
    // members not shown
};

struct MAGtype_CoordGeodetic {
    // members not shown
};

struct MAGtype_Date {
    // members not shown
};

struct MAGtype_GeoMagneticElements {
    // members not shown
};

struct MAGtype_Geoid {
    // members not shown
};
  */
char MAG_GeomagIntroduction_WMM(MAGtype_MagneticModel *MagneticModel, char *VersionDate, char *ModelDate) {
    char help = 'h';
    char ans;
    cout<< "\n\n Welcome to the World Magnetic Model (WMM)" << MagneticModel->epoch << " C-Program\n\n";
    cout << " --- Model Release Date: " << ModelDate << " ---\n";
    cout << " --- Software Release Date: " << VersionDate << " ---\n\n";
    cout << "\n This program estimates the strength and direction of ";
    cout << "\n Earth's main Magnetic field for a given point/area.";
    while (help != 'c' && help != 'C')
    {
        cout << "\n Enter h for help and contact information or c to continue.";
        cout << "\n >";
        cin>>help;
        cin.ignore();

        if ((help == 'h') || (help == 'H'))
        {
            cout << "\n Help information ";

            cout << "\n The World Magnetic Model (WMM) for " << MagneticModel->epoch;
            cout << "\n is a model of Earth's main magnetic field. The WMM";
            cout << "\n is recomputed every five (5) years, in years divisible by ";
            cout << "\n five (i.e. 2010, 2015). See the contact information below";
            cout << "\n to obtain more information on the WMM and associated software.";
            cout << "\n ";
            cout << "\n Input required is the location in geodetic latitude and";
            cout << "\n longitude (positive for northern latitudes and eastern ";
            cout << "\n longitudes), geodetic altitude in meters, and the date of ";
            cout << "\n interest in years.";

            cout << "\n\n\n The program computes the estimated Magnetic Declination";
            cout << "\n (Decl) which is sometimes called MagneticVAR, Inclination (Incl), Total";
            cout << "\n Intensity (F or TI), Horizontal Intensity (H or HI), Vertical";
            cout << "\n Intensity (Z), and Grid Variation (GV). Declination and Grid";
            cout << "\n Variation are measured in units of degrees and are considered";
            cout << "\n positive when east or north. Inclination is measured in units";
            cout << "\n of degrees and is considered positive when pointing down (into";
            cout << "\n the Earth). The WMM is referenced to the WGS-84 ellipsoid and";
            cout << "\n is valid for 5 years after the base epoch. Uncertainties for the";
            cout << "\n WMM are one standard deviation uncertainties averaged over the globe.";
            cout << "\n We represent the uncertainty as constant values in Incl, F, H, X,";
            cout << "\n Y, and Z. Uncertainty in Declination varies depending on the strength";
            cout << "\n of the horizontal field. For more information see the WMM Technical";
            cout << "\n Report.";

            cout << "\n\n\n It is very important to note that a degree and order 12 model,";
            cout << "\n such as WMM, describes only the long wavelength spatial Magnetic ";
            cout << "\n fluctuations due to Earth's core. Not included in the WMM series";
            cout << "\n models are intermediate and short wavelength spatial fluctuations ";
            cout << "\n that originate in Earth's mantle and crust. Consequently, isolated";
            cout << "\n angular errors at various positions on the surface (primarily over";
            cout << "\n land, along continental margins and over oceanic sea-mounts, ridges and";
            cout << "\n trenches) of`````` several degrees may be expected. Also not included in";
            cout << "\n the model are temporal fluctuations of magnetospheric and ionospheric";
            cout << "\n origin. On the days during and immediately following magnetic storms,";
            cout << "\n temporal fluctuations can cause substantial deviations of the Geomagnetic";
            cout << "\n field from model values. If the required declination accuracy is";
            cout << "\n more stringent than the WMM series of models provide, the user is";
            cout << "\n advised to request special (regional or local) surveys be performed";
            cout << "\n and models prepared. The World Magnetic Model is a joint product of";
            cout << "\n the United States' National Geospatial-Intelligence Agency (NGA) and";
            cout << "\n the United Kingdom's Defence Geographic Centre (DGC). The WMM was";
            cout << "\n developed jointly by the National Centers for Environmental Information";
            cout << "\n (NCEI, Boulder CO, USA) and the British Geological Survey (BGS, ";
            cout << "\n Edinburgh, Scotland).";

            cout << "\n\n\n Contact Information";

            cout << "\n  Software and Model Support";
            cout << "\n	National Centers for Environmental Information";
            cout << "\n	NOAA E/NE42";
            cout << "\n	325 Broadway";
            cout << "\n	Boulder, CO 80305 USA";
            cout << "\n	Attn: Manoj Nair or Arnaud Chulliat";
            cout << "\n	Phone:  (303) 497-4642 or -6522"; 
            cout << "\n	Email:  Geomag.Models@noaa.gov \n";
        }
    }
    ans = help;
    return ans;

}

int main() {

    char MAG_GeomagIntroduction_WMM(MAGtype_MagneticModel *MagneticModel, char *VersionDate, char *ModelDate);
    
    MAGtype_MagneticModel *MagneticModels[1], *TimedMagneticModel;
    MAGtype_Ellipsoid Ellip;
    MAGtype_CoordSpherical CoordSpherical;
    MAGtype_CoordGeodetic CoordGeodetic;
    MAGtype_Date UserDate;
    MAGtype_GeoMagneticElements GeoMagneticElements, Errors;
    MAGtype_Geoid Geoid;
    char ans[20], b;
    char filename[] = "WMM.COF";
    char VersionDate[12];
    int NumTerms, Flag = 1, nMax = 0;
    int epochs = 1;

    // Memory allocation

    strncpy(VersionDate, VERSIONDATE_LARGE + 39, 11);
    VersionDate[11] = '\0';

    if(!MAG_robustReadMagModels(filename, &MagneticModels, epochs)) {
        printf("\n WMM.COF not found.  Press enter to exit... \n ");
        fgets(ans, 20, stdin);
        return 1;
    }

    if(nMax < MagneticModels[0]->nMax) nMax = MagneticModels[0]->nMax;
    NumTerms = ((nMax + 1) * (nMax + 2) / 2);
    TimedMagneticModel = MAG_AllocateModelMemory(NumTerms); /* For storing the time modified WMM Model parameters */

    if(MagneticModels[0] == NULL || TimedMagneticModel == NULL) {
        MAG_Error(2);
    }

    MAG_SetDefaults(&Ellip, &Geoid); /* Set default values and constants */

    // Check for Geographic Poles

    // Set EGM96 Geoid parameters

    b = MAG_GeomagIntroduction_WMM(MagneticModels[0], VersionDate, MODEL_RELEASE_DATE);

    while(Flag == 1 && b != 'x') {
        if(MAG_GetUserInput(MagneticModels[0], &Geoid, &CoordGeodetic, &UserDate) == 1) /*Get User Input */
        {
            MAG_GeodeticToSpherical(Ellip, CoordGeodetic, &CoordSpherical); /*Convert from geodetic to Spherical Equations: 17-18, WMM Technical report*/
            MAG_TimelyModifyMagneticModel(UserDate, MagneticModels[0], TimedMagneticModel); /* Time adjust the coefficients, Equation 19, WMM Technical report */
            MAG_Geomag(Ellip, CoordSpherical, CoordGeodetic, TimedMagneticModel, &GeoMagneticElements); /* Computes the geoMagnetic field elements and their time change*/
            MAG_CalculateGridVariation(CoordGeodetic, &GeoMagneticElements);
            MAG_WMMErrorCalc(GeoMagneticElements.H, &Errors);
            MAG_PrintUserDataWithUncertainty(GeoMagneticElements, Errors, CoordGeodetic, UserDate, TimedMagneticModel, &Geoid); /* Print the results */
        }
        string ansStr;
        do {
            printf("\n\n Do you need more point data ? (y or n) \n ");
            getline(cin, ansStr);
        } while (ansStr.empty());

        switch(ansStr[0]) {
            case 'Y':
            case 'y':
                Flag = 1;
                break;
            case 'N':
            case 'n':
                Flag = 0;
                break;
            default:
                Flag = 0;
                break;
        }
    }

    MAG_FreeMagneticModelMemory(TimedMagneticModel);
    MAG_FreeMagneticModelMemory(MagneticModels[0]);

    return 0;
}