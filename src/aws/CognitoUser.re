[@bs.deriving abstract]
type client = {
  endpoint: string,
  userAgent: string,
};
[@bs.deriving abstract]
type storage = {key: string};
[@bs.deriving abstract]
type pool = {
  userPoolId: string,
  clientId: string,
  client,
  advancedSecurityDataCollectionFlag: bool,
  storage,
};
type id = string;
[@bs.deriving abstract]
type payload = {
  sub: string,
  aud: string,
  email_verified: bool,
  event_id: string,
  token_use: id,
  /** UNIX time */
  auth_time: int,
  iss: string,
  //  cognito_username: string,
  cognito_username: string,
  /** UNIX time */
  exp: int,
  /** UNIX time */
  iat: int,
  email: string,
};
[@bs.deriving abstract]
type refreshToken = {token: string};
[@bs.deriving abstract]
type idToken = {
  jwtToken: string,
  payload,
};
[@bs.deriving abstract]
type accessTokenpayload = {
  sub: string,
  event_id: string,
  token_use: string,
  scope: string,
  /** UNIX time */
  auth_time: int,
  iss: string,
  /** UNIX time */
  exp: int,
  /** UNIX time */
  iat: int,
  jti: string,
  client_id: string,
  username: string,
};
[@bs.deriving abstract]
type accessToken = {
  jwtToken: string,
  payload: accessTokenpayload,
};
[@bs.deriving abstract]
type signInUserSession = {
  idToken,
  refreshToken,
  accessToken,
  clockDrift: int,
  authenticationFlowType: string,
};
[@bs.deriving abstract]
type attributes = {
  sub: string,
  email_verified: bool,
  email: string,
};
/**
   * `Auth.currentUserPoolUser` return value
   * (Throws Error if no login)
   * @see amazon-cognito-identity-js/src/CognitoUser.js
   */

[@bs.deriving abstract]
type userJsDecoder = {
  username: string,
  pool,
  [@bs.as "Session"]
  session: Js.Nullable.t(Js.t({.})),
  client,
  signInUserSession,
  storage,
  keyPrefix: string,
  userDataKey: string,
  attributes,
  preferredMFA: string,
};
type userResponse = {
  username: string,
  pool,
  session:Js.Nullable.t(Js.t({.})),
  client,
  signInUserSession,
  storage,
  keyPrefix: string,
  userDataKey: string,
  attributes,
  preferredMFA: string,
};

let userResponsefromJs: userJsDecoder => userResponse =
  data => {
    username: data->usernameGet,
    pool: data->poolGet,
    session: data->sessionGet,
    client: data->clientGet,
    signInUserSession: data->signInUserSessionGet,
    storage: data->storageGet,
    keyPrefix: data->keyPrefixGet,
    userDataKey: data->userDataKeyGet,
    attributes: data->attributesGet,
    preferredMFA: data->preferredMFAGet,
  };
