/*
 * file: entity110.h
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
 *
 * This file is part of libIGES.
 *
 * libIGES is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libIGES is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libIGES.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
 * Description: IGES Entity 120: Surface of Revolution, Section 4.18, p.116+ (144+)
 */

#ifndef ENTITY_120_H
#define ENTITY_120_H

#include <libigesconf.h>
#include <iges_entity.h>

// NOTE:
// The associated parameter data are:
// + L: Pointer: Line entity, the axis of revolution
// + C: Pointer: Curve entity (generatrix)
// + SA: Real: Start Angle, Radians
// + TA: Real: Terminate Angle, Radians
//
// Forms: 0 only
//
// Unused DE items:
// + Structure
//

class IGES_CURVE;


/**
 * Class IGES_ENTITY_120
 * represents a Surface of Revolution which consists of a
 * 2D/3D Generatrix curve, an axis of revolution,
 * and a Start and Terminate angle.
 */
class IGES_ENTITY_120 : public IGES_ENTITY
{
protected:

    friend class IGES;
    virtual bool format( int &index );
    virtual bool rescale( double sf );

    IGES_CURVE* L;
    IGES_CURVE* C;

public:
    // public functions for libIGES only
    virtual bool associate(std::vector<IGES_ENTITY *> *entities);
    virtual bool unlink(IGES_ENTITY *aChild);
    virtual bool isOrphaned( void );
    virtual bool addReference(IGES_ENTITY *aParentEntity, bool &isDuplicate);
    virtual bool delReference(IGES_ENTITY *aParentEntity);
    virtual bool readDE(IGES_RECORD *aRecord, std::ifstream &aFile, int &aSequenceVar);
    virtual bool readPD(std::ifstream &aFile, int &aSequenceVar);

public:
    MCAD_API IGES_ENTITY_120( IGES* aParent );
    virtual MCAD_API ~IGES_ENTITY_120();

    // Inherited virtual functions
    virtual MCAD_API bool SetEntityForm( int aForm );
    virtual MCAD_API bool SetHierarchy( IGES_STAT_HIER aHierarchy );

    int iL;         // DE pointer to line entity
    int iC;         // DE pointer to curve entity

    /**
     * Function GetL
     * retrieves a pointer to the axis of revolution and
     * returns true on success.
     *
     * @param aCurve = handle to store pointer to axis of revolution, a line entity (Type 110)
     */
    MCAD_API bool GetL( IGES_CURVE** aCurve );

    /**
     * Function GetAxis
     * retrieves a pointer to the axis of revolution and
     * returns true on success.
     *
     * @param aCurve = handle to store pointer to axis of revolution, a line entity (Type 110)
     */
    MCAD_API bool GetAxis( IGES_CURVE** aCurve );

    /**
     * Function SetL
     * sets the axis of revolution and returns true on success.
     *
     * @param aCurve = pointer to line entity (Type 110) representing the axis of revolution
     */
    MCAD_API bool SetL( IGES_CURVE* aCurve );

    /**
     * Function SetAxis
     * sets the axis of revolution and returns true on success.
     *
     * @param aCurve = pointer to line entity (Type 110) representing the axis of revolution
     */
    MCAD_API bool SetAxis( IGES_CURVE* aCurve );

    /**
     * Function GetC
     * retrieves a pointer to the 2D/3D Generatrix curve and
     * returns true on success.
     *
     * @param aCurve = handle to store pointer to generatrix curve
     */
    MCAD_API bool GetC( IGES_CURVE** aCurve );

    /**
     * Function GetGeneratrix
     * retrieves a pointer to the 2D/3D Generatrix curve and
     * returns true on success.
     *
     * @param aCurve = handle to store pointer to generatrix curve
     */
    MCAD_API bool GetGeneratrix( IGES_CURVE** aCurve );


    /**
     * Function SetC
     * sets the 2D/3D Generatrix curve and returns true on success.
     *
     * @param aCurve = pointer to generatrix curve
     */
    MCAD_API bool SetC( IGES_CURVE* aCurve );

    /**
     * Function SetGeneratrix
     * sets the 2D/3D Generatrix curve and returns true on success.
     *
     * @param aCurve = pointer to generatrix curve
     */
    MCAD_API bool SetGeneratrix( IGES_CURVE* aCurve );

    /**
     * Start Angle (radians)
     */
    MCAD_API union
    {
        double SA;
        double startAngle;
    };

    /**
     * Terminal Angle (radians)
     */
    MCAD_API union
    {
        double TA;
        double endAngle;
    };
};

#endif  // ENTITY_TEMP_H
