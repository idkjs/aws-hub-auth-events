// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Nav from "../components/Nav.bs.js";
import * as Auth from "../aws/Auth.bs.js";
import * as Form from "../components/Form.bs.js";
import * as React from "react";
import * as Public from "../components/Public.bs.js";
import * as Profile from "./Profile.bs.js.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";

console.log("currentUserPoolUser", Auth.currentUserPoolUser);

function str(prim) {
  return prim;
}

function Root(Props) {
  var url = ReasonReactRouter.useUrl(undefined, /* () */0);
  var match = url[/* path */0];
  var current;
  if (match) {
    switch (match[0]) {
      case "profile" :
          current = match[1] ? "public" : "profile";
          break;
      case "signin" :
          current = match[1] ? "public" : "signin";
          break;
      case "signup" :
          current = match[1] ? "public" : "signup";
          break;
      default:
        current = "public";
    }
  } else {
    current = "public";
  }
  var match$1 = url[/* path */0];
  var tmp;
  var exit = 0;
  if (match$1) {
    switch (match$1[0]) {
      case "profile" :
          if (match$1[1]) {
            exit = 1;
          } else {
            tmp = React.createElement(Profile.make, { });
          }
          break;
      case "signin" :
          if (match$1[1]) {
            exit = 1;
          } else {
            tmp = React.createElement(Form.make, {
                  formType: /* SignIn */0
                });
          }
          break;
      case "signup" :
          if (match$1[1]) {
            exit = 1;
          } else {
            tmp = React.createElement(Form.make, {
                  formType: /* SignUp */1
                });
          }
          break;
      default:
        exit = 1;
    }
  } else {
    exit = 1;
  }
  if (exit === 1) {
    tmp = React.createElement(Public.make, { });
  }
  return React.createElement(React.Fragment, undefined, React.createElement(Nav.make, {
                  current: current
                }), React.createElement("main", undefined, React.createElement("div", {
                      className: "task-container"
                    }, tmp)));
}

var make = Root;

var $$default = Root;

export {
  str ,
  make ,
  $$default ,
  $$default as default,

}
/*  Not a pure module */
