module Styles = {
  open Css;

  let container =
    style([
      marginTop(px(0)),
      marginBottom(`auto),
      paddingTop(px(50)),
      paddingBottom(px(100)),
    ]);
};
[@react.component]
let make = (~children) => <div className=Styles.container> children </div>;
let default = make;