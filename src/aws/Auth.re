[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external currentAuthenticatedUser: unit => Js.Promise.t('a) =
  "currentAuthenticatedUser";
let currentAuthenticatedUser =
  currentAuthenticatedUser()
  |> Js.Promise.then_(res => Js.Promise.resolve(res));

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signOut: unit => Js.Promise.t(unit) = "signOut";

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external _signIn: (~username: string, ~password: string) => Js.Promise.t('a) =
  "signIn";
let signIn = (~username, ~password) =>
  _signIn(~username, ~password)
  |> Js.Promise.then_(res => Js.Promise.resolve(res));
[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external _signUp:
  (~username: string, ~password: string, ~attributes: 'a) => Js.Promise.t('a) =
  "signUp";
let signUp = (~username, ~password, ~attributes) =>
  _signUp(~username, ~password, ~attributes)
  |> Js.Promise.then_(res => Js.Promise.resolve(res));
[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external _confirmSignUp:
  (~username: string, ~confirmationCode: string) => Js.Promise.t('a) =
  "confirmSignUp";
let confirmSignUp = (~username, ~confirmationCode) =>
  _confirmSignUp(~username, ~confirmationCode)
  |> Js.Promise.then_(res => Js.Promise.resolve(res));
[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external _forgotPassword: (~username: string) => Js.Promise.t('a) =
  "forgotPassword";
let forgotPassword = (~username) =>
  _forgotPassword(~username)
  |> Js.Promise.then_(res => Js.Promise.resolve(res));
[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external _forgotPasswordSubmit:
  (~username: string, ~confirmationCode: string, ~password: string) =>
  Js.Promise.t('a) =
  "forgotPasswordSubmit";
let forgotPasswordSubmit = (~username, ~confirmationCode, ~password) =>
  _forgotPasswordSubmit(~username, ~confirmationCode, ~password)
  |> Js.Promise.then_(res => Js.Promise.resolve(res));

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external currentUserPoolUser: (~userPoolId: string) => Js.Promise.t('a) =
  "currentUserPoolUser";
let currentUserPoolUser = (~userPoolId: string) =>
  currentUserPoolUser(~userPoolId)
  |> Js.Promise.then_(res => Js.Promise.resolve(res)) /* }*/;
// let signIn = (~username, ~password) => {
//   let signInValues: Js.Dict.t(Js.Json.t) =
//     Js.Dict.fromList([
//       ("username", Js.Json.string(username)),
//       ("password", Js.Json.string(password)),
//     ]);
//   let json = Js.Json.object_(signInValues);
//   Js.Promise.(
//     signIn(json)
//     |> then_(result => {
//          Js.log2("result", result);
//          resolve();
//        })
//     |> catch(err => {
//          Js.log2("Error", err);
//          resolve();
//        })
//   );