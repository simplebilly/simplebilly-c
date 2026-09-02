#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/accept_invite_request.h"
#include "../model/auth_response.h"
#include "../model/forgot_password_request.h"
#include "../model/login_request.h"
#include "../model/magic_link_request.h"
#include "../model/magic_link_verify_request.h"
#include "../model/register_request.h"
#include "../model/reset_password_request.h"
#include "../model/totp_enable_request.h"
#include "../model/totp_setup_response.h"
#include "../model/verify_email_request.h"


// Accept an invite: create the account (or reuse an existing one) and join the inviting tenant. The invite token proves control of the mailbox.
//
void
AuthAPI_acceptInvite(apiClient_t *apiClient, accept_invite_request_t *accept_invite_request);


// Register a new user account
//
auth_response_t*
AuthAPI_callRegister(apiClient_t *apiClient, register_request_t *register_request);


// Send a password reset email to the user
//
void
AuthAPI_forgotPassword(apiClient_t *apiClient, forgot_password_request_t *forgot_password_request);


// Authenticate a user with email + password (optional TOTP)
//
auth_response_t*
AuthAPI_login(apiClient_t *apiClient, login_request_t *login_request);


// Log out the current user (kills the assay session)
//
void
AuthAPI_logout(apiClient_t *apiClient);


// Request a magic link login (sends an email with a one-time link)
//
void
AuthAPI_magicLinkLogin(apiClient_t *apiClient, magic_link_request_t *magic_link_request);


// Verify a magic link token and log the user in
//
auth_response_t*
AuthAPI_magicLinkVerify(apiClient_t *apiClient, magic_link_verify_request_t *magic_link_verify_request);


// Reset the user's password using a reset token
//
void
AuthAPI_resetPassword(apiClient_t *apiClient, reset_password_request_t *reset_password_request);


// Enable TOTP two-factor authentication by verifying a code
//
void
AuthAPI_totpEnable(apiClient_t *apiClient, totp_enable_request_t *totp_enable_request);


// Set up TOTP two-factor authentication (generates secret + backup codes)
//
totp_setup_response_t*
AuthAPI_totpSetup(apiClient_t *apiClient);


// Verify a user's email address using a verification token
//
void
AuthAPI_verifyEmail(apiClient_t *apiClient, verify_email_request_t *verify_email_request);


