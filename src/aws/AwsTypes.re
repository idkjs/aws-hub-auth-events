type authState =
  [@bs.string] [
    | `signIn
    | `signUp
    | `confirmSignIn
    | `confirmSignUp
    | `forgotPassword
    | `requireNewPassword
    | `verifyContact
    | `signedIn
    | `loading
  ];
  
type serializableError = {
  message: string,
  name: string,
  stack: option(string),
  code: option(string),
};

let toSerializableError =
    (error, errorCode: option(string)): serializableError => {
  message: error.message,
  name: error.name,
  stack: error.stack,
  code: errorCode,
};