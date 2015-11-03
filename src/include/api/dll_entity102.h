/*
 * file: dll_entity102.h
 *
 * Copyright 2015, Dr. Cirilo Bernardo (cirilo.bernardo@gmail.com)
 *
 * This file is part of libIGES.
 *
 * libIGES is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libIGES is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, If not, see
 * <http://www.gnu.org/licenses/> or write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/*
 * Description: IGES Entity 102: Composite Curve, Section 4.4, p.69+ (97+)
 */

#ifndef DLL_ENTITY_102_H
#define DLL_ENTITY_102_H

#include <libigesconf.h>
#include <api/dll_iges_curve.h>


class MCAD_API DLL_IGES_ENTITY_102 : public DLL_IGES_CURVE
{
public:
    DLL_IGES_ENTITY_102( IGES* aParent, bool create );
    DLL_IGES_ENTITY_102( DLL_IGES& aParent, bool create );
    virtual ~DLL_IGES_ENTITY_102();

    virtual bool NewEntity( void );

    bool AddSegment( IGES_CURVE* aSegment );
};

#endif  // DLL_ENTITY_102_H
