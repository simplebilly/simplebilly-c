#ifndef webhook_direction_TEST
#define webhook_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define webhook_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/webhook_direction.h"
webhook_direction_t* instantiate_webhook_direction(int include_optional);



webhook_direction_t* instantiate_webhook_direction(int include_optional) {
  webhook_direction_t* webhook_direction = NULL;
  if (include_optional) {
    webhook_direction = webhook_direction_create(
    );
  } else {
    webhook_direction = webhook_direction_create(
    );
  }

  return webhook_direction;
}


#ifdef webhook_direction_MAIN

void test_webhook_direction(int include_optional) {
    webhook_direction_t* webhook_direction_1 = instantiate_webhook_direction(include_optional);

	cJSON* jsonwebhook_direction_1 = webhook_direction_convertToJSON(webhook_direction_1);
	printf("webhook_direction :\n%s\n", cJSON_Print(jsonwebhook_direction_1));
	webhook_direction_t* webhook_direction_2 = webhook_direction_parseFromJSON(jsonwebhook_direction_1);
	cJSON* jsonwebhook_direction_2 = webhook_direction_convertToJSON(webhook_direction_2);
	printf("repeating webhook_direction:\n%s\n", cJSON_Print(jsonwebhook_direction_2));
}

int main() {
  test_webhook_direction(1);
  test_webhook_direction(0);

  printf("Hello world \n");
  return 0;
}

#endif // webhook_direction_MAIN
#endif // webhook_direction_TEST
