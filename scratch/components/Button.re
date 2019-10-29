module Styles = {
  open Css;
  let button =
    style([
      backgroundColor(`hex("#006bfc")),
      color(white),
      width(px(316)),
      height(px(45)),
      fontWeight(`num(600)),
      fontSize(px(14)),
      cursor(`pointer),
      borderStyle(`none),
      outlineStyle(`none),
      borderRadius(px(3)),
      marginTop(px(25)),
      boxShadow(
        Shadow.box(~x=px(0), ~y=px(1), ~blur=px(3), rgba(0, 0, 0, 0.3)),
      ),
    ]);
};
[@react.component]
let make = (~onClick, ~title) =>
  <button className=Styles.button type_="submit" onClick={_evt => onClick}>
    title->React.string
  </button>;
let default = make;