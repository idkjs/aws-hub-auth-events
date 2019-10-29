type t;
[@bs.module "aws-amplify"] external amplify: t = "default";

type config;
[@bs.module "../aws-exports.js"] external awsConfig: config = "default";
Js.log2("awsConfig",awsConfig );
[@bs.send] external configure: (t, config) => unit = "configure";
let configure =()=> configure(amplify, awsConfig);
