module Auth = {
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
  external signOut: unit => Js.Promise.t(unit) = "signOut";
  // external signOut: unit => AsyncResult.t('a) = "signOut";
};
type attributes = {
  email: string,
  phone_number: option(string),
};
type userInfo = {
  username: string,
  attributes,
  // attributes: Js.Json.t,
};

[@react.component]
let make = () => {
  let (user, setUser) = React.useState(() => None);
  let handleUserInfo = data => {
    let userInfo = {username: data##username, attributes: data##attributes};
    setUser(_ => Some(userInfo));
    Js.log(data);
    Js.log2("userInfo: ", userInfo);
    Js.Promise.resolve(Belt.Result.Ok(data));
  };
  let checkUser = () => {
    let user =
      switch (Auth.currentAuthenticatedUser()) {
      | Ok(data) => (data => handleUserInfo(data) |> ignore)
      | Error((message, stack)) =>
        Js.log4("message: ", message, "stack: ", stack);
        let err = Belt.Option.mapWithDefault(stack, "", s => s);
        Js.log4("message: ", message, "error: ", err);
        (message, err) |> Obj.magic;
      };
    Js.log2("userInfo: ", user);
  };
  let checkUser2 = () => {
    Auth.currentUserPoolUser
    |> Js.Promise.then_(data => {
         let userInfo = {
           username: data##username,
           attributes: data##attributes,
         };
         setUser(_ => Some(userInfo));
         Js.log(data);
         Js.log2("userInfo: ", userInfo);
         Js.Promise.resolve(Belt.Result.Ok(data));
       })
    |> Js.Promise.catch(error => {
         Js.log2("error", error);
         Js.Promise.resolve(Belt.Result.Error(error));
       })
    |> ignore;
  };

  let signOut = () => {
    Auth.signOut()
    |> Js.Promise.then_(data => {
         Js.log2("signed Out: ", data);
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(error => {
         Js.log2("error", error);
         Js.Promise.resolve();
       })
    |> ignore;
  };
  open Hub;
  let logger = str => Js.log(str);

  let listener = payload => {
    // let payload = fromJs(payloadJs);
    Js.log2("listener_payload", payload);
    switch (payload.event) {
    | "signIn" => logger("user signed in") //[ERROR] My-Logger - user signed in
    | "signUp" => logger("user signed up") |> ignore

    | "signOut" => logger("user signed out") |> ignore

    | "signIn_failure" => logger("user sign in failed") |> ignore

    | "configured" => logger("the Auth module is configured") |> ignore
    | _ => logger("unknown error") |> ignore
    };
  };
  React.useEffect(() => {
    checkUser();
    Hub.listen("auth", listener);
    // Hub.listen("auth", data => {
    //   let payload = data##payload;
    //   if (payload##event === "signOut") {
    //     setUser(_ => None);
    //   };
    // });
    None;
  });
  // [||],
  // let formType: FormTypes.formType = SignIn;
  let renderProfile =
    switch (user) {
    | Some(user) =>
      <Container>
        <h1> "Profile"->React.string </h1>
        <h2> {"Username: " ++ user.username |> React.string} </h2>
        <h3> {"Email: " ++ user.attributes.email |> React.string} </h3>
        // <h4>{"Phone: " ++ user.phone_number|>React.string}</h4>
        <button onClick={_ => signOut()}>
          {"Sign Out" |> React.string}
        </button>
      </Container>
    | None =>
      <Container>
        <h1> "Profile"->React.string </h1>
        <h2> {"No Profile Available: " |> React.string} </h2>
      </Container>
    };
  // <h1> "Profile"->React.string </h1>;
  renderProfile;
};