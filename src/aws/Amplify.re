module Config = {
  [@bs.module "../aws-exports"]
  external env: Js.Dict.t(Js.Json.t) = "default";
  let dictEntries = dict => {
    let keys = Js.Dict.keys(dict);
    let l = Js.Array.length(keys);
    let values = Obj.magic(Array.make(l, 0));
    for (i in 0 to l - 1) {
      let key = Array.unsafe_get(keys, i);
      values[i] = (key, Js.Dict.unsafeGet(dict, key));
    };
    values;
  };
  let values = dictEntries(env);
  let region = values[0][1];
  let identityPoolId = values[1][1];
  let userPoolId = values[3][1];
  let userPoolWebClientId = values[4][1];
  // Js.log2("values", values);
  // Js.log2("userPoolWebClientId", userPoolWebClientId);
  // Js.log2("identityPoolId", identityPoolId);
  // Js.log2("userPoolId", userPoolId);
  // Js.log2("region", region);

  type config; // create abstract button type

  [@bs.obj] // define a translator function for the button type
  external config:
    (
      ~identityPoolId: string=?,
      ~region: string=?,
      ~userPoolId: string=?,
      ~userPoolWebClientId: string=?,
      unit
    ) =>
    config =
    ""; // returns a button

  type t = {. "Auth": config};
  let config =
    config(~identityPoolId, ~region, ~userPoolId, ~userPoolWebClientId, ());
  let awsConfig: t = {"Auth": config};
};
// module Amplify = {
//   type t;
//   [@bs.module "aws-amplify"] external amplify: t = "default";
//   [@bs.send] external configure: (t, Js.t({..})) => unit = "configure";
//   let configure =(config:Config.t)=> configure(amplify, config);
// };
type t;
[@bs.module "aws-amplify"] external amplify: t = "default";
[@bs.send] external configure: (t, Config.t) => unit = "configure";
let configure = (config: Config.t) => configure(amplify, config);