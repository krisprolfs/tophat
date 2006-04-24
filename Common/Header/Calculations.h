#if !defined(AFX_CALCULATIONS_H__695AAC30_F401_4CFF_9BD9_FE62A2A2D0D2__INCLUDED_)
#define AFX_CALCULATIONS_H__695AAC30_F401_4CFF_9BD9_FE62A2A2D0D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Parser.h"
#include <windows.h>

#define NUMTHERMALBUCKETS 10

typedef struct _DERIVED_INFO
{
  double Vario;
  double LD;
  double CruiseLD;
  double VMacCready;
  double Average30s;
  double BestCruiseTrack;
  double AverageThermal;
  double ThermalGain;
  double LastThermalAverage;
  double LastThermalGain;
  double LastThermalTime;
  double ClimbStartLat;
  double ClimbStartLong;
  double ClimbStartAlt;
  double ClimbStartTime;
  double CruiseStartLat;
  double CruiseStartLong;
  double CruiseStartAlt;
  double CruiseStartTime;
  double WindSpeed;
  double WindBearing;
  double Bearing;
  double TerrainAlt;
  bool TerrainValid;
  double Heading;
  double AltitudeAGL;
  int    Circling;
  int    FinalGlide;
  int    AutoMacCready;
  int    Flying;
  double NextAltitudeRequired;
  double NextAltitudeDifference;
  double FinalAltitudeRequired;
  double FinalAltitudeDifference;
  double TaskDistanceToGo;
  double TaskDistanceCovered;
  double TaskTimeToGo;
  double TaskStartTime;
  double TaskSpeed;
  double TaskAltitudeRequired;
  double TaskAltitudeDifference;
  double LDFinish;
  double LDNext;
  double LegDistanceToGo;
  double LegDistanceCovered;
  double LegTimeToGo;
  double LegStartTime;
  double LegSpeed;
  double NextLatitude;
  double NextLongitude;
  double NextAltitude;
  double AATMaxDistance;
  double AATMinDistance;
  double AATTargetDistance;
  double AATTimeToGo;
  double AATMaxSpeed;
  double AATTargetSpeed;
  double AATMinSpeed;
  double PercentCircling;

  double TerrainWarningLongitude;
  double TerrainWarningLatitude;

  // JMW moved calculated waypoint info here

  double WaypointBearing;
  double WaypointDistance;
  double WaypointSpeed;

  // JMW thermal band data
  double MaxThermalHeight;
  int    ThermalProfileN[NUMTHERMALBUCKETS];
  double ThermalProfileW[NUMTHERMALBUCKETS];

  double NettoVario;

  // optimum speed to fly instantaneously
  double VOpt;

  // JMW estimated track bearing at next time step
  double NextTrackBearing;

  // whether Speed-To-Fly audio are valid or not
  bool STFMode;

  // JMW energy height excess to slow to best glide speed
  double EnergyHeight;

  double TurnRate;

  // reflects whether aircraft is in a start/finish/aat/turn sector
  bool IsInSector;
  bool IsInAirspace;

} DERIVED_INFO;

#include "RasterTerrain.h"


int DoCalculations(NMEA_INFO *Basic, DERIVED_INFO *Calculated);
int DoCalculationsVario(NMEA_INFO *Basic, DERIVED_INFO *Calculated);
void DoCalculationsSlow(NMEA_INFO *Basic, DERIVED_INFO *Calculated);

void OpenTerrain(void);
void CloseTerrain(void);
void AddSnailPoint(void);
double FinalGlideThroughTerrain(double bearing, NMEA_INFO *Basic,
				DERIVED_INFO *Calculated, double *retlat,
				double *retlon,
				double maxsearchrange);

bool ClearAirspaceWarnings(bool ack, bool allday=false);
void ResumeAbortTask(int set = 0);
void RefreshTaskStatistics(void);
void  SetWindEstimate(double speed, double bearing);

double PirkerAnalysis(NMEA_INFO *Basic, DERIVED_INFO *Calculated,
		      double bearing,
		      double GlideSlope);

#endif
