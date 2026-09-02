#ifndef ai_worker_config_TEST
#define ai_worker_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ai_worker_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ai_worker_config.h"
ai_worker_config_t* instantiate_ai_worker_config(int include_optional);



ai_worker_config_t* instantiate_ai_worker_config(int include_optional) {
  ai_worker_config_t* ai_worker_config = NULL;
  if (include_optional) {
    ai_worker_config = ai_worker_config_create(
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    ai_worker_config = ai_worker_config_create(
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      1,
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "2013-10-20T19:20:30+01:00"
    );
  }

  return ai_worker_config;
}


#ifdef ai_worker_config_MAIN

void test_ai_worker_config(int include_optional) {
    ai_worker_config_t* ai_worker_config_1 = instantiate_ai_worker_config(include_optional);

	cJSON* jsonai_worker_config_1 = ai_worker_config_convertToJSON(ai_worker_config_1);
	printf("ai_worker_config :\n%s\n", cJSON_Print(jsonai_worker_config_1));
	ai_worker_config_t* ai_worker_config_2 = ai_worker_config_parseFromJSON(jsonai_worker_config_1);
	cJSON* jsonai_worker_config_2 = ai_worker_config_convertToJSON(ai_worker_config_2);
	printf("repeating ai_worker_config:\n%s\n", cJSON_Print(jsonai_worker_config_2));
}

int main() {
  test_ai_worker_config(1);
  test_ai_worker_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // ai_worker_config_MAIN
#endif // ai_worker_config_TEST
