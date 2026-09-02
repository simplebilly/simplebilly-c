#ifndef submit_result_dto_TEST
#define submit_result_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define submit_result_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/submit_result_dto.h"
submit_result_dto_t* instantiate_submit_result_dto(int include_optional);



submit_result_dto_t* instantiate_submit_result_dto(int include_optional) {
  submit_result_dto_t* submit_result_dto = NULL;
  if (include_optional) {
    submit_result_dto = submit_result_dto_create(
      list_createList(),
      "0",
      56,
      "0"
    );
  } else {
    submit_result_dto = submit_result_dto_create(
      list_createList(),
      "0",
      56,
      "0"
    );
  }

  return submit_result_dto;
}


#ifdef submit_result_dto_MAIN

void test_submit_result_dto(int include_optional) {
    submit_result_dto_t* submit_result_dto_1 = instantiate_submit_result_dto(include_optional);

	cJSON* jsonsubmit_result_dto_1 = submit_result_dto_convertToJSON(submit_result_dto_1);
	printf("submit_result_dto :\n%s\n", cJSON_Print(jsonsubmit_result_dto_1));
	submit_result_dto_t* submit_result_dto_2 = submit_result_dto_parseFromJSON(jsonsubmit_result_dto_1);
	cJSON* jsonsubmit_result_dto_2 = submit_result_dto_convertToJSON(submit_result_dto_2);
	printf("repeating submit_result_dto:\n%s\n", cJSON_Print(jsonsubmit_result_dto_2));
}

int main() {
  test_submit_result_dto(1);
  test_submit_result_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // submit_result_dto_MAIN
#endif // submit_result_dto_TEST
