#ifndef package_TEST
#define package_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define package_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/package.h"
package_t* instantiate_package(int include_optional);



package_t* instantiate_package(int include_optional) {
  package_t* package = NULL;
  if (include_optional) {
    package = package_create(
      "0",
      1.337,
      1.337,
      "0",
      1.337,
      1.337
    );
  } else {
    package = package_create(
      "0",
      1.337,
      1.337,
      "0",
      1.337,
      1.337
    );
  }

  return package;
}


#ifdef package_MAIN

void test_package(int include_optional) {
    package_t* package_1 = instantiate_package(include_optional);

	cJSON* jsonpackage_1 = package_convertToJSON(package_1);
	printf("package :\n%s\n", cJSON_Print(jsonpackage_1));
	package_t* package_2 = package_parseFromJSON(jsonpackage_1);
	cJSON* jsonpackage_2 = package_convertToJSON(package_2);
	printf("repeating package:\n%s\n", cJSON_Print(jsonpackage_2));
}

int main() {
  test_package(1);
  test_package(0);

  printf("Hello world \n");
  return 0;
}

#endif // package_MAIN
#endif // package_TEST
