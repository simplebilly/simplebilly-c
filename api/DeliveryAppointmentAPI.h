#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/appointment_status_update.h"
#include "../model/delivery_appointment.h"
#include "../model/delivery_appointment_create.h"
#include "../model/plugin_error.h"
#include "../model/public_delivery_appointment_request.h"
#include "../model/public_delivery_appointment_response.h"
#include "../model/public_delivery_appointment_status_response.h"


delivery_appointment_t*
DeliveryAppointmentAPI_createDeliveryAppointment(apiClient_t *apiClient, delivery_appointment_create_t *delivery_appointment_create);


void
DeliveryAppointmentAPI_deleteDeliveryAppointment(apiClient_t *apiClient, char *appointment_id);


delivery_appointment_t*
DeliveryAppointmentAPI_getDeliveryAppointment(apiClient_t *apiClient, char *appointment_id);


// Supplier/carrier checks appointment status (public, no auth). The appointment is only revealed when email AND token match.
//
public_delivery_appointment_status_response_t*
DeliveryAppointmentAPI_getPublicDeliveryAppointmentStatus(apiClient_t *apiClient, char *appointmentId, char *email, char *token);


list_t*
DeliveryAppointmentAPI_listDeliveryAppointments(apiClient_t *apiClient, int *page, int *page_size, char *status, char *warehouse_id, char from, char to);


// Supplier/carrier requests an inbound delivery slot (public, no auth). The tenant is derived from the warehouse found by `code` — never from the request.
//
public_delivery_appointment_response_t*
DeliveryAppointmentAPI_requestPublicDeliveryAppointment(apiClient_t *apiClient, public_delivery_appointment_request_t *public_delivery_appointment_request);


delivery_appointment_t*
DeliveryAppointmentAPI_updateDeliveryAppointment(apiClient_t *apiClient, char *appointment_id, body);


delivery_appointment_t*
DeliveryAppointmentAPI_updateDeliveryAppointmentStatus(apiClient_t *apiClient, char *appointment_id, appointment_status_update_t *appointment_status_update);


