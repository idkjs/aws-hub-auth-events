// open AwsConfig;

Amplify.configure(Amplify.Config.awsConfig);
[@bs.module] external _css: Js.t({..}) as 'a = "./index.module.css";
[%bs.raw {|require('antd/dist/antd.css')|}];
[@bs.module "./serviceWorker"]
external register_service_worker: unit => unit = "register";
[@bs.module "./serviceWorker"]
external unregister_service_worker: unit => unit = "unregister";
ReactDOMRe.renderToElementWithId(<Router />, "root");