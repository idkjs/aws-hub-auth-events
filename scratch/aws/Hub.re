type hub;
[@bs.module "@aws-amplify/core"] external hub: hub = "Hub";

// type logger;
// [@bs.module "@aws-amplify/core"] [@bs.new]
// external logger: (string, unit) => logger = "Logger";
// [@bs.send] external error: (string) =>logger = "error";

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
  event: string,
  data: Js.Nullable.t(Js.t({.})),
  [@bs.optional]
  message: string,
};

type payload = {
  event: string,
  data: Js.Nullable.t(Js.t({.})),
  message: option(string),
};

type cb = payload => unit;
// type cb('a) = unit => HubPayload.make('a);

type listen;
[@bs.send] external listen: (hub, string, cb) => unit = "listen";

let listen = (string, callback) => listen(hub, string, callback);