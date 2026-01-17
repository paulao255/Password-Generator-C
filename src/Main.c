/* Include guard: */
#ifndef PG_C
#define PG_C

/* Importations: */
#include "C-Utils/cutils.h"
#include <stdio.h>
#include <stdlib.h>


/* PG-C version variables: */
#define PG_C_FULL_VERSION       20260117 /* PG-C full version variable (2026/01/17). */
#define PG_C_MAJOR_VERSION      2026     /* PG-C major version variable (2026).      */
#define PG_C_MINOR_VERSION      01       /* PG-C minor version variable (01).        */
#define PG_C_PATCH_VERSION      17       /* PG-C patch version variable (17).        */

/* Defines: */
#define MINIMUM_PASSWORD_LENGHT 3        /* Minimum password lenght variable.        */
#define MAXIMUM_PASSWORD_LENGHT 20       /* Maximum password lenght variable.        */

/* Main code: */
int main(void)
{
	/* Local variables: */
	int number = 0;                                                                                                           /* Ammount of characters in the password variable.                    */
	int times = 0;                                                                                                            /* Times to generate random characters for the password.              */
	char snumber[8192] = "";                                                                                                  /* String number variable.                                            */
	char characters[95] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-=_+!@#$%^&*()[]{};:'\"\\|/?,.<>`~"; /* Variable to store all the possible characters to be in a password. */
	char password[21] = "";                                                                                                   /* Variable to store the generated password.                          */

	/* Start seed: */
	srand((unsigned) time(NULL));

	/* Main loop: */
	while(number < MINIMUM_PASSWORD_LENGHT || number > MAXIMUM_PASSWORD_LENGHT)
	{
		clear_terminal();
		printf("Type the ammount of digits that you want to have in the password (Minimum: %d; Maximum: %d): ", MINIMUM_PASSWORD_LENGHT, MAXIMUM_PASSWORD_LENGHT);
		scanf("%8191s", snumber);
		number = atoi(snumber);
	}

	for(times = 0; times < number; ++times)
	{
		password[times] = characters[rand() % 95];
	}

	printf("Generated password: %s\n", password);

	return 0;
}

/* End code: */
#endif
