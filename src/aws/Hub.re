type hub;
[@bs.module "@aws-amplify/core"] external hub: hub = "Hub";
type logger;
[@bs.new] [@bs.module "@aws-amplify/core"] external logger: logger = "Logger";
[@bs.send] external info: unit => logger = "info";
[@bs.send] external error: unit => logger = "error";

// type logger;
// [@bs.module "@aws-amplify/core"] [@bs.new]
// external logger: (string, unit) => logger = "Logger";
// [@bs.send] external error: (string) =>logger = "error";
/*    | "signOut" => setUser(_ => None)

      | "signIn_failure" => logger("user sign in failed") |> ignore

      | "configured" */
type event = [ | `signIn | `signUp | `signOut | `signIn_failure | `configured];
type channel = [
  | `core
  | `auth
  | `api
  | `analytics
  | `interactions
  | `pubsub
  | `storage
  | `xr
];
module HubPayload = {
  [@bs.deriving abstract]
  type t('a) = {
    event: string,
    data: Js.Nullable.t('a),
    message: option(string),
  };
  let make = t;
};
[@bs.deriving abstract]
type payloadJs = {
  event,
  data: Js.Nullable.t(Js.t({.})),
  [@bs.optional]
  message: string,
};

// type payload('a) = {
//   event: string,
//   data: Js.Nullable.t(Js.t('a)),
//   message: option(string),
// };
type payload('a) = {
  event,
  data: option('a),
  message: option(string),
};

type cb = payload(Js.t({.})) => unit;

type listen;
[@bs.send] external listen: (hub, channel, cb) => unit = "listen";
type remove;
[@bs.send] external remove: (hub, channel, cb) => unit = "remove";

let listen = (string, callback) => listen(hub, string, callback);
let remove = (string, callback) => remove(hub, string, callback);