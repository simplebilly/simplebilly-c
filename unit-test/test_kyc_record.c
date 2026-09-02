#ifndef kyc_record_TEST
#define kyc_record_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define kyc_record_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/kyc_record.h"
kyc_record_t* instantiate_kyc_record(int include_optional);



kyc_record_t* instantiate_kyc_record(int include_optional) {
  kyc_record_t* kyc_record = NULL;
  if (include_optional) {
    kyc_record = kyc_record_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      "0"
    );
  } else {
    kyc_record = kyc_record_create(
      "0",
      "0",
      "2013-10-20",
      "0",
      "2013-10-20",
      "0"
    );
  }

  return kyc_record;
}


#ifdef kyc_record_MAIN

void test_kyc_record(int include_optional) {
    kyc_record_t* kyc_record_1 = instantiate_kyc_record(include_optional);

	cJSON* jsonkyc_record_1 = kyc_record_convertToJSON(kyc_record_1);
	printf("kyc_record :\n%s\n", cJSON_Print(jsonkyc_record_1));
	kyc_record_t* kyc_record_2 = kyc_record_parseFromJSON(jsonkyc_record_1);
	cJSON* jsonkyc_record_2 = kyc_record_convertToJSON(kyc_record_2);
	printf("repeating kyc_record:\n%s\n", cJSON_Print(jsonkyc_record_2));
}

int main() {
  test_kyc_record(1);
  test_kyc_record(0);

  printf("Hello world \n");
  return 0;
}

#endif // kyc_record_MAIN
#endif // kyc_record_TEST
