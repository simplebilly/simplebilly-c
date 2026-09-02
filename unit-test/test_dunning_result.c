#ifndef dunning_result_TEST
#define dunning_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dunning_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dunning_result.h"
dunning_result_t* instantiate_dunning_result(int include_optional);



dunning_result_t* instantiate_dunning_result(int include_optional) {
  dunning_result_t* dunning_result = NULL;
  if (include_optional) {
    dunning_result = dunning_result_create(
      0,
      "0"
    );
  } else {
    dunning_result = dunning_result_create(
      0,
      "0"
    );
  }

  return dunning_result;
}


#ifdef dunning_result_MAIN

void test_dunning_result(int include_optional) {
    dunning_result_t* dunning_result_1 = instantiate_dunning_result(include_optional);

	cJSON* jsondunning_result_1 = dunning_result_convertToJSON(dunning_result_1);
	printf("dunning_result :\n%s\n", cJSON_Print(jsondunning_result_1));
	dunning_result_t* dunning_result_2 = dunning_result_parseFromJSON(jsondunning_result_1);
	cJSON* jsondunning_result_2 = dunning_result_convertToJSON(dunning_result_2);
	printf("repeating dunning_result:\n%s\n", cJSON_Print(jsondunning_result_2));
}

int main() {
  test_dunning_result(1);
  test_dunning_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // dunning_result_MAIN
#endif // dunning_result_TEST
