open Hub;

let logger = str => Js.log(str);
// let error = (string) => error(logger, string);

let fromJs = payloadJs => {
  let payload = {
    event: eventGet(payloadJs),
    data: dataGet(payloadJs),
    message: messageGet(payloadJs),
  };
  payload;
};
let listener =
  payload => {
    // let payload = fromJs(payloadJs);
    Js.log2("payload", payload);
    switch (payload.event) {
    | "signIn" => logger("user signed in") //[ERROR] My-Logger - user signed in
    | "signUp" => logger("user signed up") |> ignore

    | "signOut" => logger("user signed out") |> ignore

    | "signIn_failure" => logger("user sign in failed") |> ignore

    | "configured" => logger("the Auth module is configured") |> ignore
    | _ => logger("unknown error") |> ignore
    };
  };

Hub.listen("auth", listener);