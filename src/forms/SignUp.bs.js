// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";
import * as FormStyle from "../pages/FormStyle.bs.js";
import * as FormTypes from "../hooks/FormTypes.bs.js";

function SignUp(Props) {
  var formType = Props.formType;
  var onClick = Props.onClick;
  var onChange = Props.onChange;
  return React.createElement("div", {
              className: FormStyle.Styles.container
            }, React.createElement("input", {
                  className: FormStyle.Styles.input,
                  name: "username",
                  placeholder: "Username",
                  type: "username",
                  onChange: onChange
                }), React.createElement("input", {
                  className: FormStyle.Styles.input,
                  name: "email",
                  placeholder: "Email",
                  type: "email",
                  onChange: onChange
                }), React.createElement("input", {
                  className: FormStyle.Styles.input,
                  name: "password",
                  placeholder: "Password",
                  type: "password",
                  onChange: onChange
                }), React.createElement("button", {
                  className: FormStyle.Styles.button,
                  onClick: onClick
                }, FormTypes.formTypeToString(formType)));
}

var make = SignUp;

export {
  make ,
  
}
/* react Not a pure module */
