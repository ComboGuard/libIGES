/*
 * file: entity122.h
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
 * Description: IGES Entity 122: Tabulated Cylinder, Section 4.19, p.119(147+)
 */

#ifndef ENTITY_122_H
#define ENTITY_122_H

#include <libigesconf.h>
#include <mcad_elements.h>
#include <iges_curve.h>

// Note:
// The associated parameter data are:
// + DE: Int: pointer to DE entry of directrix
// + LX: Real: coordinates of terminate point of generatrix
// + LY: Real
// + LZ: Real
//
// Forms: 0
//
// Unused DE items:
// + Structure
//


/**
 * Class IGES_ENTITY_122
 * represents a Tabulated Cylinder which consists of a line segment,
 * the generatrix, which is swept along a 2D or 3D curve, the
 * directrix. The implied start point of the generatrix is the start
 * point of the directrix.
 */
class IGES_ENTITY_122 : public IGES_ENTITY
{
protected:

    friend class IGES;
    virtual bool format( int &index );
    virtual bool rescale( double sf );

    IGES_CURVE* DE;
    int iDE;

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
    MCAD_API IGES_ENTITY_122( IGES* aParent );
    virtual MCAD_API ~IGES_ENTITY_122();

    // Inherited virtual functions
    virtual MCAD_API bool SetEntityForm(int aForm);
    virtual MCAD_API bool SetHierarchy(IGES_STAT_HIER aHierarchy);

    // parameters
    MCAD_API double LX;  //< X value of Generatrix end point
    MCAD_API double LY;  //< Y value of Generatrix end point
    MCAD_API double LZ;  //< Z value of Generatrix end point

    /**
     * Function GetDE
     * retrieves a pointer to the Directrix Entity 2D/3D curve
     * and returns true on success.
     *
     * @param aPtr = handle to store a pointer to the directrix curve
     */
    MCAD_API bool GetDE( IGES_CURVE** aPtr );

    /**
     * Function SetDE
     * sets the curve entity of the Directrix and returns true on success.
     *
     * @param aPtr = pointer to the Directrix curve
     */
    MCAD_API bool SetDE( IGES_CURVE* aPtr );
};

#endif  // ENTITY_122_H
