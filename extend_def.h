//
// Created by Owner on 7/10/2024.
//

#ifndef EXTEND_DEF_H
	#define EXTEND_DEF_H

	/*
	* infinite loop replacement for while (true). Loop must
	* be broken with a break call inside the loop, i.e. if (condition) break;
	*/
	#ifndef loop
		#define loop while (1)

		/*
		 * break the loop if condition is true
		 */

		#define breakif(condition) if (condition) break

	#endif /* loop */

	#ifndef TODO
		#define TODO fprintf(stderr, "WIP code reached.\n") && 0

		#include <stdio.h>

	#endif /* TODO */


#endif /* EXTEND_DEF_H */
