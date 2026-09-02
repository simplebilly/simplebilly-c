#ifndef konzern_beteiligung_TEST
#define konzern_beteiligung_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define konzern_beteiligung_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/konzern_beteiligung.h"
konzern_beteiligung_t* instantiate_konzern_beteiligung(int include_optional);



konzern_beteiligung_t* instantiate_konzern_beteiligung(int include_optional) {
  konzern_beteiligung_t* konzern_beteiligung = NULL;
  if (include_optional) {
    konzern_beteiligung = konzern_beteiligung_create(
      "0",
      list_createList(),
      1,
      "0"
    );
  } else {
    konzern_beteiligung = konzern_beteiligung_create(
      "0",
      list_createList(),
      1,
      "0"
    );
  }

  return konzern_beteiligung;
}


#ifdef konzern_beteiligung_MAIN

void test_konzern_beteiligung(int include_optional) {
    konzern_beteiligung_t* konzern_beteiligung_1 = instantiate_konzern_beteiligung(include_optional);

	cJSON* jsonkonzern_beteiligung_1 = konzern_beteiligung_convertToJSON(konzern_beteiligung_1);
	printf("konzern_beteiligung :\n%s\n", cJSON_Print(jsonkonzern_beteiligung_1));
	konzern_beteiligung_t* konzern_beteiligung_2 = konzern_beteiligung_parseFromJSON(jsonkonzern_beteiligung_1);
	cJSON* jsonkonzern_beteiligung_2 = konzern_beteiligung_convertToJSON(konzern_beteiligung_2);
	printf("repeating konzern_beteiligung:\n%s\n", cJSON_Print(jsonkonzern_beteiligung_2));
}

int main() {
  test_konzern_beteiligung(1);
  test_konzern_beteiligung(0);

  printf("Hello world \n");
  return 0;
}

#endif // konzern_beteiligung_MAIN
#endif // konzern_beteiligung_TEST
