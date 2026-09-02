#ifndef qr_code_response_TEST
#define qr_code_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define qr_code_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/qr_code_response.h"
qr_code_response_t* instantiate_qr_code_response(int include_optional);



qr_code_response_t* instantiate_qr_code_response(int include_optional) {
  qr_code_response_t* qr_code_response = NULL;
  if (include_optional) {
    qr_code_response = qr_code_response_create(
      "0",
      "0"
    );
  } else {
    qr_code_response = qr_code_response_create(
      "0",
      "0"
    );
  }

  return qr_code_response;
}


#ifdef qr_code_response_MAIN

void test_qr_code_response(int include_optional) {
    qr_code_response_t* qr_code_response_1 = instantiate_qr_code_response(include_optional);

	cJSON* jsonqr_code_response_1 = qr_code_response_convertToJSON(qr_code_response_1);
	printf("qr_code_response :\n%s\n", cJSON_Print(jsonqr_code_response_1));
	qr_code_response_t* qr_code_response_2 = qr_code_response_parseFromJSON(jsonqr_code_response_1);
	cJSON* jsonqr_code_response_2 = qr_code_response_convertToJSON(qr_code_response_2);
	printf("repeating qr_code_response:\n%s\n", cJSON_Print(jsonqr_code_response_2));
}

int main() {
  test_qr_code_response(1);
  test_qr_code_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // qr_code_response_MAIN
#endif // qr_code_response_TEST
