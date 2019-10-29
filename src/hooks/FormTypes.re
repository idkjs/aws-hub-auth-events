/*
 This file hold the types we are using in our UseForm.re form hook and in the the Form pages themselves.
 `formState` defines the input state for our input fields in the forms.
 `formRules` defines state for our form validation rules
  */
type formState = {
  username: string,
  email: string,
  password: string,
  confirmationCode: string,
};
/* We will have a fixed number of rules, and we will have to map over all of them. Arrays are a good fit because they have a fixed size. We could use a List, which is an immutable singly-linked list under the hood. But finding an element is O(n) for both Lists and Arrays, and Arrays are a better fit for sets of items of known size.
   The Ocaml [website](https://ocaml.org/learn/tutorials/comparison_of_standard_containers.html) offers a concise overview of the different standard containers.
   */
type formRule = {
  id: int,
  field: string,
  message: string,
  valid: bool,
};

type formRules = array(formRule);

type formType =
  | SignIn
  | SignUp
  | ConfirmSignUp
  | ForgotPassword
  | ForgotPasswordSubmit;

let formTypeToString =
  fun
  | SignIn => "Sign In"
  | SignUp => "Sign Up"
  | ConfirmSignUp => "Confirm Sign Up"
  | ForgotPassword => "Forgot Password"
  | ForgotPasswordSubmit => "forgotPasswordSubmit";

type attributes = {
  sub: string,
  email_verified: bool,
  email: string,
  phone_number:Js.Nullable.t(string),
};
type userInfo = {
  username: string,
  attributes,
};
let fromJsAttrs = attributes => {
  sub: attributes##sub,
  email_verified: attributes##email_verified,
  email: attributes##email,
  phone_number: Js.Nullable.return(attributes##phone_number),
};
let fromJs = data => {
  username: data##username,
  attributes: fromJsAttrs(data##attributes),
};
/* /* "pool": {
     "userPoolId": "eu-west-1_ozeTBMvBW",
     "clientId": "a4k3ku8ba0e71le282fckp0bt",
     "client": {
       "endpoint": "https://cognito-idp.eu-west-1.amazonaws.com/",
       "userAgent": "aws-amplify/0.1.x js"
     },
     "advancedSecurityDataCollectionFlag": true,
     "storage": {
     }
   } */
// type client = {
//   endpoint: string,
//   userAgent: string,
// };

// type pool = {
//   userPoolId: string,
//   clientId: string,
//   client,
//   advancedSecurityDataCollectionFlag: bool,
// };
[@bs.deriving abstract]
type attributesJs = {
  sub: string,
  email_verified: bool,
  email: string,
};
type attributes = {
  sub: string,
  email_verified: bool,
  email: string,
};

[@bs.deriving abstract]
type signInResponseJs = {
  username: string,
  attributes,
};

type signInResponse = {
  username: string,
  attributes,
}; */