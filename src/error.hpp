//
// Define methods for performing error checking,
// both by providing code contracts, and by defining
// methods for pre- and post condition checking.
//

#pragma once

// outcomment when application reliability has been
// proven sufficiently
#define __ERRORS_ENABLED__



/* condition checking module */
#ifdef __ERRORS_ENABLED__

#include <iostream>
#include <assert>


/* pre- and post-condition checking */
#define PRECONDITION(testBool) ( !(testBool) ?              \
    ( fprintf(stderr, "%s:%i: Precondition '%s' failed.\n", \
              __FILE__, __LINE__, #testBool),               \
      exit(1) ) : void(sizeof(0)) )

#define POSTCONDITION(testBool) ( !(testBool) ?             \
    ( fprintf(stderr, "%s:%i: Postcondition '%s' failed.\n", \
              __FILE__, __LINE__, #testBool),               \
      exit(1) ) : void(sizeof(0)) )

#else // ! __ERRORS_ENABLED__


#define PRECONDITION(testBool) ( void(sizeof(0)) )
#define POSTCONDITION(testBool) ( void(sizeof(0)) )


#endif // __ERRORS_ENABLED__
