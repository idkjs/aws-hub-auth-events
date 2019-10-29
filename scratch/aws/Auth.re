[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external currentAuthenticatedUser: unit => AsyncResult.t('a) =
  "currentAuthenticatedUser";

// let currentAuthenticatedUser =
//   currentAuthenticatedUser()
//   |> Js.Promise.then_(res => Js.Promise.resolve(res));

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external currentUserPoolUser: unit => Js.Promise.t('a) =
  "currentUserPoolUser";
let currentUserPoolUser =
  currentUserPoolUser() |> Js.Promise.then_(res => Js.Promise.resolve(res));
[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signOut: AsyncResult.t('a) = "signOut";
// external signOut: Js.Promise.t(unit) = "signOut";

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signIn: Js.Json.t => Js.Promise.t(Js.Json.t) = "signIn";

let signIn = (~username, ~password) => {
  let signInValues: Js.Dict.t(Js.Json.t) =
    Js.Dict.fromList([
      ("username", Js.Json.string(username)),
      ("password", Js.Json.string(password)),
    ]);
  let json = Js.Json.object_(signInValues);
  Js.Promise.(
    signIn(json)
    |> then_(result => {
         Js.log2("result", result);
         resolve();
       })
    |> catch(err => {
         Js.log2("Error", err);
         resolve();
       })
  );
};
// SignUp

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signUp: Js.Json.t => Js.Promise.t(Js.Json.t) = "signUp";

let signUp = (~username: string, ~password: string, ~email: string) => {
  // ~phone_number: string,

  let attributes: Js.Dict.t(Js.Json.t) =
    Js.Dict.fromList([
      ("email", Js.Json.string(email)),
      // ("phone_number", Js.Json.string(phone_number)),
    ]);
  let authValues =
    Js.Dict.fromList([
      ("username", Js.Json.string(username)),
      ("password", Js.Json.string(password)),
      ("attributes", Js.Json.object_(attributes)),
    ]);
  Js.log("Running SIGNUP");
  Js.log2("authValues", authValues);
  let json = Js.Json.object_(authValues);
  Js.log2("SIGNUP_JSON", json);
  Js.Promise.(
    signUp(json)
    |> then_(result => {
         Js.log2("result", result);
         resolve();
       })
    |> catch(err => {
         Js.log2("Error", err);
         resolve();
       })
  );
};