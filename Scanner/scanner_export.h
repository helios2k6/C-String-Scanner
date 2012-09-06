#include "scanner.hpp"
#ifdef __cplusplus
extern "C" {
#endif

/* Constructors */
scanner::Scanner * createScanner(const char * string);

/* Destructor */
void destroyScanner(scanner::Scanner * scanner);

/* Next Functions */
int * nextInt(scanner::Scanner * scanner);
unsigned int * nextUnsignedInt(scanner::Scanner * scanner);
double * nextDouble(scanner::Scanner * scanner);
float * nextFloat(scanner::Scanner * scanner);

/* Searching */
int searchNextStringToken(scanner::Scanner * scanner, const char * string);

/* Check Functions */
int hasNextInt(scanner::Scanner * scanner);
int hasNextUnsignedInt(scanner::Scanner * scanner);
int hasNextDouble(scanner::Scanner * scanner);
int hasNextFloat(scanner::Scanner * scanner);
int hasNextStringToken(scanner::Scanner * scanner, const char * string);

/* Utility Functions */
void rewindScanner(scanner::Scanner * scanner);

/* Scanner 2.0 Functions */
int tryGetNextInt(scanner::Scanner * scanner, int * ref);
int tryGetNextUnsignedInt(scanner::Scanner * scanner, unsigned int * ref);
int tryGetNextDouble(scanner::Scanner * scanner, double * ref);
int tryGetNextFloat(scanner::Scanner * scanner, float * ref);

#ifdef __cplusplus
}
#endif