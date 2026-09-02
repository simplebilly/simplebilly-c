#ifndef oss_dependency_TEST
#define oss_dependency_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define oss_dependency_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/oss_dependency.h"
oss_dependency_t* instantiate_oss_dependency(int include_optional);



oss_dependency_t* instantiate_oss_dependency(int include_optional) {
  oss_dependency_t* oss_dependency = NULL;
  if (include_optional) {
    oss_dependency = oss_dependency_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    oss_dependency = oss_dependency_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return oss_dependency;
}


#ifdef oss_dependency_MAIN

void test_oss_dependency(int include_optional) {
    oss_dependency_t* oss_dependency_1 = instantiate_oss_dependency(include_optional);

	cJSON* jsonoss_dependency_1 = oss_dependency_convertToJSON(oss_dependency_1);
	printf("oss_dependency :\n%s\n", cJSON_Print(jsonoss_dependency_1));
	oss_dependency_t* oss_dependency_2 = oss_dependency_parseFromJSON(jsonoss_dependency_1);
	cJSON* jsonoss_dependency_2 = oss_dependency_convertToJSON(oss_dependency_2);
	printf("repeating oss_dependency:\n%s\n", cJSON_Print(jsonoss_dependency_2));
}

int main() {
  test_oss_dependency(1);
  test_oss_dependency(0);

  printf("Hello world \n");
  return 0;
}

#endif // oss_dependency_MAIN
#endif // oss_dependency_TEST
