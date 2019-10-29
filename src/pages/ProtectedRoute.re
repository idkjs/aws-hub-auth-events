let useProtectedRoute = () => {
  let (authenticated, setAuthenticated) = React.useState(() => false);

  let checkAuthState = () => {
    Auth.currentAuthenticatedUser
    |> Js.Promise.then_(_data => {
         //  Js.log(data);
         setAuthenticated(_ => true);
         Js.Promise.resolve(Belt.Result.Ok(_data));
       })
    |> Js.Promise.catch(error => {
         Js.log2("error", error);
         setAuthenticated(_ => false);
         ReasonReactRouter.push("/profile");
         Js.Promise.resolve(Belt.Result.Error(error));
       })
    |> ignore;
  };
  React.useEffect1(
    () => {
      checkAuthState();
      None;
    },
    [||],
  );

  authenticated;
};
