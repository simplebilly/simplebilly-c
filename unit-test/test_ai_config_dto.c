#ifndef ai_config_dto_TEST
#define ai_config_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ai_config_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ai_config_dto.h"
ai_config_dto_t* instantiate_ai_config_dto(int include_optional);



ai_config_dto_t* instantiate_ai_config_dto(int include_optional) {
  ai_config_dto_t* ai_config_dto = NULL;
  if (include_optional) {
    ai_config_dto = ai_config_dto_create(
      1,
      56,
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    ai_config_dto = ai_config_dto_create(
      1,
      56,
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return ai_config_dto;
}


#ifdef ai_config_dto_MAIN

void test_ai_config_dto(int include_optional) {
    ai_config_dto_t* ai_config_dto_1 = instantiate_ai_config_dto(include_optional);

	cJSON* jsonai_config_dto_1 = ai_config_dto_convertToJSON(ai_config_dto_1);
	printf("ai_config_dto :\n%s\n", cJSON_Print(jsonai_config_dto_1));
	ai_config_dto_t* ai_config_dto_2 = ai_config_dto_parseFromJSON(jsonai_config_dto_1);
	cJSON* jsonai_config_dto_2 = ai_config_dto_convertToJSON(ai_config_dto_2);
	printf("repeating ai_config_dto:\n%s\n", cJSON_Print(jsonai_config_dto_2));
}

int main() {
  test_ai_config_dto(1);
  test_ai_config_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // ai_config_dto_MAIN
#endif // ai_config_dto_TEST
