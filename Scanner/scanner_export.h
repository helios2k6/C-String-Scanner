#ifdef __cplusplus
#include "scanner.hpp"
using namespace scanner;
#else
typedef struct Scanner Scanner;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Constructors */
Scanner * createScanner(const char * string);

/* Destructor */
void destroyScanner(Scanner * scanner);

/* Next Functions */
int * nextInt(Scanner * scanner);
unsigned int * nextUnsignedInt(Scanner * scanner);
double * nextDouble(Scanner * scanner);
float * nextFloat(Scanner * scanner);

/* Searching */
int searchNextStringToken(Scanner * scanner, const char * string);

/* Check Functions */
int hasNextInt(Scanner * scanner);
int hasNextUnsignedInt(Scanner * scanner);
int hasNextDouble(Scanner * scanner);
int hasNextFloat(Scanner * scanner);
int hasNextStringToken(Scanner * scanner, const char * string);

/* Utility Functions */
void rewindScanner(Scanner * scanner);

/* Scanner 2.0 Functions */
int tryGetNextInt(Scanner * scanner, int * ref);
int tryGetNextUnsignedInt(Scanner * scanner, unsigned int * ref);
int tryGetNextDouble(Scanner * scanner, double * ref);
int tryGetNextFloat(Scanner * scanner, float * ref);

#ifdef __cplusplus
}
#endif