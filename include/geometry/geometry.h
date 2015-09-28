#pragma once

#include "parser/parser.h"

class GeometryStructure {
  public:
    GeometryStructure (ParamParser& pp);
    ~GeometryStructure();
  
    int getM();
    int getN();

    // Stokes Data
    double * getStokesData();
    // Subsections of Stokes Data
    double * getVelocityData();
    double * getUVelocityData();
    double * getVVelocityData();
    double * getPressureData();

    // Velocity Boundary Data
    double * getVelocityBoundaryData();
    // Subsections of Velocity Boundary Data
    double * getUVelocityBoundaryData();
    double * getVVelocityBoundaryData();

    // Forcing Data
    double * getForcingData();
    // Subsections of Forcing Data
    double * getUForcingData();
    double * getVForcingData();

    // Viscosity Data 
    double * getViscosityData();

    // Temperature Data
    double * getTemperatureData();

    // Temperature Boundary Data
    double * getTemperatureBoundaryData();
    // Subsections of Temperature Boundary Data
    double * getUTemperatureBoundaryData();
    double * getVTemperatureBoundaryData();
  
  private:

    /* BE CAREFUL NOT TO CONFUSE THE GRID WITH AN M x N MATRIX!
     *
     * The geometry of the domain in terms of M, N, and h is as follows:
     *
     * The domain is the rectangle [0,0] X [M*h, N*h].
     *
     * The are M X N cells and M X N cell centers, with (M+1) X N vertical
     * cells edges (left and right) on which lie the uVelocities, including
     * the uVelocity boundary conditions at i = 0 and i = M+1, and M X (N+1)
     * horizontal (top and bottom) edges on which lie the vVelocities,
     * including the vVelocity boundary conditions at j = 0 and j = N+1.
     *
     * The upper right hand corner of cell i,j is the point (i * h, j * h).
     *
     * The lower left hand corner of cell i,j is the point ((i-1) * h, (j-1) * h).
     *
     * The CENTER of cell i,j is the point ((i+1/2) * h, (j+1/2) * h).
     *
     */

	int M; // Number of cells in a row: M * h = width of the Domain
    int N; // Number of cells in a column:  N * h = height of the Domain

    // Data pointers
    // Stokes solution data contains velocity and pressure solutions.
    double * stokesData;
    // Velocity boundary data contains prescribed velocity boundary values.
    double * velocityBoundaryData;

    // Forcing data contains Stokes equation forcing terms.
    double * forcingData;

    // Viscosity data
    double * viscosityData;

    // Temperature data
    double * temperatureData;
    // Temperature Boundary Data
    double * temperatureBoundaryData;
};
