module Styles = {
  open Css;

  let container =
    style([
      display(`flex),
      flexDirection(column),
      marginTop(px(150)),
      justifyContent(center),
      alignItems(center),
    ]);

  let input =
    style([
      height(px(45)),
      marginTop(px(8)),
      width(px(300)),
      maxWidth(px(300)),
      paddingTop(px(0)),
      paddingBottom(px(8)),
      alignItems(center),
      fontSize(px(16)),
      outlineStyle(none),
      borderStyle(none),
      fontSize(px(16)),
      borderBottom(px(2), solid, rgba(0, 0, 0, 0.3)),
    ]);

  let toggleForm =
    style([
      fontWeight(`num(600)),
      marginTop(px(8)),
      paddingTop(px(0)),
      paddingBottom(px(25)),
      marginTop(px(15)),
      marginBottom(px(0)),
      textAlign(center),
      fontSize(px(16)),
      outlineStyle(none),
      borderStyle(none),
      fontSize(px(16)),
      color(rgba(0, 0, 0, 0.6)),
    ]);
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

  let resetPassword = style([marginTop(px(5))]);
  let anchor = style([color(`hex("#006bfc")), cursor(`pointer)]);
};