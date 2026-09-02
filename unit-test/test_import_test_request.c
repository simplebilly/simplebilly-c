#ifndef import_test_request_TEST
#define import_test_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define import_test_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/import_test_request.h"
import_test_request_t* instantiate_import_test_request(int include_optional);



import_test_request_t* instantiate_import_test_request(int include_optional) {
  import_test_request_t* import_test_request = NULL;
  if (include_optional) {
    import_test_request = import_test_request_create(
      "0",
      "0"
    );
  } else {
    import_test_request = import_test_request_create(
      "0",
      "0"
    );
  }

  return import_test_request;
}


#ifdef import_test_request_MAIN

void test_import_test_request(int include_optional) {
    import_test_request_t* import_test_request_1 = instantiate_import_test_request(include_optional);

	cJSON* jsonimport_test_request_1 = import_test_request_convertToJSON(import_test_request_1);
	printf("import_test_request :\n%s\n", cJSON_Print(jsonimport_test_request_1));
	import_test_request_t* import_test_request_2 = import_test_request_parseFromJSON(jsonimport_test_request_1);
	cJSON* jsonimport_test_request_2 = import_test_request_convertToJSON(import_test_request_2);
	printf("repeating import_test_request:\n%s\n", cJSON_Print(jsonimport_test_request_2));
}

int main() {
  test_import_test_request(1);
  test_import_test_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // import_test_request_MAIN
#endif // import_test_request_TEST
