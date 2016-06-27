/* > sgp4.h
 *
 *
 *	(c) Paul Crawford & Andrew Brooks 1994-2010
 *	University of Dundee
 *	psc (at) sat.dundee.ac.uk
 *	arb (at) sat.dundee.ac.uk
 *
 *	Released under the terms of the GNU LGPL V3
 *	http://www.gnu.org/licenses/lgpl-3.0.html
 *	
 *	This software is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *
 * 2.00 psc Sun May 28 1995 - Modifed for non-Dundee use.
 *
 */

#ifndef _SGP4_H
#define _SGP4_H

#include "adcs_frame.h"
#include "adcs_time.h"

#define TLE_SIZE 145
#define TLE_LINE2_OFFSET 69+1

typedef struct orbit_s {
	/* Add the epoch time if required. */
	int ep_year; /* Year of epoch, e.g. 94 for 1994, 100 for 2000AD */
	double ep_day; /* Day of epoch from 00:00 Jan 1st ( = 1.0 ) */
	double rev; /* Mean motion, revolutions per day */
	double bstar; /* Drag term .*/
	double eqinc; /* Equatorial inclination, radians */
	double ecc; /* Eccentricity */
	double mnan; /* Mean anomaly at epoch from elements, radians */
	double argp; /* Argument of perigee, radians */
	double ascn; /* Right ascension (ascending node), radians */
	double smjaxs; /* Semi-major axis, km */
	long norb; /* Orbit number, for elements */
	int satno; /* Satellite number. */
} orbit_t;

typedef enum {
	TLE_NORMAL = 0, TLE_ERROR
} tle_status;

extern orbit_t upsat_tle;
extern uint8_t tle_string[TLE_SIZE];
extern xyz_t p_eci, v_eci;

int satpos_xyz(double jd, xyz_t *pos, xyz_t *vel);

orbit_t read_tle(uint8_t *tle);
orbit_t calculate_tle(xyz_t position, xyz_t velocity, _tle_epoch updt_tle_epoch);
tle_status update_tle(orbit_t *tle, orbit_t new_tle);

#endif
