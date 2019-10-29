type serializableError = {
  message: string,
  name: string,
  stack: option(string),
  code: option(string),
};
// type errorPromise = Js.Promise
external castToSerializableError: 'a => serializableError = "%identity";
let toSerializableError =
    (error, errorCode: option(string)): serializableError => {
  message: error.message,
  name: error.name,
  stack: error.stack,
  code: errorCode,
};
[@react.component]
let make = () => {
  let (user, setUser) = React.useState(() => None);

  // let formType: FormTypes.formType = SignIn;
  //  let (state, formRules, handleChange, handleSubmit, updateFormType) =
  //    UseForm.useForm(~formType: FormTypes.formType);
  // let checkUser = () => {
  //   Auth.currentAuthenticatedUser
  //   |> Js.Promise.then_(data => {
  //        let userInfo = data->FormTypes.fromJs;
  //        Js.log2("userInfo: ", userInfo);
  //        setUser(_ => Some(userInfo));
  //        Js.Promise.resolve(Belt.Result.Ok(userInfo));
  //      })
  //   |> Js.Promise.catch(error => {
  //        Js.log2("error", error);
  //        Js.Promise.resolve(Belt.Result.Error(error));
  //      })
  //   |> ignore;
  // };

  let checkUser = () => {
    Auth.currentUserPoolUser(~userPoolId="Amplify.Config.identityPoolId")
    // Auth.currentUserPoolUser(~userPoolId=Amplify.Config.userPoolId)
    |> Js.Promise.then_(data => {
         let userInfo = data->FormTypes.fromJs;
         Js.log2("userInfo: ", userInfo);
         setUser(_ => Some(userInfo));
         Js.Promise.resolve(Belt.Result.Ok(userInfo));
       })
    |> Js.Promise.catch(error => {
          Js.log2("error", error);
          let serializableError= error->castToSerializableError;
         Js.log2(
           "toSerializableError",
           serializableError->toSerializableError,
         );
         let errorS = serializableError->toSerializableError;
         Js.log2(
           "toSerializableError:errorS",
           errorS,
         );
         Js.Promise.resolve(Belt.Result.Error(error));
       })
    |> ignore;
  };

  let logger = str => Js.log2("logger", str);

  let listener: Hub.cb =
    payload => {
      Js.log2("listener_payload", payload);
      switch (payload.event) {
      // | `signIn => logger(payload) //[ERROR] My-Logger - user signed in
      // | `signUp => logger("user signed up") |> ignore

      | `signOut => setUser(_ => None)

      // | `signIn_failure => logger("user sign in failed") |> ignore

      // | `configured => logger(payload) |> ignore
      | _ => logger(payload) |> ignore
      };
    };
  React.useEffect1(
    () => {
      checkUser();
      Hub.listen(`auth, listener);
      Some(() => Hub.remove(`auth, listener));
    },
    [||],
  );

  let signOut = () => {
    Auth.signOut()
    |> Js.Promise.then_(_ => {
         Js.log("signed Out");
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(error => {
         Js.log2("error", error);
         Js.Promise.resolve();
       })
    |> ignore;
  };
  let formType: FormTypes.formType = SignIn;
  let renderProfile = () =>
    switch (user) {
    | Some(user) =>
      <Container>
        <h1> "Profile"->React.string </h1>
        <h2> {"Username: " ++ user.username |> React.string} </h2>
        <h3> {"Email: " ++ user.attributes.email |> React.string} </h3>
        {switch (Js.Nullable.toOption(user.attributes.phone_number)) {
         | Some(number) => <h4> {"Phone: " ++ number |> React.string} </h4>
         | None => React.null
         }}
        <button onClick={_ => signOut()}>
          {"Sign Out" |> React.string}
        </button>
      </Container>
    | None => <Form formType setUser />
    };
  renderProfile();
};