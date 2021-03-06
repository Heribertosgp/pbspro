/*
 * Copyright (C) 1994-2017 Altair Engineering, Inc.
 * For more information, contact Altair at www.altair.com.
 *
 * This file is part of the PBS Professional ("PBS Pro") software.
 *
 * Open Source License Information:
 *
 * PBS Pro is free software. You can redistribute it and/or modify it under the
 * terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * PBS Pro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Commercial License Information:
 *
 * The PBS Pro software is licensed under the terms of the GNU Affero General
 * Public License agreement ("AGPL"), except where a separate commercial license
 * agreement for PBS Pro version 14 or later has been executed in writing with Altair.
 *
 * Altair’s dual-license business model allows companies, individuals, and
 * organizations to create proprietary derivative works of PBS Pro and distribute
 * them - whether embedded or bundled with other software - under a commercial
 * license agreement.
 *
 * Use of Altair’s trademarks, including but not limited to "PBS™",
 * "PBS Professional®", and "PBS Pro™" and Altair’s logos is subject to Altair's
 * trademark licensing policies.
 *
 */

#ifndef _RANGE_H
#define _RANGE_H

#include "data_types.h"

/**
 * Control whether to consider stepping or not
 */
enum range_step_type {
	DISABLE_SUBRANGE_STEPPING,
	ENABLE_SUBRANGE_STEPPING
};

/*
 *	new_range - allocate and initialize a range structure
 */
#ifdef NAS /* localmod 005 */
range *new_range(void);
#else
range *new_range();
#endif /* localmod 005 */

/*
 *	free_range_list - free a list of ranges
 */
void free_range_list(range *r);

/*
 *	free_range - free a range structure
 */
void free_range(range *r);

/*
 *	dup_range_list - duplicate a range list
 */
range *dup_range_list(range *old_r);

/*
 *	dup_range - duplicate a range structure
 */
range *dup_range(range *old_r);

/*
 *	range_parse - parse string of ranges delimited by comma
 */
range *range_parse(char *str);

/*
 *
 *	range_next_value - get the next value in a range
 *			   if a current value is given, return the next
 *			   if no current value is given, return the first
 *
 */
int range_next_value(range *r, int cur_value);

/*
 *	range_contains - find if a range contains a value
 */
int range_contains(range *r, int val);

/*
 *	range_contains_single - is a value contained in a single range
 *				  structure
 */
int range_contains_single(range *r, int val);

/*
 *	range_remove_value - remove a value from a range list
 *	NOTE: only supports removing values from either the start or end
 *	      of a range, not in the middle
 */
int range_remove_value(range **r, int val);

/*
 *	range_add_value - add a value to a range list by adding it to the end
 *			  of the list
 */
int range_add_value(range *r, int val, enum range_step_type type);

/*
 *	range_intersection - create an intersection between two ranges
 */
range *range_intersection(range *r1, range *r2);

int parse_subjob_index(char *pc, char **ep, int *px, int *py, int *pz, int *pct);

/*
 * Return a string representation of a range structure
 */
char *range_to_str(range *r);


#endif /* _RANGE_H */
