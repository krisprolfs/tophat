/* Generated by Together */

#ifndef INTERMEDIATEPOINT_H
#define INTERMEDIATEPOINT_H
#include "OrderedTaskPoint.hpp"

/**
 * An IntermediatePoint is an abstract OrderedTaskPoint,
 * does not yet have an observation zone, nor defines
 * how scoring is performed within.
 * All IntermediatePoints shall have a preceding and following
 * taskpoint.
 *
 */
class IntermediatePoint: 
  public OrderedTaskPoint 
{
public:    
/** 
 * Constructor.
 * 
 * @param _oz Observation zone attached to this point
 * @param tp Global projection 
 * @param wp Waypoint origin of turnpoint
 * @param tb Task Behaviour defining options (esp safety heights)
 * @param b_scored Whether distance within OZ is scored 
 * 
 * @return Partially-initialised object
 */

  IntermediatePoint(ObservationZonePoint* _oz,
                    const TaskProjection& tp,
                    const Waypoint & wp, 
                    const TaskBehaviour& tb,
                    const bool b_scored): 
    OrderedTaskPoint(_oz, tp, wp, tb, b_scored) 
    {};

/** 
 * Retrieve elevation of taskpoint, taking into account
 * rules and safety margins.
 * 
 * @return Minimum allowable elevation of task point
 */
  virtual double getElevation() const;

};
#endif //INTERMEDIATEPOINT_H
