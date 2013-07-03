/********************************************************************************
* ReactPhysics3D physics library, http://code.google.com/p/reactphysics3d/      *
* Copyright (c) 2010-2013 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/

#ifndef REACTPHYSICS3D_CONFIGURATION_H
#define	REACTPHYSICS3D_CONFIGURATION_H

// Libraries
#include <limits>
#include <cfloat>
#include <utility>
#include "decimal.h"

// Windows platform
#if defined(WIN32) ||defined(_WIN32) || defined(_WIN64) ||defined(__WIN32__) || defined(__WINDOWS__)
    #define WINDOWS_OS
#elif defined(__APPLE__)     // Apple platform
    #define APPLE_OS
#elif defined(__linux__) || defined(linux) || defined(__linux)    // Linux platform
    #define LINUX_OS
#endif

/// Namespace reactphysics3d
namespace reactphysics3d {

// ------------------- Type definitions ------------------- //

typedef unsigned int uint;
typedef long unsigned int luint;
typedef luint bodyindex;
typedef std::pair<bodyindex, bodyindex> bodyindexpair;

// ------------------- Enumerations ------------------- //

/// Position correction technique used in the constraint solver (for joints).
/// BAUMGARTE_JOINTS : Faster but can be innacurate in some situations.
/// NON_LINEAR_GAUSS_SEIDEL : Slower but more precise. This is the option used by default.
enum JointsPositionCorrectionTechnique {BAUMGARTE_JOINTS, NON_LINEAR_GAUSS_SEIDEL};

/// Position correction technique used in the contact solver (for contacts)
/// BAUMGARTE_CONTACTS : Faster but can be innacurate and can lead to unexpected bounciness
///                      in some situations (due to error correction factor being added to
///                      the bodies momentum).
/// SPLIT_IMPULSES : A bit slower but the error correction factor is not added to the
///                 bodies momentum. This is the option used by default.
enum ContactsPositionCorrectionTechnique {BAUMGARTE_CONTACTS, SPLIT_IMPULSES};

// ------------------- Constants ------------------- //

/// Smallest decimal value (negative)
const decimal DECIMAL_SMALLEST = - std::numeric_limits<decimal>::max();

/// Maximum decimal value
const decimal DECIMAL_LARGEST = std::numeric_limits<decimal>::max();

/// Machine epsilon
const decimal MACHINE_EPSILON = std::numeric_limits<decimal>::epsilon();

/// Pi constant
const decimal PI = decimal(3.14159265);

/// 2*Pi constant
const decimal PI_TIMES_2 = decimal(6.28318530);

/// Default internal constant timestep in seconds
const decimal DEFAULT_TIMESTEP = decimal(1.0 / 60.0);

/// Default friction coefficient for a rigid body
const decimal DEFAULT_FRICTION_COEFFICIENT = decimal(0.3);

/// True if the deactivation (sleeping) of inactive bodies is enabled
const bool DEACTIVATION_ENABLED = true;

/// Object margin for collision detection in meters (for the GJK-EPA Algorithm)
const decimal OBJECT_MARGIN = decimal(0.04);

/// Distance threshold for two contact points for a valid persistent contact (in meters)
const decimal PERSISTENT_CONTACT_DIST_THRESHOLD = decimal(0.03);

/// Velocity threshold for contact velocity restitution
const decimal RESTITUTION_VELOCITY_THRESHOLD = decimal(1.0);

/// Number of iterations when solving the velocity constraints of the Sequential Impulse technique
const uint DEFAULT_VELOCITY_SOLVER_NB_ITERATIONS = 15;

/// Number of iterations when solving the position constraints of the Sequential Impulse technique
const uint DEFAULT_POSITION_SOLVER_NB_ITERATIONS = 5;

}

#endif
