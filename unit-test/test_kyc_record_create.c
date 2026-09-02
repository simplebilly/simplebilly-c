#ifndef kyc_record_create_TEST
#define kyc_record_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define kyc_record_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/kyc_record_create.h"
kyc_record_create_t* instantiate_kyc_record_create(int include_optional);



kyc_record_create_t* instantiate_kyc_record_create(int include_optional) {
  kyc_record_create_t* kyc_record_create = NULL;
  if (include_optional) {
    kyc_record_create = kyc_record_create_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      "0"
    );
  } else {
    kyc_record_create = kyc_record_create_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      "0"
    );
  }

  return kyc_record_create;
}


#ifdef kyc_record_create_MAIN

void test_kyc_record_create(int include_optional) {
    kyc_record_create_t* kyc_record_create_1 = instantiate_kyc_record_create(include_optional);

	cJSON* jsonkyc_record_create_1 = kyc_record_create_convertToJSON(kyc_record_create_1);
	printf("kyc_record_create :\n%s\n", cJSON_Print(jsonkyc_record_create_1));
	kyc_record_create_t* kyc_record_create_2 = kyc_record_create_parseFromJSON(jsonkyc_record_create_1);
	cJSON* jsonkyc_record_create_2 = kyc_record_create_convertToJSON(kyc_record_create_2);
	printf("repeating kyc_record_create:\n%s\n", cJSON_Print(jsonkyc_record_create_2));
}

int main() {
  test_kyc_record_create(1);
  test_kyc_record_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // kyc_record_create_MAIN
#endif // kyc_record_create_TEST
